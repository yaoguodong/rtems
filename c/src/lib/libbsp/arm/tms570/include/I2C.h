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

#ifndef LIBBSP_ARM_tms570_I2C
#define LIBBSP_ARM_tms570_I2C

#include <bsp/utility.h>

typedef struct{
  uint32_t OAR;               /*I2C Own Address Manager*/
  uint32_t IMR;               /*I2C Interupt Mask Register*/
  uint32_t STR;               /*I2C Status Register*/
  uint32_t CKL;               /*I2C Clock Divider Low Register*/
  uint32_t CKH;               /*I2C Clock Control High Register*/
  uint32_t CNT;               /*I2C Data Count Register*/
  uint32_t DRR;               /*I2C Data Receive Register*/
  uint32_t SAR;               /*I2C Slave Address Register*/
  uint32_t DXR;               /*I2C Data Transmit Register*/
  uint32_t MDR;               /*I2C Mode Register*/
  uint32_t IVR;               /*I2C Interrupt Vector Register*/
  uint32_t EMDR;              /*I2C Extended Mode Register*/
  uint32_t PSC;               /*I2C Prescale Register*/
  uint32_t PID11;             /*I2C Peripheral ID Register 1*/
  uint32_t PID12;             /*I2C Peripheral ID Register 2*/
  uint32_t DMACR;             /*I2C DMA Control Register*/
  uint8_t reserved1 [8];
  uint32_t PFNC;              /*I2C Pin Function Register*/
  uint32_t DIR;               /*I2C Pin Direction Register*/
  uint32_t DIN;               /*I2C Data Input Register*/
  uint32_t DOUT;              /*I2C Data Output Register*/
  uint32_t SET;               /*I2C Data Set Register*/
  uint32_t CLR;               /*I2C Data Clear Register*/
  uint32_t PDR;               /*I2C Pin Open Drain Register*/
  uint32_t PDIS;              /*I2C Pull Disable Register*/
  uint32_t PSEL;              /*I2C Pull Select Register*/
  uint32_t pSRS;              /*I2C Pins Slew Rate Select Register*/
} tms570_i2c_t;


/*-----------------------TMS570_I2COAR-----------------------*/
/* field: OA - Own address */
#define TMS570_I2C_OAR_OA(val) BSP_FLD32(val,0, 9)
#define TMS570_I2C_OAR_OA_GET(reg) BSP_FLD32GET(reg,0, 9)
#define TMS570_I2C_OAR_OA_SET(reg,val) BSP_FLD32SET(reg, val,0, 9)


/*-----------------------TMS570_I2CIMR-----------------------*/
/* field: AASEN - Address As Slave Interrupt Enable */
#define TMS570_I2C_IMR_AASEN BSP_FLD32(6)

/* field: SCDEN - Stop Condition Interrupt Enable */
#define TMS570_I2C_IMR_SCDEN BSP_FLD32(5)

/* field: TXRDYEN - Transmit Data Ready Interrupt Enable */
#define TMS570_I2C_IMR_TXRDYEN BSP_FLD32(4)

/* field: RXRDYEN - Receive Data Ready Interrupt Enable */
#define TMS570_I2C_IMR_RXRDYEN BSP_FLD32(3)

/* field: ARDYEN - Register Access Ready Interrupt Enable */
#define TMS570_I2C_IMR_ARDYEN BSP_FLD32(2)

/* field: NACKEN - No Acknowledgement Interrupt Enable */
#define TMS570_I2C_IMR_NACKEN BSP_FLD32(1)

/* field: ALEN - Arbitration Lost Interrupt Enable */
#define TMS570_I2C_IMR_ALEN BSP_FLD32(0)


/*-----------------------TMS570_I2CSTR-----------------------*/
/* field: SDIR - Slave direction */
#define TMS570_I2C_STR_SDIR BSP_FLD32(14)

/* field: NACKSNT - No acknowledge sent */
#define TMS570_I2C_STR_NACKSNT BSP_FLD32(13)

/* field: BB - Bus busy */
#define TMS570_I2C_STR_BB BSP_FLD32(12)

/* field: RSFULL - Receiver shift full */
#define TMS570_I2C_STR_RSFULL BSP_FLD32(11)

/* field: XSMT - XSMT */
#define TMS570_I2C_STR_XSMT BSP_FLD32(10)

/* field: AAS - Address as slave */
#define TMS570_I2C_STR_AAS BSP_FLD32(9)

/* field: AD0 - Address zero status */
#define TMS570_I2C_STR_AD0 BSP_FLD32(8)

/* field: SCD - SCD */
#define TMS570_I2C_STR_SCD BSP_FLD32(5)

/* field: TXRDY - Transmit data ready interrupt flag */
#define TMS570_I2C_STR_TXRDY BSP_FLD32(4)

/* field: RXRDY - Receive data ready interrupt flag */
#define TMS570_I2C_STR_RXRDY BSP_FLD32(3)

/* field: ARDY - Register access ready interrupt flag */
#define TMS570_I2C_STR_ARDY BSP_FLD32(2)

/* field: NACK - No acknowledgement interrupt */
#define TMS570_I2C_STR_NACK BSP_FLD32(1)

/* field: AL - Arbitration lost interrupt flag */
#define TMS570_I2C_STR_AL BSP_FLD32(0)


/*-----------------------TMS570_I2CCKL-----------------------*/
/* field: CLKL - Low time clock division factor */
#define TMS570_I2C_CKL_CLKL(val) BSP_FLD32(val,0, 15)
#define TMS570_I2C_CKL_CLKL_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_I2C_CKL_CLKL_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*-----------------------TMS570_I2CCKH-----------------------*/
/* field: CLKH - High time clock division factor */
#define TMS570_I2C_CKH_CLKH(val) BSP_FLD32(val,0, 15)
#define TMS570_I2C_CKH_CLKH_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_I2C_CKH_CLKH_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*-----------------------TMS570_I2CCNT-----------------------*/
/* field: CNT - Data counter */
#define TMS570_I2C_CNT_CNT(val) BSP_FLD32(val,0, 15)
#define TMS570_I2C_CNT_CNT_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_I2C_CNT_CNT_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*-----------------------TMS570_I2CDRR-----------------------*/
/* field: DATARX - Receive data */
#define TMS570_I2C_DRR_DATARX(val) BSP_FLD32(val,0, 7)
#define TMS570_I2C_DRR_DATARX_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_I2C_DRR_DATARX_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*-----------------------TMS570_I2CSAR-----------------------*/
/* field: SA - 7- or 10-bit programmable slave address */
#define TMS570_I2C_SAR_SA(val) BSP_FLD32(val,0, 9)
#define TMS570_I2C_SAR_SA_GET(reg) BSP_FLD32GET(reg,0, 9)
#define TMS570_I2C_SAR_SA_SET(reg,val) BSP_FLD32SET(reg, val,0, 9)


/*-----------------------TMS570_I2CDXR-----------------------*/
/* field: DATATX - Transmit data */
#define TMS570_I2C_DXR_DATATX(val) BSP_FLD32(val,0, 7)
#define TMS570_I2C_DXR_DATATX_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_I2C_DXR_DATATX_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*-----------------------TMS570_I2CMDR-----------------------*/
/* field: NACKMOD - No-acknowledge (NACK) mode */
#define TMS570_I2C_MDR_NACKMOD BSP_FLD32(15)

/* field: FREE - Free running bit */
#define TMS570_I2C_MDR_FREE BSP_FLD32(14)

/* field: STT - Start condition */
#define TMS570_I2C_MDR_STT BSP_FLD32(13)

/* field: STP - Stop condition */
#define TMS570_I2C_MDR_STP BSP_FLD32(11)

/* field: MST - Master/slave mode bit */
#define TMS570_I2C_MDR_MST BSP_FLD32(10)

/* field: TRX - Transmit/receive bit */
#define TMS570_I2C_MDR_TRX BSP_FLD32(9)

/* field: XA - Expand address enable bit */
#define TMS570_I2C_MDR_XA BSP_FLD32(8)

/* field: RM - RM */
#define TMS570_I2C_MDR_RM BSP_FLD32(7)

/* field: DLB - Digital loop back enable bit */
#define TMS570_I2C_MDR_DLB BSP_FLD32(6)

/* field: nIRS - I2C reset enable bit */
#define TMS570_I2C_MDR_nIRS BSP_FLD32(5)

/* field: STB - Start byte mode enable bit (Master mode only) */
#define TMS570_I2C_MDR_STB BSP_FLD32(4)

/* field: FDF - Free data format enable bit */
#define TMS570_I2C_MDR_FDF BSP_FLD32(3)

/* field: BC - Bit count */
#define TMS570_I2C_MDR_BC(val) BSP_FLD32(val,0, 2)
#define TMS570_I2C_MDR_BC_GET(reg) BSP_FLD32GET(reg,0, 2)
#define TMS570_I2C_MDR_BC_SET(reg,val) BSP_FLD32SET(reg, val,0, 2)


/*-----------------------TMS570_I2CIVR-----------------------*/
/* field: TESTMD - Reserved for internal testing. */
#define TMS570_I2C_IVR_TESTMD(val) BSP_FLD32(val,8, 11)
#define TMS570_I2C_IVR_TESTMD_GET(reg) BSP_FLD32GET(reg,8, 11)
#define TMS570_I2C_IVR_TESTMD_SET(reg,val) BSP_FLD32SET(reg, val,8, 11)

/* field: INTCODE - Interrupt Code Bits */
#define TMS570_I2C_IVR_INTCODE(val) BSP_FLD32(val,0, 2)
#define TMS570_I2C_IVR_INTCODE_GET(reg) BSP_FLD32GET(reg,0, 2)
#define TMS570_I2C_IVR_INTCODE_SET(reg,val) BSP_FLD32SET(reg, val,0, 2)


/*-----------------------TMS570_I2CEMDR-----------------------*/
/* field: IGNACK - Ignore NACK mode */
#define TMS570_I2C_EMDR_IGNACK BSP_FLD32(1)

/* field: BCM - Backwards compatibility mode */
#define TMS570_I2C_EMDR_BCM BSP_FLD32(0)


/*-----------------------TMS570_I2CPSC-----------------------*/
/* field: PSC - Prescale */
#define TMS570_I2C_PSC_PSC(val) BSP_FLD32(val,0, 7)
#define TMS570_I2C_PSC_PSC_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_I2C_PSC_PSC_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*----------------------TMS570_I2CPID11----------------------*/
/* field: CLASS - Peripheral class */
#define TMS570_I2C_PID11_CLASS(val) BSP_FLD32(val,8, 15)
#define TMS570_I2C_PID11_CLASS_GET(reg) BSP_FLD32GET(reg,8, 15)
#define TMS570_I2C_PID11_CLASS_SET(reg,val) BSP_FLD32SET(reg, val,8, 15)

/* field: REVISION - Revision level of the I2C */
#define TMS570_I2C_PID11_REVISION(val) BSP_FLD32(val,0, 7)
#define TMS570_I2C_PID11_REVISION_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_I2C_PID11_REVISION_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*----------------------TMS570_I2CPID12----------------------*/
/* field: TYPE - Peripheral type */
#define TMS570_I2C_PID12_TYPE(val) BSP_FLD32(val,0, 7)
#define TMS570_I2C_PID12_TYPE_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_I2C_PID12_TYPE_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*----------------------TMS570_I2CDMACR----------------------*/
/* field: TXDMAEN - Transmitter DMA enable */
#define TMS570_I2C_DMACR_TXDMAEN BSP_FLD32(1)

/* field: RXDMAEN - Receive DMA enable */
#define TMS570_I2C_DMACR_RXDMAEN BSP_FLD32(0)


/*-----------------------TMS570_I2CPFNC-----------------------*/
/* field: PINFUNC - SDA and SCL Pin Function */
#define TMS570_I2C_PFNC_PINFUNC BSP_FLD32(0)


/*-----------------------TMS570_I2CDIR-----------------------*/
/* field: SDADIR - SDA direction */
#define TMS570_I2C_DIR_SDADIR BSP_FLD32(1)

/* field: SCLDIR - SCL direction */
#define TMS570_I2C_DIR_SCLDIR BSP_FLD32(0)


/*-----------------------TMS570_I2CDIN-----------------------*/
/* field: SDAIN - Serial data in */
#define TMS570_I2C_DIN_SDAIN BSP_FLD32(1)

/* field: SCLIN - Serial clock data in */
#define TMS570_I2C_DIN_SCLIN BSP_FLD32(0)


/*-----------------------TMS570_I2CDOUT-----------------------*/
/* field: SDAOUT - SDA Data Output */
#define TMS570_I2C_DOUT_SDAOUT BSP_FLD32(1)

/* field: SCLOUT - SCL Data Output */
#define TMS570_I2C_DOUT_SCLOUT BSP_FLD32(0)


/*-----------------------TMS570_I2CSET-----------------------*/
/* field: SDASET - Serial Data Set */
#define TMS570_I2C_SET_SDASET BSP_FLD32(1)

/* field: SCLSET - Serial Clock Set */
#define TMS570_I2C_SET_SCLSET BSP_FLD32(0)


/*-----------------------TMS570_I2CCLR-----------------------*/
/* field: SDACLR - Serial Data Clear */
#define TMS570_I2C_CLR_SDACLR BSP_FLD32(1)

/* field: SCLCLR - Serial Clock Clear */
#define TMS570_I2C_CLR_SCLCLR BSP_FLD32(0)


/*-----------------------TMS570_I2CPDR-----------------------*/
/* field: SDAPDR - SDA pin open drain enable */
#define TMS570_I2C_PDR_SDAPDR BSP_FLD32(1)

/* field: SCLPDR - SCL pin open drain enable */
#define TMS570_I2C_PDR_SCLPDR BSP_FLD32(0)


/*-----------------------TMS570_I2CPDIS-----------------------*/
/* field: SDAPDIS - SDA pull disable */
#define TMS570_I2C_PDIS_SDAPDIS BSP_FLD32(1)

/* field: SCLPDIS - SCL pull disable */
#define TMS570_I2C_PDIS_SCLPDIS BSP_FLD32(0)


/*-----------------------TMS570_I2CPSEL-----------------------*/
/* field: SDAPSEL - SDA pull select */
#define TMS570_I2C_PSEL_SDAPSEL BSP_FLD32(1)

/* field: SCLPSEL - SCL pull select */
#define TMS570_I2C_PSEL_SCLPSEL BSP_FLD32(0)


/*-----------------------TMS570_I2CpSRS-----------------------*/
/* field: SDASRS - SDA Slew Rate select */
#define TMS570_I2C_pSRS_SDASRS BSP_FLD32(1)

/* field: SCLSRS - SCL Slew Rate select */
#define TMS570_I2C_pSRS_SCLSRS BSP_FLD32(0)



#endif /* LIBBSP_ARM_tms570_I2C */
