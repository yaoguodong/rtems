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

#ifndef LIBBSP_ARM_tms570_POM
#define LIBBSP_ARM_tms570_POM

#include <bsp/utility.h>

typedef struct{
  uint32_t PROGSTART;         /*POM Program Region Start Address Register*/
  uint32_t OVLSTART;          /*POM Overlay Region Start Address Register*/
  uint32_t REGSIZE;           /*POM Region Size Register */
  uint32_t Reser;             /*Reserved*/
} tms570_pom_region_t;

typedef struct{
  uint32_t GLBCTRL;           /*POM Global Control Register*/
  uint32_t REV;               /*POM Revision ID*/
  uint32_t CLKCTRL;           /*POM Clock Gate Control Register*/
  uint32_t FLG;               /*POM Status Register*/
  uint8_t reserved1 [496];
  tms570_pom_region_t REG[32];/*Program Regions*/
  uint8_t reserved2 [3264];
  uint32_t ITCTRL;            /*POM Integration Control Register*/
  uint8_t reserved3 [156];
  uint32_t CLAIMSET;          /*POM Claim Set Register*/
  uint32_t CLAIMCLR;          /*POM Claim Clear Register*/
  uint8_t reserved4 [8];
  uint32_t LOCKACCESS;        /*POM Lock Access Register*/
  uint32_t LOCKSTATUS;        /*POM Lock Status Register*/
  uint32_t AUTHSTATUS;        /*POM Authentication Status Register*/
  uint8_t reserved5 [12];
  uint32_t DEVID;             /*POM Device ID Register*/
  uint32_t DEVTYPE;           /*POM Device Type Register*/
  uint32_t PERIPHERALID4;     /*POM Peripheral ID 4 Register*/
  uint32_t PERIPHERALID5;     /*POM Peripheral ID 5 Register*/
  uint32_t PERIPHERALID6;     /*POM Peripheral ID 6 Register*/
  uint32_t PERIPHERALID7;     /*POM Peripheral ID 7 Register*/
  uint32_t PERIPHERALID0;     /*POM Peripheral ID 0 Register*/
  uint32_t PERIPHERALID1;     /*POM Peripheral ID 1 Register*/
  uint32_t PERIPHERALID2;     /*POM Peripheral ID 2 Register*/
  uint32_t PERIPHERALID3;     /*POM Peripheral ID 3 Register*/
  uint32_t COMPONENTID0;      /*POM Component ID 0 Register*/
  uint32_t COMPONENTID1;      /*POM Component ID 1 Register*/
  uint32_t COMPONENTID2;      /*POM Component ID 2 Register*/
  uint32_t COMPONENTID3;      /*POM Component ID 3 Register*/
} tms570_pom_t;


/*--------------------TMS570_POMPROGSTART--------------------*/
/* field: STARTADDRESS - Defines the start address of the program memory region. */
#define TMS570_POM_PROGSTART_STARTADDRESS(val) BSP_FLD32(val,0, 22)
#define TMS570_POM_PROGSTART_STARTADDRESS_GET(reg) BSP_FLD32GET(reg,0, 22)
#define TMS570_POM_PROGSTART_STARTADDRESS_SET(reg,val) BSP_FLD32SET(reg, val,0, 22)


/*---------------------TMS570_POMOVLSTART---------------------*/
/* field: STARTADDRESS - Defines the start address of the overlay memory region. */
#define TMS570_POM_OVLSTART_STARTADDRESS(val) BSP_FLD32(val,0, 22)
#define TMS570_POM_OVLSTART_STARTADDRESS_GET(reg) BSP_FLD32GET(reg,0, 22)
#define TMS570_POM_OVLSTART_STARTADDRESS_SET(reg,val) BSP_FLD32SET(reg, val,0, 22)


/*---------------------TMS570_POMREGSIZE---------------------*/
/* field: SIZE - Region size */
#define TMS570_POM_REGSIZE_SIZE(val) BSP_FLD32(val,0, 3)
#define TMS570_POM_REGSIZE_SIZE_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_POM_REGSIZE_SIZE_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*---------------------TMS570_POMGLBCTRL---------------------*/
/* field: OTADDR - Overlay target Address. */
#define TMS570_POM_GLBCTRL_OTADDR(val) BSP_FLD32(val,23, 31)
#define TMS570_POM_GLBCTRL_OTADDR_GET(reg) BSP_FLD32GET(reg,23, 31)
#define TMS570_POM_GLBCTRL_OTADDR_SET(reg,val) BSP_FLD32SET(reg, val,23, 31)

/* field: ETO - Enable Timeout. Refer to Section 18.2.2 for more details on the timeout error. */
#define TMS570_POM_GLBCTRL_ETO(val) BSP_FLD32(val,8, 11)
#define TMS570_POM_GLBCTRL_ETO_GET(reg) BSP_FLD32GET(reg,8, 11)
#define TMS570_POM_GLBCTRL_ETO_SET(reg,val) BSP_FLD32SET(reg, val,8, 11)

/* field: ON_OFF - Turn functionality of POM on or off. */
#define TMS570_POM_GLBCTRL_ON_OFF(val) BSP_FLD32(val,0, 3)
#define TMS570_POM_GLBCTRL_ON_OFF_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_POM_GLBCTRL_ON_OFF_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*-----------------------TMS570_POMREV-----------------------*/
/* field: SCHEME - Used to distinguish between different ID schemes. */
#define TMS570_POM_REV_SCHEME(val) BSP_FLD32(val,30, 31)
#define TMS570_POM_REV_SCHEME_GET(reg) BSP_FLD32GET(reg,30, 31)
#define TMS570_POM_REV_SCHEME_SET(reg,val) BSP_FLD32SET(reg, val,30, 31)

/* field: FUNC - Indicates the SW compatible module family */
#define TMS570_POM_REV_FUNC(val) BSP_FLD32(val,16, 27)
#define TMS570_POM_REV_FUNC_GET(reg) BSP_FLD32GET(reg,16, 27)
#define TMS570_POM_REV_FUNC_SET(reg,val) BSP_FLD32SET(reg, val,16, 27)

/* field: RTL - RTL version number */
#define TMS570_POM_REV_RTL(val) BSP_FLD32(val,11, 15)
#define TMS570_POM_REV_RTL_GET(reg) BSP_FLD32GET(reg,11, 15)
#define TMS570_POM_REV_RTL_SET(reg,val) BSP_FLD32SET(reg, val,11, 15)

/* field: MAJOR - Major revision number */
#define TMS570_POM_REV_MAJOR(val) BSP_FLD32(val,8, 10)
#define TMS570_POM_REV_MAJOR_GET(reg) BSP_FLD32GET(reg,8, 10)
#define TMS570_POM_REV_MAJOR_SET(reg,val) BSP_FLD32SET(reg, val,8, 10)

/* field: CUSTOM - Indicates a device specific implementation */
#define TMS570_POM_REV_CUSTOM(val) BSP_FLD32(val,6, 7)
#define TMS570_POM_REV_CUSTOM_GET(reg) BSP_FLD32GET(reg,6, 7)
#define TMS570_POM_REV_CUSTOM_SET(reg,val) BSP_FLD32SET(reg, val,6, 7)

/* field: 5_0 - MINOR 8h Minor revision number */
#define TMS570_POM_REV_5_0(val) BSP_FLD32(val,0, 5)
#define TMS570_POM_REV_5_0_GET(reg) BSP_FLD32GET(reg,0, 5)
#define TMS570_POM_REV_5_0_SET(reg,val) BSP_FLD32SET(reg, val,0, 5)


/*---------------------TMS570_POMCLKCTRL---------------------*/
/* field: CLK_GATE_OFF - Do not modify this bit. Leave it in its reset state. */
#define TMS570_POM_CLKCTRL_CLK_GATE_OFF BSP_FLD32(0)


/*-----------------------TMS570_POMFLG-----------------------*/
/* field: TO - Timeout. */
#define TMS570_POM_FLG_TO BSP_FLD32(0)


/*----------------------TMS570_POMITCTRL----------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_ITCTRL_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_ITCTRL_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_ITCTRL_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*---------------------TMS570_POMCLAIMSET---------------------*/
/* field: SET1 - The module is claimed */
#define TMS570_POM_CLAIMSET_SET1 BSP_FLD32(1)

/* field: SET0 - The module is claimed */
#define TMS570_POM_CLAIMSET_SET0 BSP_FLD32(0)


/*---------------------TMS570_POMCLAIMCLR---------------------*/
/* field: CLR1 - The module is claimed */
#define TMS570_POM_CLAIMCLR_CLR1 BSP_FLD32(1)

/* field: CLR0 - The module is claimed */
#define TMS570_POM_CLAIMCLR_CLR0 BSP_FLD32(0)


/*--------------------TMS570_POMLOCKACCESS--------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_LOCKACCESS_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_LOCKACCESS_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_LOCKACCESS_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*--------------------TMS570_POMLOCKSTATUS--------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_LOCKSTATUS_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_LOCKSTATUS_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_LOCKSTATUS_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*--------------------TMS570_POMAUTHSTATUS--------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_AUTHSTATUS_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_AUTHSTATUS_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_AUTHSTATUS_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*----------------------TMS570_POMDEVID----------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_DEVID_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_DEVID_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_DEVID_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*---------------------TMS570_POMDEVTYPE---------------------*/
/* field: Sub_Type - Other */
#define TMS570_POM_DEVTYPE_Sub_Type(val) BSP_FLD32(val,4, 7)
#define TMS570_POM_DEVTYPE_Sub_Type_GET(reg) BSP_FLD32GET(reg,4, 7)
#define TMS570_POM_DEVTYPE_Sub_Type_SET(reg,val) BSP_FLD32SET(reg, val,4, 7)

/* field: Major_Type - Debug Control */
#define TMS570_POM_DEVTYPE_Major_Type(val) BSP_FLD32(val,0, 3)
#define TMS570_POM_DEVTYPE_Major_Type_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_POM_DEVTYPE_Major_Type_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*------------------TMS570_POMPERIPHERALID4------------------*/
/* field: 4KB_Count - Only 4KB implemented */
#define TMS570_POM_PERIPHERALID4_4KB_Count(val) BSP_FLD32(val,4, 7)
#define TMS570_POM_PERIPHERALID4_4KB_Count_GET(reg) BSP_FLD32GET(reg,4, 7)
#define TMS570_POM_PERIPHERALID4_4KB_Count_SET(reg,val) BSP_FLD32SET(reg, val,4, 7)

/* field: JEP_Continuation - JEP106 Code */
#define TMS570_POM_PERIPHERALID4_JEP_Continuation(val) BSP_FLD32(val,0, 3)
#define TMS570_POM_PERIPHERALID4_JEP_Continuation_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_POM_PERIPHERALID4_JEP_Continuation_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*------------------TMS570_POMPERIPHERALID5------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_PERIPHERALID5_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_PERIPHERALID5_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_PERIPHERALID5_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*------------------TMS570_POMPERIPHERALID6------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_PERIPHERALID6_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_PERIPHERALID6_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_PERIPHERALID6_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*------------------TMS570_POMPERIPHERALID7------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_PERIPHERALID7_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_PERIPHERALID7_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_PERIPHERALID7_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*------------------TMS570_POMPERIPHERALID0------------------*/
/* field: Part_Number - Reads 0, since POMREV defines the module */
#define TMS570_POM_PERIPHERALID0_Part_Number(val) BSP_FLD32(val,0, 7)
#define TMS570_POM_PERIPHERALID0_Part_Number_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_POM_PERIPHERALID0_Part_Number_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*------------------TMS570_POMPERIPHERALID1------------------*/
/* field: JEP106_Identity - Part of TI JEDEC number */
#define TMS570_POM_PERIPHERALID1_JEP106_Identity(val) BSP_FLD32(val,4, 7)
#define TMS570_POM_PERIPHERALID1_JEP106_Identity_GET(reg) BSP_FLD32GET(reg,4, 7)
#define TMS570_POM_PERIPHERALID1_JEP106_Identity_SET(reg,val) BSP_FLD32SET(reg, val,4, 7)

/* field: Part_Number - Reads 0, since POMREV defines the module */
#define TMS570_POM_PERIPHERALID1_Part_Number(val) BSP_FLD32(val,0, 3)
#define TMS570_POM_PERIPHERALID1_Part_Number_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_POM_PERIPHERALID1_Part_Number_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*------------------TMS570_POMPERIPHERALID2------------------*/
/* field: Revision - Reads 0, since POMREV defines the module */
#define TMS570_POM_PERIPHERALID2_Revision(val) BSP_FLD32(val,4, 7)
#define TMS570_POM_PERIPHERALID2_Revision_GET(reg) BSP_FLD32GET(reg,4, 7)
#define TMS570_POM_PERIPHERALID2_Revision_SET(reg,val) BSP_FLD32SET(reg, val,4, 7)

/* field: JEDEC - Indicates JEDEC assigned value */
#define TMS570_POM_PERIPHERALID2_JEDEC BSP_FLD32(3)

/* field: JEP106_Identity - JEDEC+JEP106 Identity Code (POMPERIPHERALID2)+JEP106 Identity Code */
#define TMS570_POM_PERIPHERALID2_JEP106_Identity(val) BSP_FLD32(val,0, 2)
#define TMS570_POM_PERIPHERALID2_JEP106_Identity_GET(reg) BSP_FLD32GET(reg,0, 2)
#define TMS570_POM_PERIPHERALID2_JEP106_Identity_SET(reg,val) BSP_FLD32SET(reg, val,0, 2)


/*------------------TMS570_POMPERIPHERALID3------------------*/
/* field: Reserved - Read returns 0. Writes have no effect. */
#define TMS570_POM_PERIPHERALID3_Reserved(val) BSP_FLD32(val,0, 31)
#define TMS570_POM_PERIPHERALID3_Reserved_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_POM_PERIPHERALID3_Reserved_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-------------------TMS570_POMCOMPONENTID0-------------------*/
/* field: Preamble - Preamble */
#define TMS570_POM_COMPONENTID0_Preamble(val) BSP_FLD32(val,0, 7)
#define TMS570_POM_COMPONENTID0_Preamble_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_POM_COMPONENTID0_Preamble_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*-------------------TMS570_POMCOMPONENTID1-------------------*/
/* field: Component_Class - CoreSight Component */
#define TMS570_POM_COMPONENTID1_Component_Class(val) BSP_FLD32(val,4, 7)
#define TMS570_POM_COMPONENTID1_Component_Class_GET(reg) BSP_FLD32GET(reg,4, 7)
#define TMS570_POM_COMPONENTID1_Component_Class_SET(reg,val) BSP_FLD32SET(reg, val,4, 7)

/* field: Preamble - Preamble */
#define TMS570_POM_COMPONENTID1_Preamble(val) BSP_FLD32(val,0, 3)
#define TMS570_POM_COMPONENTID1_Preamble_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_POM_COMPONENTID1_Preamble_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*-------------------TMS570_POMCOMPONENTID2-------------------*/
/* field: Preamble - Preamble */
#define TMS570_POM_COMPONENTID2_Preamble(val) BSP_FLD32(val,0, 7)
#define TMS570_POM_COMPONENTID2_Preamble_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_POM_COMPONENTID2_Preamble_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*-------------------TMS570_POMCOMPONENTID3-------------------*/
/* field: Preamble - Preamble */
#define TMS570_POM_COMPONENTID3_Preamble(val) BSP_FLD32(val,0, 7)
#define TMS570_POM_COMPONENTID3_Preamble_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_POM_COMPONENTID3_Preamble_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)



#endif /* LIBBSP_ARM_tms570_POM */
