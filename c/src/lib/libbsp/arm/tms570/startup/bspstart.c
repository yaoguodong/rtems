/**
 * @file
 *
 * @ingroup tms570
 *
 * @brief Startup code.
 */
/*
 * Copyright (c) 2014 Premysl Houdek <kom541000@gmail.com>
 *
 * Google Summer of Code 2014 at
 * Czech Technical University in Prague
 * Zikova 1903/4
 * 166 36 Praha 6
 * Czech Republic
 *
 * Based on LPC24xx and LPC1768 BSP
 * 
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */




#include <bsp.h>
#include <bsp/io.h>
#include <bsp/irq.h>
#include <bsp/dma.h>
#include <bsp/bootcard.h>
#include <bsp/timer.h>
#include <bsp/irq-generic.h>
#include <bsp/system-clocks.h>
#include <bsp/linker-symbols.h>
#include <bsp/common-types.h>
#include <bsp/uart-output-char.h>

#ifdef TMS570_HEAP_EXTEND
LINKER_SYMBOL( tms570_region_heap_0_begin );
LINKER_SYMBOL( tms570_region_heap_0_size );
LINKER_SYMBOL( tms570_region_heap_0_end );
LINKER_SYMBOL( tms570_region_heap_1_begin );
LINKER_SYMBOL( tms570_region_heap_1_size );
LINKER_SYMBOL( tms570_region_heap_1_end );
extern Heap_Control *RTEMS_Malloc_Heap;
#endif

void bsp_pretasking_hook( void )
{
#ifdef TMS570_HEAP_EXTEND
  _Heap_Extend( RTEMS_Malloc_Heap,
    tms570_region_heap_0_begin,
    (uintptr_t) tms570_region_heap_0_size,
    NULL );
  _Heap_Extend( RTEMS_Malloc_Heap,
    tms570_region_heap_1_begin,
    (uintptr_t) tms570_region_heap_1_size,
    NULL );
#endif
}

/**
 * @brief Console initialization
 */
static void initialize_console( void )
{
#ifdef TMS570_CONFIG_CONSOLE

  tms570_module_enable( TMS570_MODULE_UART_0, TMS570_MODULE_PCLK_DEFAULT );

  tms570_pin_select( TMS570_PIN_UART_0_TXD, TMS570_PIN_FUNCTION_01 );
  tms570_pin_select( TMS570_PIN_UART_0_RXD, TMS570_PIN_FUNCTION_01 );

  BSP_CONSOLE_UART_INIT( TMS570_PCLK / 16 / TMS570_UART_BAUD );
#endif
}

void bsp_start( void )
{
  /* Initialize console */
  initialize_console();

  /*Initialize timer*/
  tms570_timer_init( TMS570_TIMER_1 );
  tms570_timer_start( TMS570_TIMER_1 );

  /* Interrupts */
  bsp_interrupt_initialize();

  /* DMA */
  tms570_dma_initialize();
}
