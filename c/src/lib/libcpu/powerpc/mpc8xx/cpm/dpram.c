/*
 * dpram.c
 *
 * MPC8xx dual-port RAM allocation routines
 * 
 * Based on code (alloc860.c in eth_comm port) by
 * Jay Monkman (jmonkman@frasca.com),
 * which, in turn, is based on code by
 * W. Eric Norum (eric@skatter.usask.ca).
 *
 *
 * Modifications :
 * Copyright (c) 1999, National Research Council of Canada
 */

#include <rtems.h>
#include <rtems/error.h>

#include <mpc8xx.h>
#include <mpc8xx/cpm.h>

/*
 * Allocation order:
 *      - Dual-Port RAM section 0
 *      - Dual-Port RAM section 1
 *      - Dual-Port RAM section 2
 *      - Dual-Port RAM section 3
 *      - Dual-Port RAM section 4
 */
static struct {
  char	 	*base;
  size_t	 size;
  unsigned int   used;
} dpram_regions[] = {
  { (char *)&m8xx.dpram0[0],    sizeof m8xx.dpram0,     0 },
  { (char *)&m8xx.dpram1[0],    sizeof m8xx.dpram1,     0 },
  { (char *)&m8xx.dpram2[0],    sizeof m8xx.dpram2,     0 },
  { (char *)&m8xx.dpram3[0],    sizeof m8xx.dpram3,     0 },
  { (char *)&m8xx.dpram4[0],    sizeof m8xx.dpram4,     0 },
};

#define	NUM_DPRAM_REGIONS	(sizeof(dpram_regions) / sizeof(dpram_regions[0]))

void *
m8xx_dpram_allocate( unsigned int byte_count )
{
  unsigned int i;
  ISR_Level level;
  void *blockp = NULL;
  
  byte_count = (byte_count + 3) & ~0x3;
  
  /*
   * Running with interrupts disabled is usually considered bad
   * form, but this routine is probably being run as part of an
   * initialization sequence so the effect shouldn't be too severe.
   */
  _ISR_Disable (level);
  
  for ( i = 0; i < NUM_DPRAM_REGIONS; i++ ) {
    /*
     * Verify that the region is available for use.
     * This test is necessary because if extra microcode modules
     * are installed, some regions are locked and unavailable.
     * See MPC860 User's Manual Pages 19-9 to 19-11.
     */
    if (dpram_regions[i].used == 0) {
      volatile unsigned char *cp = dpram_regions[i].base;
      *cp = 0xAA;
      if (*cp != 0xAA)
        dpram_regions[i].used = dpram_regions[i].size;
      else {
        *cp = 0x55;
        if (*cp != 0x55)
          dpram_regions[i].used = dpram_regions[i].size;
      }
      *cp = 0x0;
    }
    if (dpram_regions[i].size - dpram_regions[i].used >= byte_count) {
      blockp = dpram_regions[i].base + dpram_regions[i].used;
      dpram_regions[i].used += byte_count;
      break;
    }
  }
  
  _ISR_Enable(level);
  
  if (blockp == NULL)
    rtems_panic("Can't allocate %d bytes of dual-port RAM.\n", byte_count);
  return blockp;
}
