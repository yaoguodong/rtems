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

#ifndef LIBBSP_ARM_tms570_NHET
#define LIBBSP_ARM_tms570_NHET

#include <bsp/utility.h>

typedef struct{
  uint32_t GCR;               /*Global Configuration Register*/
  uint32_t PFR;               /*Prescale Factor Register*/
  uint32_t ADDR;              /*NHET Current Address Register*/
  uint32_t OFF1;              /*Offset Index Priority Level 1 Register*/
  uint32_t OFF2;              /*Offset Index Priority Level 2 Register*/
  uint32_t INTENAS;           /*Interrupt Enable Set Register*/
  uint32_t INTENAC;           /*Interrupt Enable Clear Register*/
  uint32_t EXC1;              /*Exception Control Register 1*/
  uint32_t EXC2;              /*Exception Control Register 2*/
  uint32_t PRY;               /*Interrupt Priority Register*/
  uint32_t FLG;               /*Interrupt Flag Register*/
  uint32_t AND;               /*AND Share Control Register*/
  uint8_t reserved1 [4];
  uint32_t HRSH;              /*HR Share Control Register*/
  uint32_t XOR;               /*HR XOR-Share Control Register*/
  uint32_t REQENS;            /*Request Enable Set Register*/
  uint32_t REQENC;            /*Request Enable Clear Register*/
  uint32_t REQDS;             /*Request Destination Select Register*/
  uint8_t reserved2 [4];
  uint32_t DIR;               /*NHET Direction Register*/
  uint32_t DIN;               /*NHET Data Input Register*/
  uint32_t DOUT;              /*NHET Data Output Register*/
  uint32_t DSET;              /*NHET Data Set Register*/
  uint32_t DCLR;              /*NHET Data Clear Register*/
  uint32_t PDR;               /*NHET Open Drain Register*/
  uint32_t PULDIS;            /*NHET Pull Disable Register*/
  uint32_t PSL;               /*NHET Pull Select Register*/
  uint8_t reserved3 [8];
  uint32_t PCR;               /*Parity Control Register*/
  uint32_t PAR;               /*Parity Address Register*/
  uint32_t PPR;               /*Parity Pin Register*/
  uint32_t SFPRLD;            /*Suppression Filter Preload Register*/
  uint32_t SFENA;             /*Suppression Filter Enable Register*/
  uint8_t reserved4 [4];
  uint32_t LBPSEL;            /*Loop Back Pair Select Register*/
  uint32_t LBPDIR;            /*Loop Back Pair Direction Register*/
  uint32_t PINDIS;            /*NHET Pin Disable Register*/
} tms570_nhet_t;


/*-----------------------TMS570_NHETGCR-----------------------*/
/* field: HET_PIN_ENA - Enables the output buffers of the pin structures depending on the value of nDIS and DIR. */
#define TMS570_NHET_GCR_HET_PIN_ENA BSP_FLD32(24)

/* field: MP - Master Priority */
#define TMS570_NHET_GCR_MP(val) BSP_FLD32(val,21, 22)
#define TMS570_NHET_GCR_MP_GET(reg) BSP_FLD32GET(reg,21, 22)
#define TMS570_NHET_GCR_MP_SET(reg,val) BSP_FLD32SET(reg, val,21, 22)

/* field: PPF - Protect Program Fields */
#define TMS570_NHET_GCR_PPF BSP_FLD32(18)

/* field: IS - Ignore Suspend */
#define TMS570_NHET_GCR_IS BSP_FLD32(17)

/* field: CMS - Clk_master/slave */
#define TMS570_NHET_GCR_CMS BSP_FLD32(16)


/*-----------------------TMS570_NHETPFR-----------------------*/
/* field: LRPFC - oop Resolution Pre-scale Factor Code */
#define TMS570_NHET_PFR_LRPFC(val) BSP_FLD32(val,8, 10)
#define TMS570_NHET_PFR_LRPFC_GET(reg) BSP_FLD32GET(reg,8, 10)
#define TMS570_NHET_PFR_LRPFC_SET(reg,val) BSP_FLD32SET(reg, val,8, 10)

/* field: HRPFC - High Resolution Pre-scale Factor Code */
#define TMS570_NHET_PFR_HRPFC(val) BSP_FLD32(val,0, 5)
#define TMS570_NHET_PFR_HRPFC_GET(reg) BSP_FLD32GET(reg,0, 5)
#define TMS570_NHET_PFR_HRPFC_SET(reg,val) BSP_FLD32SET(reg, val,0, 5)


/*----------------------TMS570_NHETADDR----------------------*/
/* field: HETADDR - N2HET Current Address */
#define TMS570_NHET_ADDR_HETADDR(val) BSP_FLD32(val,0, 8)
#define TMS570_NHET_ADDR_HETADDR_GET(reg) BSP_FLD32GET(reg,0, 8)
#define TMS570_NHET_ADDR_HETADDR_SET(reg,val) BSP_FLD32SET(reg, val,0, 8)


/*----------------------TMS570_NHETOFF1----------------------*/
/* field: OFFSET1 - HETOFF1[5:0] indexes the currently pending high-priority interrupt. */
#define TMS570_NHET_OFF1_OFFSET1(val) BSP_FLD32(val,0, 5)
#define TMS570_NHET_OFF1_OFFSET1_GET(reg) BSP_FLD32GET(reg,0, 5)
#define TMS570_NHET_OFF1_OFFSET1_SET(reg,val) BSP_FLD32SET(reg, val,0, 5)


/*----------------------TMS570_NHETOFF2----------------------*/
/* field: OFFSET2 - HETOFF2[5:0] indexes the currently pending low-priority interrupt. */
#define TMS570_NHET_OFF2_OFFSET2(val) BSP_FLD32(val,0, 5)
#define TMS570_NHET_OFF2_OFFSET2_GET(reg) BSP_FLD32GET(reg,0, 5)
#define TMS570_NHET_OFF2_OFFSET2_SET(reg,val) BSP_FLD32SET(reg, val,0, 5)


/*---------------------TMS570_NHETINTENAS---------------------*/
/* field: HETINTENAS - Interrupt Enable Set bits. HETINTENAS is readable and writable in any operation mode. */
#define TMS570_NHET_INTENAS_HETINTENAS(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_INTENAS_HETINTENAS_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_INTENAS_HETINTENAS_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*---------------------TMS570_NHETINTENAC---------------------*/
/* field: HETINTENAC - Interrupt Enable Clear bits. HETINTENAC is readable and writable in any operation mode. */
#define TMS570_NHET_INTENAC_HETINTENAC(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_INTENAC_HETINTENAC_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_INTENAC_HETINTENAC_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*----------------------TMS570_NHETEXC1----------------------*/
/* field: APCNT_OVRFL_ENA - APCNT Overflow Enable */
#define TMS570_NHET_EXC1_APCNT_OVRFL_ENA BSP_FLD32(24)

/* field: APCNT_UNRFL_ENA - APCNT Underflow Enable */
#define TMS570_NHET_EXC1_APCNT_UNRFL_ENA BSP_FLD32(16)

/* field: PRGM_OVRFL_ENA - Program Overflow Enable */
#define TMS570_NHET_EXC1_PRGM_OVRFL_ENA BSP_FLD32(8)

/* field: APCNT_OVRFL_PRY - APCNT Overflow Exception Interrupt Priority */
#define TMS570_NHET_EXC1_APCNT_OVRFL_PRY BSP_FLD32(2)

/* field: APCNT_UNRFL_PRY - APCNT Underflow Exception Interrupt Priority */
#define TMS570_NHET_EXC1_APCNT_UNRFL_PRY BSP_FLD32(1)

/* field: PRGM_OVRFL_PRY - ProgramOverflow Exception Interrupt Priority */
#define TMS570_NHET_EXC1_PRGM_OVRFL_PRY BSP_FLD32(0)


/*----------------------TMS570_NHETEXC2----------------------*/
/* field: DEBUG_STATUS_FLAG - Debug Status Flag. */
#define TMS570_NHET_EXC2_DEBUG_STATUS_FLAG BSP_FLD32(8)

/* field: APCNT_OVRFL_FLAG - APCNT Overflow Flag */
#define TMS570_NHET_EXC2_APCNT_OVRFL_FLAG BSP_FLD32(2)

/* field: APCNT_UNDFL_FLAG - APCNT Underflow Flag */
#define TMS570_NHET_EXC2_APCNT_UNDFL_FLAG BSP_FLD32(1)

/* field: PRGM_OVERFL_FLAG - Program Overflow Flag */
#define TMS570_NHET_EXC2_PRGM_OVERFL_FLAG BSP_FLD32(0)


/*-----------------------TMS570_NHETPRY-----------------------*/
/* field: HETPRY - HET Interrupt Priority Level bits */
#define TMS570_NHET_PRY_HETPRY(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_PRY_HETPRY_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_PRY_HETPRY_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_NHETFLG-----------------------*/
/* field: HETFLAG - Interrupt Flag Register Bits */
#define TMS570_NHET_FLG_HETFLAG(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_FLG_HETFLAG_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_FLG_HETFLAG_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_NHETAND-----------------------*/
/* field: AND_SHARE - AND Share Enable */
#define TMS570_NHET_AND_AND_SHARE(val) BSP_FLD32(val,0, 15)
#define TMS570_NHET_AND_AND_SHARE_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_NHET_AND_AND_SHARE_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*----------------------TMS570_NHETHRSH----------------------*/
/* field: HR_SHARE - HR Share Bits */
#define TMS570_NHET_HRSH_HR_SHARE(val) BSP_FLD32(val,0, 15)
#define TMS570_NHET_HRSH_HR_SHARE_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_NHET_HRSH_HR_SHARE_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*-----------------------TMS570_NHETXOR-----------------------*/
/* field: XOR_SHARE - XOR Share Enable */
#define TMS570_NHET_XOR_XOR_SHARE(val) BSP_FLD32(val,0, 15)
#define TMS570_NHET_XOR_XOR_SHARE_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_NHET_XOR_XOR_SHARE_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*---------------------TMS570_NHETREQENS---------------------*/
/* field: REQ_ENA_n - Request Enable Bits */
#define TMS570_NHET_REQENS_REQ_ENA_n(val) BSP_FLD32(val,0, 7)
#define TMS570_NHET_REQENS_REQ_ENA_n_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_NHET_REQENS_REQ_ENA_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*---------------------TMS570_NHETREQENC---------------------*/
/* field: REQ_DIS_n - Request Disable Bits */
#define TMS570_NHET_REQENC_REQ_DIS_n(val) BSP_FLD32(val,0, 7)
#define TMS570_NHET_REQENC_REQ_DIS_n_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_NHET_REQENC_REQ_DIS_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*----------------------TMS570_NHETREQDS----------------------*/
/* field: TDBS_n - HTU, DMA or Both Select Bits */
#define TMS570_NHET_REQDS_TDBS_n(val) BSP_FLD32(val,16, 23)
#define TMS570_NHET_REQDS_TDBS_n_GET(reg) BSP_FLD32GET(reg,16, 23)
#define TMS570_NHET_REQDS_TDBS_n_SET(reg,val) BSP_FLD32SET(reg, val,16, 23)

/* field: TDS_n - HTU or DMA Select Bits */
#define TMS570_NHET_REQDS_TDS_n(val) BSP_FLD32(val,0, 7)
#define TMS570_NHET_REQDS_TDS_n_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_NHET_REQDS_TDS_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*-----------------------TMS570_NHETDIR-----------------------*/
/* field: HETDIR_n - Data direction of NHET pins */
#define TMS570_NHET_DIR_HETDIR_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_DIR_HETDIR_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_DIR_HETDIR_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_NHETDIN-----------------------*/
/* field: HETDIN_n - Data input. This bit displays the logic state of the pin. */
#define TMS570_NHET_DIN_HETDIN_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_DIN_HETDIN_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_DIN_HETDIN_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*----------------------TMS570_NHETDOUT----------------------*/
/* field: HETDOUT_n - Data out write. Writes to this bit will only take effect when the pin is configured as an output. */
#define TMS570_NHET_DOUT_HETDOUT_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_DOUT_HETDOUT_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_DOUT_HETDOUT_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*----------------------TMS570_NHETDSET----------------------*/
/* field: HETDSET_n - This register allows bits of HETDOUT to be set while avoiding the pitfalls of a readmodify- write */
#define TMS570_NHET_DSET_HETDSET_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_DSET_HETDSET_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_DSET_HETDSET_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*----------------------TMS570_NHETDCLR----------------------*/
/* field: HETDCLR_n - This register allows bits of HETDOUT to be cleared while avoiding the pitfalls of a read-modifywrite */
#define TMS570_NHET_DCLR_HETDCLR_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_DCLR_HETDCLR_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_DCLR_HETDCLR_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_NHETPDR-----------------------*/
/* field: HETPDR_n - Open drain control for HET[n] pins */
#define TMS570_NHET_PDR_HETPDR_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_PDR_HETPDR_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_PDR_HETPDR_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*---------------------TMS570_NHETPULDIS---------------------*/
/* field: HETPULDIS_n - Pull disable for N2HET pins */
#define TMS570_NHET_PULDIS_HETPULDIS_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_PULDIS_HETPULDIS_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_PULDIS_HETPULDIS_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_NHETPSL-----------------------*/
/* field: HETPSL_n - Pull select for NHET pins */
#define TMS570_NHET_PSL_HETPSL_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_PSL_HETPSL_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_PSL_HETPSL_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*-----------------------TMS570_NHETPCR-----------------------*/
/* field: TEST - Test Bit. */
#define TMS570_NHET_PCR_TEST BSP_FLD32(8)

/* field: PARITY_ENA - Enable/disable parity checking. */
#define TMS570_NHET_PCR_PARITY_ENA(val) BSP_FLD32(val,0, 3)
#define TMS570_NHET_PCR_PARITY_ENA_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_NHET_PCR_PARITY_ENA_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*-----------------------TMS570_NHETPAR-----------------------*/
/* field: PAOFF - Parity Error Address Offset. */
#define TMS570_NHET_PAR_PAOFF(val) BSP_FLD32(val,2, 12)
#define TMS570_NHET_PAR_PAOFF_GET(reg) BSP_FLD32GET(reg,2, 12)
#define TMS570_NHET_PAR_PAOFF_SET(reg,val) BSP_FLD32SET(reg, val,2, 12)


/*-----------------------TMS570_NHETPPR-----------------------*/
/* field: HETPPR_n - NHET Parity Pin Select Bits - Allows HET[n] pins to be configured to drive to a known state when */
#define TMS570_NHET_PPR_HETPPR_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_PPR_HETPPR_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_PPR_HETPPR_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*---------------------TMS570_NHETSFPRLD---------------------*/
/* field: CCDIV - Counter Clock Divider */
#define TMS570_NHET_SFPRLD_CCDIV(val) BSP_FLD32(val,16, 17)
#define TMS570_NHET_SFPRLD_CCDIV_GET(reg) BSP_FLD32GET(reg,16, 17)
#define TMS570_NHET_SFPRLD_CCDIV_SET(reg,val) BSP_FLD32SET(reg, val,16, 17)

/* field: CPRLD - Counter Preload Value */
#define TMS570_NHET_SFPRLD_CPRLD(val) BSP_FLD32(val,0, 9)
#define TMS570_NHET_SFPRLD_CPRLD_GET(reg) BSP_FLD32GET(reg,0, 9)
#define TMS570_NHET_SFPRLD_CPRLD_SET(reg,val) BSP_FLD32SET(reg, val,0, 9)


/*----------------------TMS570_NHETSFENA----------------------*/
/* field: HETSFENA_n - Suppression Filter Enable Bits */
#define TMS570_NHET_SFENA_HETSFENA_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_SFENA_HETSFENA_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_SFENA_HETSFENA_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)


/*---------------------TMS570_NHETLBPSEL---------------------*/
/* field: LBPTYPE - Loop Back Pair Type Select Bits */
#define TMS570_NHET_LBPSEL_LBPTYPE(val) BSP_FLD32(val,16, 31)
#define TMS570_NHET_LBPSEL_LBPTYPE_GET(reg) BSP_FLD32GET(reg,16, 31)
#define TMS570_NHET_LBPSEL_LBPTYPE_SET(reg,val) BSP_FLD32SET(reg, val,16, 31)

/* field: LBPSEL - Loop Back Pair Select Bits */
#define TMS570_NHET_LBPSEL_LBPSEL(val) BSP_FLD32(val,0, 15)
#define TMS570_NHET_LBPSEL_LBPSEL_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_NHET_LBPSEL_LBPSEL_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*---------------------TMS570_NHETLBPDIR---------------------*/
/* field: LBPTSTENA - Loopback Test Enable Key */
#define TMS570_NHET_LBPDIR_LBPTSTENA(val) BSP_FLD32(val,16, 19)
#define TMS570_NHET_LBPDIR_LBPTSTENA_GET(reg) BSP_FLD32GET(reg,16, 19)
#define TMS570_NHET_LBPDIR_LBPTSTENA_SET(reg,val) BSP_FLD32SET(reg, val,16, 19)

/* field: LBPDIR - Loop Back Pair Direction Bits */
#define TMS570_NHET_LBPDIR_LBPDIR(val) BSP_FLD32(val,0, 15)
#define TMS570_NHET_LBPDIR_LBPDIR_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_NHET_LBPDIR_LBPDIR_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*---------------------TMS570_NHETPINDIS---------------------*/
/* field: HETPINDIS_n - N2HET Pin Disable Bits */
#define TMS570_NHET_PINDIS_HETPINDIS_n(val) BSP_FLD32(val,0, 31)
#define TMS570_NHET_PINDIS_HETPINDIS_n_GET(reg) BSP_FLD32GET(reg,0, 31)
#define TMS570_NHET_PINDIS_HETPINDIS_n_SET(reg,val) BSP_FLD32SET(reg, val,0, 31)



#endif /* LIBBSP_ARM_tms570_NHET */
