/*

 * Copyright (c) 2014-2015, Premysl Houdek <kom541000@gmail.com>

 *

 * Czech Technical University in Prague

 * Zikova 1903/4

 * 166 36 Praha 6

 * Czech Republic

 *

 * All rights reserved.

 *

 * Redistribution and use in source and binary forms, with or without

 * modification, are permitted provided that the following conditions are met:

 *

 * 1. Redistributions of source code must retain the above copyright notice, this

 *    list of conditions and the following disclaimer.

 * 2. Redistributions in binary form must reproduce the above copyright notice,

 *    this list of conditions and the following disclaimer in the documentation

 *    and/or other materials provided with the distribution.

 *

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND

 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED

 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE

 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR

 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES

 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;

 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND

 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT

 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS

 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 *

 * The views and conclusions contained in the software and documentation are those

 * of the authors and should not be interpreted as representing official policies,

 * either expressed or implied, of the FreeBSD Project.

*/

#ifndef LIBBSP_ARM_tms570_HTU
#define LIBBSP_ARM_tms570_HTU

#include <bsp/utility.h>

typedef struct{
  uint32_t GC;                /*Global Control Register*/
  uint32_t CPENA;             /*Control Packet Enable Register*/
  uint32_t BUSY0;             /*Control Packet Busy Register 0*/
  uint32_t BUSY1;             /*Control Packet Busy Register 1*/
  uint32_t BUSY2;             /*Control Packet Busy Register 2*/
  uint32_t BUSY3;             /*Control Packet Busy Register 3*/
  uint32_t ACPE;              /*Active Control Packet and Error Register*/
  uint8_t reserved1 [4];
  uint32_t RLBECTRL;          /*Request Lost and Bus Error Control Register*/
  uint32_t BFINTS;            /*Buffer Full Interrupt Enable Set Register*/
  uint32_t BFINTC;            /*Buffer Full Interrupt Enable Clear Register*/
  uint8_t reserved2 [8];
  uint32_t INTOFF0;           /*Interrupt Offset Register 0*/
  uint32_t INTOFF1;           /*Interrupt Offset Register 1*/
  uint32_t BIM;               /*Buffer Initialization Mode Register*/
  uint32_t RLOSTFL;           /*Request Lost Flag Register*/
  uint32_t BFINTFL;           /*Buffer Full Interrupt Flag Register*/
  uint32_t BERINTFL;          /*BER Interrupt Flag Register*/
  uint32_t MP1S;              /*Memory Protection 1 Start Address Register*/
  uint32_t MP1E;              /*Memory Protection 1 End Address Register*/
  uint32_t DCTRL;             /*Debug Control Register*/
  uint32_t WPR;               /*Watch Point Register*/
  uint32_t WMR;               /*Watch Mask Register*/
  uint32_t ID;                /*Module Identification Register*/
  uint32_t PCR;               /*Parity Control Register*/
  uint32_t PAR;               /*Parity Address Register*/
  uint8_t reserved3 [4];
  uint32_t MPCS;              /*Memory Protection Control and Status Register*/
  uint32_t MP0S;              /*Memory Protection 0 Start Address Register*/
  uint32_t MP0E;              /*Memory Protection 0 End Address Register*/
} tms570_htu_t;


/*------------------------TMS570_HTUGC------------------------*/
/* field: VBUSHOLD - Hold the VBUS bus */
#define TMS570_HTU_GC_VBUSHOLD BSP_FLD32(24)

/* field: HTUEN - Transfer Unit Enable Bit */
#define TMS570_HTU_GC_HTUEN BSP_FLD32(16)

/* field: DEBM - Debug Mode */
#define TMS570_HTU_GC_DEBM BSP_FLD32(8)

/* field: HTURES - HTU Software Reset Request */
#define TMS570_HTU_GC_HTURES BSP_FLD32(0)


/*----------------------TMS570_HTUCPENA----------------------*/
/* field: CPENA - CP Enable Bits */
#define TMS570_HTU_CPENA_CPENA(val) BSP_FLD32(val,0, 15)
#define TMS570_HTU_CPENA_CPENA_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_HTU_CPENA_CPENA_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*----------------------TMS570_HTUBUSY0----------------------*/
/* field: BUSY0A - Busy Flag for CP A of DCP 0 */
#define TMS570_HTU_BUSY0_BUSY0A BSP_FLD32(24)

/* field: BUSY0B - Busy Flag for CP B of DCP 0 */
#define TMS570_HTU_BUSY0_BUSY0B BSP_FLD32(16)

/* field: BUSY1A - Busy Flag for CP A of DCP 1 */
#define TMS570_HTU_BUSY0_BUSY1A BSP_FLD32(8)

/* field: BUSY1B - Busy Flag for CP B of DCP 1 */
#define TMS570_HTU_BUSY0_BUSY1B BSP_FLD32(0)


/*----------------------TMS570_HTUBUSY1----------------------*/
/* field: BUSY2A - Busy Flag for CP A of DCP 2 */
#define TMS570_HTU_BUSY1_BUSY2A BSP_FLD32(24)

/* field: BUSY2B - Busy Flag for CP B of DCP 2 */
#define TMS570_HTU_BUSY1_BUSY2B BSP_FLD32(16)

/* field: BUSY3A - Busy Flag for CP A of DCP 3 */
#define TMS570_HTU_BUSY1_BUSY3A BSP_FLD32(8)

/* field: BUSY3B - Busy Flag for CP B of DCP 3 */
#define TMS570_HTU_BUSY1_BUSY3B BSP_FLD32(0)


/*----------------------TMS570_HTUBUSY2----------------------*/
/* field: BUSY4A - Busy Flag for CP A of DCP 4 */
#define TMS570_HTU_BUSY2_BUSY4A BSP_FLD32(24)

/* field: BUSY4B - Busy Flag for CP B of DCP 4 */
#define TMS570_HTU_BUSY2_BUSY4B BSP_FLD32(16)

/* field: BUSY5A - Busy Flag for CP A of DCP 5 */
#define TMS570_HTU_BUSY2_BUSY5A BSP_FLD32(8)

/* field: BUSY5B - Busy Flag for CP B of DCP 5 */
#define TMS570_HTU_BUSY2_BUSY5B BSP_FLD32(0)


/*----------------------TMS570_HTUBUSY3----------------------*/
/* field: BUSY6A - Busy Flag for CP A of DCP 6 */
#define TMS570_HTU_BUSY3_BUSY6A BSP_FLD32(24)

/* field: BUSY6B - Busy Flag for CP B of DCP 6 */
#define TMS570_HTU_BUSY3_BUSY6B BSP_FLD32(16)

/* field: BUSY7A - Busy Flag for CP A of DCP 7 */
#define TMS570_HTU_BUSY3_BUSY7A BSP_FLD32(8)

/* field: BUSY7B - Busy Flag for CP B of DCP 7 */
#define TMS570_HTU_BUSY3_BUSY7B BSP_FLD32(0)


/*-----------------------TMS570_HTUACPE-----------------------*/
/* field: ERRF - Error Flag */
#define TMS570_HTU_ACPE_ERRF BSP_FLD32(31)


/*---------------------TMS570_HTURLBECTRL---------------------*/
/* field: BERINTENA - Bus Error Interrupt Enable Bit */
#define TMS570_HTU_RLBECTRL_BERINTENA BSP_FLD32(16)

/* field: CORL - Continue On Request Lost Error */
#define TMS570_HTU_RLBECTRL_CORL BSP_FLD32(8)

/* field: RLINTENA - Request Lost Interrupt Enable Bit */
#define TMS570_HTU_RLBECTRL_RLINTENA BSP_FLD32(0)


/*----------------------TMS570_HTUBFINTS----------------------*/
/* field: BFINTENA - Bus Full Interrupt Enable Bits. */
#define TMS570_HTU_BFINTS_BFINTENA(val) BSP_FLD32(val,0, 15)
#define TMS570_HTU_BFINTS_BFINTENA_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_HTU_BFINTS_BFINTENA_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*----------------------TMS570_HTUBFINTC----------------------*/
/* field: BFINTDIS -  */
#define TMS570_HTU_BFINTC_BFINTDIS(val) BSP_FLD32(val,0, 15)
#define TMS570_HTU_BFINTC_BFINTDIS_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_HTU_BFINTC_BFINTDIS_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*---------------------TMS570_HTUINTOFF0---------------------*/
/* field: INTTYPE0 - Interrupt Type of Interrupt Line 0. */
#define TMS570_HTU_INTOFF0_INTTYPE0(val) BSP_FLD32(val,8, 10)
#define TMS570_HTU_INTOFF0_INTTYPE0_GET(reg) BSP_FLD32GET(reg,8, 10)
#define TMS570_HTU_INTOFF0_INTTYPE0_SET(reg,val) BSP_FLD32SET(reg, val,8, 10)

/* field: CPOFF0 - CP Offset. */
#define TMS570_HTU_INTOFF0_CPOFF0(val) BSP_FLD32(val,0, 4)
#define TMS570_HTU_INTOFF0_CPOFF0_GET(reg) BSP_FLD32GET(reg,0, 4)
#define TMS570_HTU_INTOFF0_CPOFF0_SET(reg,val) BSP_FLD32SET(reg, val,0, 4)


/*---------------------TMS570_HTUINTOFF1---------------------*/
/* field: INTTYPE1 - INTTYPE1 Interrupt Type of Interrupt Line 1. */
#define TMS570_HTU_INTOFF1_INTTYPE1(val) BSP_FLD32(val,8, 10)
#define TMS570_HTU_INTOFF1_INTTYPE1_GET(reg) BSP_FLD32GET(reg,8, 10)
#define TMS570_HTU_INTOFF1_INTTYPE1_SET(reg,val) BSP_FLD32SET(reg, val,8, 10)

/* field: CPOFF1 - CP Offset. */
#define TMS570_HTU_INTOFF1_CPOFF1(val) BSP_FLD32(val,0, 4)
#define TMS570_HTU_INTOFF1_CPOFF1_GET(reg) BSP_FLD32GET(reg,0, 4)
#define TMS570_HTU_INTOFF1_CPOFF1_SET(reg,val) BSP_FLD32SET(reg, val,0, 4)


/*-----------------------TMS570_HTUBIM-----------------------*/
/* field: BIM - Buffer Initialization Mode */
#define TMS570_HTU_BIM_BIM(val) BSP_FLD32(val,0, 7)
#define TMS570_HTU_BIM_BIM_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_HTU_BIM_BIM_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*---------------------TMS570_HTURLOSTFL---------------------*/
/* field: CPRLFL - CP Request Lost Flags */
#define TMS570_HTU_RLOSTFL_CPRLFL(val) BSP_FLD32(val,0, 15)
#define TMS570_HTU_RLOSTFL_CPRLFL_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_HTU_RLOSTFL_CPRLFL_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*---------------------TMS570_HTUBFINTFL---------------------*/
/* field: BFINTFL - Buffer Full Interrupt Flags */
#define TMS570_HTU_BFINTFL_BFINTFL(val) BSP_FLD32(val,0, 15)
#define TMS570_HTU_BFINTFL_BFINTFL_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_HTU_BFINTFL_BFINTFL_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*---------------------TMS570_HTUBERINTFL---------------------*/
/* field: BERINTFL - Bus Error Interrupt Flags */
#define TMS570_HTU_BERINTFL_BERINTFL(val) BSP_FLD32(val,0, 15)
#define TMS570_HTU_BERINTFL_BERINTFL_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_HTU_BERINTFL_BERINTFL_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*-----------------------TMS570_HTUMP1S-----------------------*/
/* field: STARTADDRESS1 - he start address defines at which main memory address the region begins. */
#define TMS570_HTU_MP1S_STARTADDRESS1(val) BSP_FLD32(val,0, 31)
#define TMS570_HTU_MP1S_STARTADDRESS1_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_HTU_MP1S_STARTADDRESS1_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_HTUMP1E-----------------------*/
/* field: ENDADDRESS1 - The end address defines at which address the region ends. */
#define TMS570_HTU_MP1E_ENDADDRESS1(val) BSP_FLD32(val,0, 31)
#define TMS570_HTU_MP1E_ENDADDRESS1_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_HTU_MP1E_ENDADDRESS1_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*----------------------TMS570_HTUDCTRL----------------------*/
/* field: CPNUM - CP Number. These bit fields indicate the CP which should cause the watch point to match. */
#define TMS570_HTU_DCTRL_CPNUM(val) BSP_FLD32(val,24, 27)
#define TMS570_HTU_DCTRL_CPNUM_GET(reg) BSP_FLD32GET(reg,24, 27)
#define TMS570_HTU_DCTRL_CPNUM_SET(reg,val) BSP_FLD32SET(reg, val,24, 27)

/* field: HTUDBGS - HTU Debug Status. */
#define TMS570_HTU_DCTRL_HTUDBGS BSP_FLD32(16)

/* field: DBREN - Debug Request Enable */
#define TMS570_HTU_DCTRL_DBREN BSP_FLD32(0)


/*-----------------------TMS570_HTUWPR-----------------------*/
/* field: WP - Watch Point Register */
#define TMS570_HTU_WPR_WP(val) BSP_FLD32(val,0, 31)
#define TMS570_HTU_WPR_WP_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_HTU_WPR_WP_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_HTUWMR-----------------------*/
/* field: WM - Watch Mask Register */
#define TMS570_HTU_WMR_WM(val) BSP_FLD32(val,0, 31)
#define TMS570_HTU_WMR_WM_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_HTU_WMR_WM_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*------------------------TMS570_HTUID------------------------*/
/* field: CLASS - Module Class */
#define TMS570_HTU_ID_CLASS(val) BSP_FLD32(val,16, 23)
#define TMS570_HTU_ID_CLASS_GET(reg) BSP_FLD32GET(reg,16, 23)
#define TMS570_HTU_ID_CLASS_SET(reg,val) BSP_FLD32SET(reg, val,16, 23)

/* field: TYPE - Subtype within a Class */
#define TMS570_HTU_ID_TYPE(val) BSP_FLD32(val,8, 15)
#define TMS570_HTU_ID_TYPE_GET(reg) BSP_FLD32GET(reg,8, 15)
#define TMS570_HTU_ID_TYPE_SET(reg,val) BSP_FLD32SET(reg, val,8, 15)

/* field: REV - Module Revision Number */
#define TMS570_HTU_ID_REV(val) BSP_FLD32(val,0, 7)
#define TMS570_HTU_ID_REV_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_HTU_ID_REV_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*-----------------------TMS570_HTUPCR-----------------------*/
/* field: COPE - Continue on Parity Error */
#define TMS570_HTU_PCR_COPE BSP_FLD32(16)

/* field: TEST - Test. */
#define TMS570_HTU_PCR_TEST BSP_FLD32(8)

/* field: PARITY_ENA - Enable/Disable Parity Checking. */
#define TMS570_HTU_PCR_PARITY_ENA(val) BSP_FLD32(val,0, 3)
#define TMS570_HTU_PCR_PARITY_ENA_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_HTU_PCR_PARITY_ENA_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*-----------------------TMS570_HTUPAR-----------------------*/
/* field: PEFT - Parity Error Fault Flag. */
#define TMS570_HTU_PAR_PEFT BSP_FLD32(16)

/* field: PAOFF - PAOFF */
#define TMS570_HTU_PAR_PAOFF(val) BSP_FLD32(val,0, 8)
#define TMS570_HTU_PAR_PAOFF_GET(reg) BSP_FLD32GET(reg,0, 8)
#define TMS570_HTU_PAR_PAOFF_SET(reg,val) BSP_FLD32SET(reg, val,0, 8)


/*-----------------------TMS570_HTUMPCS-----------------------*/
/* field: CPNUM0 - Control Packet Number for single memory protection region configuration. */
#define TMS570_HTU_MPCS_CPNUM0(val) BSP_FLD32(val,24, 27)
#define TMS570_HTU_MPCS_CPNUM0_GET(reg) BSP_FLD32GET(reg,24, 27)
#define TMS570_HTU_MPCS_CPNUM0_SET(reg,val) BSP_FLD32SET(reg, val,24, 27)

/* field: MPEFT1 - MPEFT1 */
#define TMS570_HTU_MPCS_MPEFT1 BSP_FLD32(17)

/* field: MPEFT0 - Memory Protection Error Fault Flag 0. */
#define TMS570_HTU_MPCS_MPEFT0 BSP_FLD32(16)

/* field: CPNUM1 - Control Packet Number for single memory protection region configuration. */
#define TMS570_HTU_MPCS_CPNUM1(val) BSP_FLD32(val,8, 11)
#define TMS570_HTU_MPCS_CPNUM1_GET(reg) BSP_FLD32GET(reg,8, 11)
#define TMS570_HTU_MPCS_CPNUM1_SET(reg,val) BSP_FLD32SET(reg, val,8, 11)


/*-----------------------TMS570_HTUMP0S-----------------------*/
/* field: ISTARTADDRESS0 - The start address defines at which main memory address the region begins. */
#define TMS570_HTU_MP0S_ISTARTADDRESS0(val) BSP_FLD32(val,0, 31)
#define TMS570_HTU_MP0S_ISTARTADDRESS0_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_HTU_MP0S_ISTARTADDRESS0_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_HTUMP0E-----------------------*/
/* field: ENDADDRESS0 - The end address defines at which address the region ends. */
#define TMS570_HTU_MP0E_ENDADDRESS0(val) BSP_FLD32(val,0, 31)
#define TMS570_HTU_MP0E_ENDADDRESS0_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_HTU_MP0E_ENDADDRESS0_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)



#endif /* LIBBSP_ARM_tms570_HTU */
