/*****************************************************************************
 * arch/arm/src/cxd56xx/cxd56_audio_regdef.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 *****************************************************************************/

/* Multiple inclusion guard of header file is not needed for this file.
 * Do not add it.
 */

/* CXD56_AUREGDEF() and CXD56_AUINTREGDEF() are macros for defining instance
 * or symbol definitions. These macros are defined c file which is including
 * this file.
 */

/* CXD56_AUREGDEF(offset, bit-length, start-bit-pos, reg-name); **************/

/* Audio block Power Down Registers 0:En 1:Dis */

CXD56_AUREGDEF(0x100, 1, 23, PDN_DSPC);
CXD56_AUREGDEF(0x100, 1, 22, PDN_DSPS1);
CXD56_AUREGDEF(0x100, 1, 21, PDN_DSPS2);
CXD56_AUREGDEF(0x100, 1, 20, PDN_SMSTR);
CXD56_AUREGDEF(0x100, 1, 19, PDN_DNC2);
CXD56_AUREGDEF(0x100, 1, 18, PDN_DNC1);
CXD56_AUREGDEF(0x100, 1, 17, PDN_ANC);
CXD56_AUREGDEF(0x100, 1, 16, PDN_DSPB);
CXD56_AUREGDEF(0x100, 1, 15, PDN_DMIC);
CXD56_AUREGDEF(0x100, 1, 10, PDN_MIC);
CXD56_AUREGDEF(0x100, 1, 9,  PDN_LINEIN);
CXD56_AUREGDEF(0x100, 1, 8,  PDN_DAC);
CXD56_AUREGDEF(0x100, 1, 6,  PDN_AMIC2);
CXD56_AUREGDEF(0x100, 1, 5,  PDN_AMIC1);
CXD56_AUREGDEF(0x100, 1, 4,  PDN_AMICEXT);

/* Audio block Enable Registers 1:En 0:Dis */

CXD56_AUREGDEF(0x104, 1, 19, MCK_AHBMSTR_EN);
CXD56_AUREGDEF(0x104, 1, 18, SDES_EN);
CXD56_AUREGDEF(0x104, 1, 17, DECIM1_EN);
CXD56_AUREGDEF(0x104, 1, 16, DECIM0_EN);

/* De-serializer input FS register 0:128Fs(HiRes)  1:64Fs(LowRes) */

CXD56_AUREGDEF(0x104, 1, 0,  FS_FS);

/* Data path control registers ***********************************************/

/* CODEC MIC Input select 0:MIC01 1:MIC23 2:MIC45 4:MIC67 */

CXD56_AUREGDEF(0x108, 2, 28, COD_INSEL1);

/* CODEC Audio Input select 0:SRC1In 1:SRC2In 2:DMA1Down 3:DMA2Down */

CXD56_AUREGDEF(0x108, 2, 26, COD_INSEL2);
CXD56_AUREGDEF(0x108, 2, 24, COD_INSEL3);

/* DMA-Down signal select 0:MIC01 1:MIC23 2:MIC45 3:MIC67 4:DMA Out */

CXD56_AUREGDEF(0x108, 3, 20, AU_DAT_SEL1);
CXD56_AUREGDEF(0x108, 3, 16, AU_DAT_SEL2);

/* Hi Res mode select Register used in CODEC 0:LowRes 1:HiRes */

CXD56_AUREGDEF(0x200, 1, 31, HI_RES_MODE);

/* I2S Clock out Enable(in Master mode) 0:En 1:Dis */

CXD56_AUREGDEF(0x200, 1, 30, SDCK_OUTENX);

/* I2S Master/Slave select 0:Slave 1:Master */

CXD56_AUREGDEF(0x200, 1, 29, SD1MASTER);
CXD56_AUREGDEF(0x200, 1, 28, SD2MASTER);

/* I2S Data store format select 0:normal I2S fmt 1:Left */

CXD56_AUREGDEF(0x200, 1, 27, I2S0_FMT);
CXD56_AUREGDEF(0x200, 1, 26, I2S1_FMT);

/* BLF input signal select 0:DMA1DownBus 1:DMA2DownBus
 *                         2:CodecADCout 3:CodecMixOut
 */

CXD56_AUREGDEF(0x200, 2, 22, SRC2IN_SEL);
CXD56_AUREGDEF(0x200, 2, 18, SRC1IN_SEL);

/* Sampling Rate Converter input FS range select
 * 0:Through(no SRC)
 * 1:8K to 48K
 * 1:48K to 96K
 * 1:96K to 192K
 */

CXD56_AUREGDEF(0x200, 2, 20, SRC2);
CXD56_AUREGDEF(0x200, 2, 16, SRC1);

/* Soft RAMP Volume Control select 0:OFF 1:ON */

CXD56_AUREGDEF(0x200, 1, 12, DIGSFT);

/* Soft RAMP Volume control speed: 1(fastest) ~ 7(slowest) */

CXD56_AUREGDEF(0x200, 3, 0,  DSR_RATE);

/* CIC filter output swap select 0:Dis 1:En */

CXD56_AUREGDEF(0x204, 1, 31, INV_AMIC1R);
CXD56_AUREGDEF(0x204, 1, 30, INV_AMIC1L);

/* CIC Input signal FS select
 * 00:64fs(3MHz) 01:128fs(6MHz) 10:256fs(12MHz) 11:inhibit
 */

CXD56_AUREGDEF(0x204, 2, 28, ADC_FS);

/* CIC filter signal gain boost select 0:OFF 1:Boost(+20dB) */

CXD56_AUREGDEF(0x204, 1, 26, ADC1_BOOST);
CXD56_AUREGDEF(0x204, 1, 10, ADC2_BOOST);
CXD56_AUREGDEF(0x208, 1, 26, ADC3_BOOST);
CXD56_AUREGDEF(0x208, 1, 10, ADC4_BOOST);

/* CIC Input signal select 0:A-MIC(from CXD5247) 1:D-MIC on CXD5602 */

CXD56_AUREGDEF(0x204, 1, 25, CIC1IN_SEL);
CXD56_AUREGDEF(0x204, 1, 9, CIC2IN_SEL);
CXD56_AUREGDEF(0x208, 1, 25, CIC3IN_SEL);
CXD56_AUREGDEF(0x208, 1, 9, CIC4IN_SEL);

/* CIC Gain mode select 0:DNC mode 1:NormalMode */

CXD56_AUREGDEF(0x204, 1, 24, CIC1_GAIN_MODE);
CXD56_AUREGDEF(0x204, 1, 8, CIC2_GAIN_MODE);

/* CIC Input inverse signal value select 0:noInverse 1:Inverted */

CXD56_AUREGDEF(0x204, 1, 23, INV_DMIC1R);
CXD56_AUREGDEF(0x204, 1, 22, INV_DMIC1L);
CXD56_AUREGDEF(0x204, 1, 15, INV_AMIC2R);
CXD56_AUREGDEF(0x204, 1, 14, INV_AMIC2L);
CXD56_AUREGDEF(0x204, 1, 7, INV_DMIC2R);
CXD56_AUREGDEF(0x204, 1, 6, INV_DMIC2L);
CXD56_AUREGDEF(0x208, 1, 31, INV_AMIC3R);
CXD56_AUREGDEF(0x208, 1, 30, INV_AMIC3L);
CXD56_AUREGDEF(0x208, 1, 23, INV_DMIC3R);
CXD56_AUREGDEF(0x208, 1, 22, INV_DMIC3L);
CXD56_AUREGDEF(0x208, 1, 15, INV_AMIC4R);
CXD56_AUREGDEF(0x208, 1, 14, INV_AMIC4L);
CXD56_AUREGDEF(0x208, 1, 7, INV_DMIC4R);
CXD56_AUREGDEF(0x208, 1, 6, INV_DMIC4L);

/* CIC Input signal LR swap select 0:Normal 1:Swap */

CXD56_AUREGDEF(0x204, 1, 21, CIC1IN_SWAP);
CXD56_AUREGDEF(0x204, 1, 5, CIC2IN_SWAP);
CXD56_AUREGDEF(0x208, 1, 21, CIC3IN_SWAP);
CXD56_AUREGDEF(0x208, 1, 5, CIC4IN_SWAP);

/* CIC Hi-pass filter cut-off freq mode select
 * 0:OFF 1:Low 2:Mid 3:High
 */

CXD56_AUREGDEF(0x204, 2, 16, HPF1_MODE);
CXD56_AUREGDEF(0x204, 2, 0, HPF2_MODE);
CXD56_AUREGDEF(0x208, 2, 16, HPF3_MODE);
CXD56_AUREGDEF(0x208, 2, 0, HPF4_MODE);

/* CIC Filter Gain control 0x4000:Mute 0x4001~0x8000 */

CXD56_AUREGDEF(0x20c, 16, 16, CIC1_LGAIN);
CXD56_AUREGDEF(0x20c, 16, 0,  CIC1_RGAIN);
CXD56_AUREGDEF(0x210, 16, 16, CIC2_LGAIN);
CXD56_AUREGDEF(0x210, 16, 0,  CIC2_RGAIN);
CXD56_AUREGDEF(0x214, 16, 16, CIC3_LGAIN);
CXD56_AUREGDEF(0x214, 16, 0,  CIC3_RGAIN);
CXD56_AUREGDEF(0x218, 16, 16, CIC4_LGAIN);
CXD56_AUREGDEF(0x218, 16, 0,  CIC4_RGAIN);

/* Auto Level Control 0:OFF 1:ON */

CXD56_AUREGDEF(0x21c, 1, 31, ALC_EN);

/* ALC direction mode 0:Play(vol-up) 1:Rec(vol-down) */

CXD56_AUREGDEF(0x21c, 1, 30, ALC_REC);

CXD56_AUREGDEF(0x21c, 6, 24, ALCTARGET);
CXD56_AUREGDEF(0x21c, 7, 16, ALC_KNEE);

/* Sound Pressure Control 0: disable 1: enable */

CXD56_AUREGDEF(0x21c, 1, 15, SPC_EN);
CXD56_AUREGDEF(0x21c, 7, 8,  SPC_LIMIT);

/* ARC(Auto Range Control) operation mode (only LINEIN) */

CXD56_AUREGDEF(0x220, 3, 29, ARC);
CXD56_AUREGDEF(0x220, 4, 16, INV_DIGIPOL);
CXD56_AUREGDEF(0x224, 24, 8, ARC_VOL);

/* SPK out volume control
 * 0x18(24:+12dB) to 0x34(-204:-102dB), 0x33(-205) is Mute
 */

CXD56_AUREGDEF(0x228, 8, 24, SDIN1_VOL);
CXD56_AUREGDEF(0x228, 8, 16, SDIN2_VOL);
CXD56_AUREGDEF(0x228, 8, 8,  SDOUT_VOL);
CXD56_AUREGDEF(0x22c, 8, 16, LINEIN_VOL);
CXD56_AUREGDEF(0x22c, 8, 8, DAC_VOL);

CXD56_AUREGDEF(0x228, 1, 7,  CS_SIGN);   /* Always 0 */
CXD56_AUREGDEF(0x228, 7, 0,  CS_VOL);    /* Allways 7'b0 */

/* SPK Signal trans mode select
 * 0: Normal L/R trans mode 1: L+R/L-R trans mode
 */

CXD56_AUREGDEF(0x22c, 1, 6, TRANS_MODE);

/* BLF filter control  0:BLF disable 1:BLF enable */

CXD56_AUREGDEF(0x22c, 1, 5, BLF_EN);

/* Codec DSP output Mute control  0:NoMute 1:Mute */

CXD56_AUREGDEF(0x22c, 1, 4, MUTE_B);

/* BLF SDOUT control  0:OutputDis 1:OutputEn */

CXD56_AUREGDEF(0x22c, 1, 3, SDOUT2_EN);
CXD56_AUREGDEF(0x22c, 1, 2, SDOUT1_EN);

/* BLF SDIN control  0:InputDis(All0) 1:InputEn */

CXD56_AUREGDEF(0x22c, 1, 1, SDIN2_EN);
CXD56_AUREGDEF(0x22c, 1, 0, SDIN1_EN);

/* BEEP function 0:OFF 1:ON */

CXD56_AUREGDEF(0x230, 1, 31, BEEP_ON);

/* BEEP frequency control
 * Frequency = Fb x 8 / (2 x RegVal)
 * Fb = MCLK/512 or MCLK/1024
 */

CXD56_AUREGDEF(0x230, 6, 24, BEEP_FREQ);

/* BEEP Volume
 * 0x18(24:+12dB) to 0x34(-204:-102dB), 0x33(-205) is Mute
 */

CXD56_AUREGDEF(0x230, 5, 16, BEEP_VOL);

/* I2S BCK/LRCK error interrupt control 0:Dis 1:En */

CXD56_AUREGDEF(0x234, 1, 1, M_SPCLKERR2);
CXD56_AUREGDEF(0x234, 1, 0, M_SPCLKERR1);

/* Codec MIC input gain */

CXD56_AUREGDEF(0x234, 7, 24, ADC2R_VOL);
CXD56_AUREGDEF(0x234, 7, 16, ADC2L_VOL);
CXD56_AUREGDEF(0x234, 7, 8,  ADC1R_VOL);
CXD56_AUREGDEF(0x234, 7, 0,  ADC1L_VOL);

/* CODEC/DNC Start timing control */

CXD56_AUREGDEF(0x300, 8, 0,  SMS_INTIM);

/* DNC control */

CXD56_AUREGDEF(0x304, 1, 31, DNC1_START);
CXD56_AUREGDEF(0x304, 1, 30, DNC1_MUTE);
CXD56_AUREGDEF(0x304, 1, 23, DNC2_START);
CXD56_AUREGDEF(0x304, 1, 22, DNC2_MUTE);

/* CIC output signal FS
 * 1:4fs(192kHz) 2:8fs(384kHz) 3:16fs(768kHz)
 */

CXD56_AUREGDEF(0x308, 2, 30, DCMFS12);
CXD56_AUREGDEF(0x308, 2, 22, DCMFS34);

/* CODEC Output Mute control 0:NoMute 1:Mute */

CXD56_AUREGDEF(0x340, 1, 31, NSPMUTE);
CXD56_AUREGDEF(0x340, 1, 30, NSX2); /* Always 0 */

/* CODEC Output signal dither value */

CXD56_AUREGDEF(0x344, 20, 0, NSDD);

/* I2S Filter Bypass mode 0:Filter 1:Bypass */

CXD56_AUREGDEF(0x400, 1, 7,  I2S2_FILTBYPASS);
CXD56_AUREGDEF(0x400, 1, 6,  I2S1_FILTBYPASS);

/* Software Reset on CXD5602 Audio block */

CXD56_AUREGDEF(0x400, 1, 16, S_RST);

CXD56_AUREGDEF(0x400, 1, 19, HALT_INHIBIT);
CXD56_AUREGDEF(0x400, 1, 24, ARWPHSET);

/* Internal SRAM clear control 0:Not clear 1:clear */

CXD56_AUREGDEF(0x400, 1, 28, DSPRAM_CLR);
CXD56_AUREGDEF(0x400, 1, 30, DSPRAM2_CLR);
CXD56_AUREGDEF(0x400, 1, 31, DSPRAM1_CLR);

/* Serializer Clock output control 0:OFF(All0) 1:ON */

CXD56_AUREGDEF(0x500, 1, 24, FS_CLK_EN);

/* Serial signal(PDM_OUT) output control 0:Dis 1:En */

CXD56_AUREGDEF(0x500, 1, 16, PDM_OUT_EN);

/* PDM_IN Channel mode control 0:8Ch 1:4Ch */

CXD56_AUREGDEF(0x500, 1, 0, SER_MODE);

/* PDM_IN signal selector
 * 0 ~ 7 Channel is assigned, 8 Channel is not used
 */

CXD56_AUREGDEF(0x504, 3, 28, SEL_OUT1_L);
CXD56_AUREGDEF(0x504, 3, 24, SEL_OUT1_R);
CXD56_AUREGDEF(0x504, 3, 20, SEL_OUT2_L);
CXD56_AUREGDEF(0x504, 3, 16, SEL_OUT2_R);
CXD56_AUREGDEF(0x504, 3, 12, SEL_OUT3_L);
CXD56_AUREGDEF(0x504, 3, 8,  SEL_OUT3_R);
CXD56_AUREGDEF(0x504, 3, 4,  SEL_OUT4_L);
CXD56_AUREGDEF(0x504, 3, 0,  SEL_OUT4_R);

/* Decimation filter Control 0:Dis 1:En */

CXD56_AUREGDEF(0x580, 1, 24, SEL_DECIM);

/* Decimation filter input signal FS control
 * 0:4fs(192kHz) 1:8fs(384kHz)
 */

CXD56_AUREGDEF(0x580, 1, 20, SEL_INF);

/* Decimation filter output FS control
 * 0:1fs(48kHz) 1:2fs(96kHz) 2:4fs(192kHz) 3:8fs(384kH)
 */

CXD56_AUREGDEF(0x580, 2, 16, SEL_OUTF);

/* Decimation filter block output signal control  0:Dis 1:En */

CXD56_AUREGDEF(0x580, 1, 7, OUTEN_MIC2R_A);
CXD56_AUREGDEF(0x580, 1, 6, OUTEN_MIC2L_A);
CXD56_AUREGDEF(0x580, 1, 5, OUTEN_MIC1R_A);
CXD56_AUREGDEF(0x580, 1, 4, OUTEN_MIC1L_A);
CXD56_AUREGDEF(0x580, 1, 3, OUTEN_MIC2R_B);
CXD56_AUREGDEF(0x580, 1, 2, OUTEN_MIC2L_B);
CXD56_AUREGDEF(0x580, 1, 1, OUTEN_MIC1R_B);
CXD56_AUREGDEF(0x580, 1, 0, OUTEN_MIC1L_B);

/* Digial Equrizer control 0:Dis 1:En */

CXD56_AUREGDEF(0x600, 1, 31, DEQ_EN);

/* LR signal swap control 0:Dis 1:En */

CXD56_AUREGDEF(0x678, 1, 1, LR_SWAP2);
CXD56_AUREGDEF(0x678, 1, 0, LR_SWAP1);

/* DMA Control Registers *****************************************************/

/* DMA Address register */

CXD56_AUREGDEF(0x1000, 32, 0, MIC_DMA_ADR);
CXD56_AUREGDEF(0x1080, 32, 0,  I2S1IN_DMA_ADR);
CXD56_AUREGDEF(0x10a0, 32, 0,  I2S2IN_DMA_ADR);
CXD56_AUREGDEF(0x10c0, 32, 0,  I2S1OUT_DMA_ADR);
CXD56_AUREGDEF(0x10e0, 32, 0,  I2S2OUT_DMA_ADR);

/* DMA Smaple number.
 * It should be counted by each channel groups.
 * e.x. in case of 2ch and 4samples each(actual 8 sample data),
 *      4 should be set in this register.
 */

CXD56_AUREGDEF(0x1004, 32, 0, MIC_DMA_SAMPLES);
CXD56_AUREGDEF(0x1084, 32, 0,  I2S1IN_DMA_SAMPLES);
CXD56_AUREGDEF(0x10a4, 32, 0,  I2S2IN_DMA_SAMPLES);
CXD56_AUREGDEF(0x10c4, 32, 0,  I2S1OUT_DMA_SAMPLES);
CXD56_AUREGDEF(0x10e4, 32, 0,  I2S2OUT_DMA_SAMPLES);

/* DMA Command register
 * 1 : DMA Start, 4 : DMA Stop
 */

CXD56_AUREGDEF(0x1008, 3,  0, MIC_DMA_CMD);
CXD56_AUREGDEF(0x1088, 3,  0,  I2S1IN_DMA_CMD);
CXD56_AUREGDEF(0x10a8, 3,  0,  I2S2IN_DMA_CMD);
CXD56_AUREGDEF(0x10c8, 3,  0,  I2S1OUT_DMA_CMD);
CXD56_AUREGDEF(0x10e8, 3,  0,  I2S2OUT_DMA_CMD);

/* DMA Sample length select
 * 1: 16bits/sample  0: 24bits
 */

CXD56_AUREGDEF(0x100c, 1,  0, MIC_BITWT);
CXD56_AUREGDEF(0x108c, 1,  0,  I2S1IN_BITWT);
CXD56_AUREGDEF(0x10ac, 1,  0,  I2S2IN_BITWT);
CXD56_AUREGDEF(0x10cc, 1,  0,  I2S1OUT_BITWT);
CXD56_AUREGDEF(0x10ec, 1,  0,  I2S2OUT_BITWT);

/* Mic Channel select
 * in 24bits width, 0 to 7 is for mic ch0 to ch7.
 * in 16bits width, 0 to 3 is for mic Ch01 to Ch67.
 * 8 means Not used.
 */

CXD56_AUREGDEF(0x1010, 4,  28, MIC_CH1SEL);
CXD56_AUREGDEF(0x1010, 4,  24, MIC_CH2SEL);
CXD56_AUREGDEF(0x1010, 4,  20, MIC_CH3SEL);
CXD56_AUREGDEF(0x1010, 4,  16, MIC_CH4SEL);
CXD56_AUREGDEF(0x1010, 4,  12, MIC_CH5SEL);
CXD56_AUREGDEF(0x1010, 4,  8,  MIC_CH6SEL);
CXD56_AUREGDEF(0x1010, 4,  4,  MIC_CH7SEL);
CXD56_AUREGDEF(0x1010, 4,  0,  MIC_CH8SEL);

/* DMA Command buffer monitor
 * CXD5602 can sotre 3 commands in the HW.
 * This register shows empty number of the command buffer.
 */

CXD56_AUREGDEF(0x1014, 4,  16, MIC_DMA_CMDMON);
CXD56_AUREGDEF(0x1094, 4,  16, I2S1IN_DMA_CMDMON);
CXD56_AUREGDEF(0x10b4, 4,  16, I2S2IN_DMA_CMDMON);
CXD56_AUREGDEF(0x10d4, 4,  16, I2S1OUT_DMA_CMDMON);
CXD56_AUREGDEF(0x10f4, 4,  16, I2S2OUT_DMA_CMDMON);

/* DMA Error intication Register 0:No error Other:Any error. */

CXD56_AUREGDEF(0x1014, 8,  8,  MIC_DMA_SETUPERR);
CXD56_AUREGDEF(0x1094, 8,  8,  I2S1IN_DMA_SETUPERR);
CXD56_AUREGDEF(0x10b4, 8,  8,  I2S2IN_DMA_SETUPERR);
CXD56_AUREGDEF(0x10d4, 8,  8,  I2S1OUT_DMA_SETUPERR);
CXD56_AUREGDEF(0x10f4, 8,  8,  I2S2OUT_DMA_SETUPERR);

/* DMA Status 1:DMA runnning 0:DMA Stopped */

CXD56_AUREGDEF(0x1014, 1,  0,  MIC_DMA_STATUS);
CXD56_AUREGDEF(0x1094, 1,  0,  I2S1IN_DMA_STATUS);
CXD56_AUREGDEF(0x10b4, 1,  0,  I2S2IN_DMA_STATUS);
CXD56_AUREGDEF(0x10d4, 1,  0,  I2S1OUT_DMA_STATUS);
CXD56_AUREGDEF(0x10f4, 1,  0,  I2S2OUT_DMA_STATUS);

/* I2S Signal selector 0:Lch, 1:Rch */

CXD56_AUREGDEF(0x1090, 2,  4,  I2S1IN_CH1SEL);
CXD56_AUREGDEF(0x1090, 2,  0,  I2S1IN_CH2SEL);
CXD56_AUREGDEF(0x1090, 8,  0,  I2S1IN_CHSEL);
CXD56_AUREGDEF(0x10b0, 2,  4,  I2S2IN_CH1SEL);
CXD56_AUREGDEF(0x10b0, 2,  0,  I2S2IN_CH2SEL);
CXD56_AUREGDEF(0x10b0, 8,  0,  I2S2IN_CHSEL);
CXD56_AUREGDEF(0x10d0, 2,  4,  I2S1OUT_CH1SEL);
CXD56_AUREGDEF(0x10d0, 2,  0,  I2S1OUT_CH2SEL);
CXD56_AUREGDEF(0x10d0, 8,  0,  I2S1OUT_CHSEL);
CXD56_AUREGDEF(0x10f0, 2,  4,  I2S2OUT_CH1SEL);
CXD56_AUREGDEF(0x10f0, 2,  0,  I2S2OUT_CH2SEL);
CXD56_AUREGDEF(0x10f0, 8,  0,  I2S2OUT_CHSEL);

/* CXD5602 I2S and output audio signal FS setting.
 * 1:4Fs(192kHz)  0:1Fs(48kHz)
 */

CXD56_AUREGDEF(0x1110, 1,  0,  I2SALL_DATARATE);

/* MIC DMA interrupt status register (RW1Clr)
 * [0] Done  [1] Error  [2] SampleSendDone [3] Cmbined
 */

CXD56_AUREGDEF(0x1140, 4,  0,  MIC_INTR_STATUS);

/* I2S DMA interrupt status register (RW1Clr)
 * [0] OutDMA Done  [1] OutDMA Error  [2] InDMA Done [3] InDMA Error
 * [4] SampleSendDone [3] Cmbined
 */

CXD56_AUREGDEF(0x1144, 6,  0,  I2S1_INTR_STATUS);
CXD56_AUREGDEF(0x1148, 6,  0,  I2S2_INTR_STATUS);

/* Mic DMA Interrupt Mask register. Bit map is the same as Status */

CXD56_AUREGDEF(0x114c, 4,  0,  MIC_INTR_MASK);

/* I2S DMA Interrupt Mask register. Bit map is the same as Status */

CXD56_AUREGDEF(0x1150, 6,  0,  I2S1_INTR_MASK);
CXD56_AUREGDEF(0x1154, 6,  0,  I2S2_INTR_MASK);

CXD56_AUREGDEF(0x1158, 1, 0,  INTMASK_HRESPERR);
CXD56_AUREGDEF(0x1158, 1, 8,  INTMASK_I2S1BCKERR);
CXD56_AUREGDEF(0x1158, 1, 9,  INTMASK_I2S2BCKERR);

/* Interrupt Clear register. Write 1 clear */

CXD56_AUREGDEF(0x115c, 1, 0,  INTCLR_HRESPERR);
CXD56_AUREGDEF(0x115c, 1, 8,  INTCLR_I2S1BCKERR1);
CXD56_AUREGDEF(0x115c, 1, 9,  INTCLR_I2S1BCKERR2);

/* I2S slave related Interrupt status register. */

CXD56_AUREGDEF(0x1160, 1, 0,  INTSTAT_HRESPERR);
CXD56_AUREGDEF(0x1160, 1, 8,  INTSTAT_I2S1BCKERR1);
CXD56_AUREGDEF(0x1160, 1, 9,  INTSTAT_I2S1BCKERR2);

/* Other Unused interrupt mask register Always 1 (masked) */

CXD56_AUREGDEF(0x114c, 1, 30,  MIC_INTR_MASK2);
CXD56_AUREGDEF(0x1150, 1, 30,  I2S1_INTR_MASK2);
CXD56_AUREGDEF(0x1154, 1, 30,  I2S2_INTR_MASK2);

CXD56_AUREGDEF(0x1158, 1, 10, INTMASK_ANCFAINT);
CXD56_AUREGDEF(0x1158, 1, 17, INTMASK_SMASLOVF);
CXD56_AUREGDEF(0x1158, 1, 18, INTMASK_SMASROVF);
CXD56_AUREGDEF(0x1158, 1, 21, INTMASK_DNC1LOVF);
CXD56_AUREGDEF(0x1158, 1, 22, INTMASK_DNC1ROVF);
CXD56_AUREGDEF(0x1158, 1, 23, INTMASK_DNC2LOVF);
CXD56_AUREGDEF(0x1158, 1, 24, INTMASK_DNC2ROVF);

/* Unused interrupt related register Always 1 (masked) */

CXD56_AUREGDEF(0x115c, 1, 10, INTCLR_ANCFAINT);
CXD56_AUREGDEF(0x115c, 1, 17, INTCLR_SMASLOVF);
CXD56_AUREGDEF(0x115c, 1, 18, INTCLR_SMSTROVF);
CXD56_AUREGDEF(0x115c, 1, 21, INTCLR_DNC1LOVF);
CXD56_AUREGDEF(0x115c, 1, 22, INTCLR_DNC1ROVF);
CXD56_AUREGDEF(0x115c, 1, 23, INTCLR_DNC2LOVF);
CXD56_AUREGDEF(0x115c, 1, 24, INTCLR_DNC2ROVF);

CXD56_AUREGDEF(0x1160, 1, 10, INTSTAT_ANCFAINT);
CXD56_AUREGDEF(0x1160, 1, 17, INTSTAT_SMASLOVF);
CXD56_AUREGDEF(0x1160, 1, 18, INTSTAT_SMSTROVF);
CXD56_AUREGDEF(0x1160, 1, 21, INTSTAT_DNC1LOVF);
CXD56_AUREGDEF(0x1160, 1, 22, INTSTAT_DNC1ROVF);
CXD56_AUREGDEF(0x1160, 1, 23, INTSTAT_DNC2LOVF);
CXD56_AUREGDEF(0x1160, 1, 24, INTSTAT_DNC2ROVF);

/* AHB Master block Clock Enable 1:En 0:Dis */

CXD56_AUREGDEF(0x11f0, 1, 0,  AHBMIC_CLKEN);
CXD56_AUREGDEF(0x11f0, 1, 1,  AHBI2S1_CLKEN);
CXD56_AUREGDEF(0x11f0, 1, 2,  AHBI2S2_CLKEN);

CXD56_AUREGDEF(0x11fc, 8, 0,  MCLK_MONTHRESH);

/* CXD56_AUINTREGDEF(offset, bit-length, start-bit-pos, reg-name); **************/

/* System Interrupt Registers */

CXD56_AUINTREGDEF(0x30 + 3 * 4, 32, 0, INT_IRQ1);
CXD56_AUINTREGDEF(0x10 + 3 * 4, 32, 0, INT_EN1);
CXD56_AUINTREGDEF(0x10 + 3 * 4, 4,  6, INT_EN1_FLD);
