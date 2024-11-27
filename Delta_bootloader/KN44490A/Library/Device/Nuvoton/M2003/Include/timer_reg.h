/**************************************************************************//**
 * @file     timer_reg.h
 * @version  V1.00
 * @brief    TIMER register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __TIMER_REG_H__
#define __TIMER_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/**
    @addtogroup TIMER Timer Controller(TIMER)
    Memory Mapped Structure for TIMER Controller
@{ */

typedef struct
{


    /**
     * @var TIMER_T::CTL
     * Offset: 0x00  Timer0~3 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |PSC       |Prescale Counter
     * |        |          |Timer input clock or event source is divided by (PSC+1) before it is fed to the timer up counter
     * |        |          |If this field is 0 (PSC = 0), then there is no scaling.
     * |        |          |Note: Update prescale counter value will reset internal 8-bit prescale counter and 24-bit up counter value.
     * |[19]    |INTRGEN   |Inter-timer Trigger Mode Enable Bit
     * |        |          |Setting this bit will enable the inter-timer trigger capture function.
     * |        |          |The Timer0/2 will be in event counter mode and counting with external clock source or event
     * |        |          |Also, Timer1/3 will be in trigger-counting mode of capture function.
     * |        |          |0 = Inter-Timer Trigger Capture mode Disabled.
     * |        |          |1 = Inter-Timer Trigger Capture mode Enabled.
     * |        |          |Note: For Timer1/3, this bit is ineffective and the read back value is always 0.
     * |[20]    |PERIOSEL  |Periodic Mode Behavior Selection Enable Bit
     * |        |          |0 = The behavior selection in periodic mode is Disabled.
     * |        |          |When user updates CMPDAT while timer is running in periodic mode,
     * |        |          |CNT will be reset to default value.
     * |        |          |1 = The behavior selection in periodic mode is Enabled.
     * |        |          |When user updates CMPDAT while timer is running in periodic mode, the limitations as bellows list,
     * |        |          |If updated CMPDAT value > CNT, CMPDAT will be updated and CNT keep running continually.
     * |        |          |If updated CMPDAT value = CNT, timer time-out interrupt will be asserted immediately.
     * |        |          |If updated CMPDAT value < CNT, CNT will be reset to default value.
     * |[21]    |TGLPINSEL |Toggle-output Pin Select
     * |        |          |0 = Toggle mode output to TMx (Timer Event Counter Pin).
     * |        |          |1 = Toggle mode output to TMx_EXT (Timer External Capture Pin).
     * |[22]    |CAPSRC    |Capture Pin Source Selection
     * |        |          |0 = Capture Function source is from TMx_EXT (x= 0~3) pin.
     * |        |          |1 = Capture Function source is from internal clock (LIRC, HIRC).
     * |        |          |Note: When CAPSRC = 1,User can set INTERCAPSEL (TIMERx_EXTCTL[10:8]) to decide which clock is as timer capture source.
     * |[23]    |WKEN      |Wake-up Function Enable Bit
     * |        |          |If this bit is set to 1, while timer interrupt flag TIF (TIMERx_INTSTS[0]) is 1 and INTEN (TIMERx_CTL[29]) is enabled, the timer interrupt signal will generate a wake-up trigger event to CPU.
     * |        |          |0 = Wake-up function Disabled if timer interrupt signal generated.
     * |        |          |1 = Wake-up function Enabled if timer interrupt signal generated.
     * |[24]    |EXTCNTEN  |Event Counter Mode Enable Bit
     * |        |          |This bit is for external counting pin function enabled.
     * |        |          |0 = Event counter mode Disabled.
     * |        |          |1 = Event counter mode Enabled.
     * |        |          |Note: When timer is used as an event counter, this bit should be set to 1 and select PCLK as timer clock source.
     * |[25]    |ACTSTS    |Timer Active Status Bit (Read Only)
     * |        |          |This bit indicates the 24-bit up counter status.
     * |        |          |0 = 24-bit up counter is not active.
     * |        |          |1 = 24-bit up counter is active.
     * |        |          |Note: This bit may active when CNT 0 transition to CNT 1.
     * |[28:27] |OPMODE    |Timer Counting Mode Select
     * |        |          |00 = The timer controller is operated in One-shot mode.
     * |        |          |01 = The timer controller is operated in Periodic mode.
     * |        |          |10 = The timer controller is operated in Toggle-output mode.
     * |        |          |11 = The timer controller is operated in Continuous Counting mode.
     * |[29]    |INTEN     |Timer Interrupt Enable Bit
     * |        |          |0 = Timer time-out interrupt Disabled.
     * |        |          |1 = Timer time-out interrupt Enabled.
     * |        |          |Note: If this bit is enabled, when the timer time-out interrupt flag TIF is set to 1, the timer interrupt signal is generated and inform to CPU.
     * |[30]    |CNTEN     |Timer Counting Enable Bit
     * |        |          |0 = Stops/Suspends counting.
     * |        |          |1 = Starts counting.
     * |        |          |Note 1: In stop status, and then set CNTEN to 1 will enable the 24-bit up counter to keep counting from the last stop counting value.
     * |        |          |Note 2: This bit is auto-cleared by hardware in one-shot mode (TIMER_CTL[28:27] = 00) when the timer time-out interrupt flag TIF (TIMERx_INTSTS[0]) is generated.
     * |        |          |Note 3: Set enable/disable this bit needs 2 * TMR_CLK period to become active, user can read ACTSTS (TIMERx_CTL[25]) to check enable/disable command is completed or not.
     * |[31]    |ICEDEBUG  |ICE Debug Mode Acknowledge Disable Bit (Write Protect)
     * |        |          |0 = ICE debug mode acknowledgement effects TIMER counting.
     * |        |          |TIMER counter will be held while CPU is held by ICE.
     * |        |          |1 = ICE debug mode acknowledgement Disabled.
     * |        |          |TIMER counter will keep going no matter CPU is held by ICE or not.
     * |        |          |Note: This bit is write protected. Refer to the SYS_REGLCTL register.
     * @var TIMER_T::CMP
     * Offset: 0x04  Timer0~3 Comparator Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CMPDAT    |Timer Comparator Value
     * |        |          |CMPDAT is a 24-bit compared value register
     * |        |          |When the internal 24-bit up counter value is equal to CMPDAT value, the TIF (TIMERx_INTSTS[0] Timer Interrupt Flag) will set to 1.
     * |        |          |Time-out period = (Period of timer clock input) * (8-bit PSC + 1) * (24-bit CMPDAT).
     * |        |          |Note 1: Never write 0x0 or 0x1 in CMPDAT field, or the core will run into unknown state.
     * |        |          |Note 2: When timer is operating at continuous counting mode, the 24-bit up counter will keep counting continuously even if user writes a new value into CMPDAT field
     * |        |          |But if timer is operating at other modes, the 24-bit up counter will restart counting from 0 and using newest CMPDAT value to be the timer compared value while user writes a new value into CMPDAT field.
     * @var TIMER_T::INTSTS
     * Offset: 0x08  Timer0~3 Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |TIF       |Timer Interrupt Flag
     * |        |          |This bit indicates the interrupt flag status of Timer while 24-bit timer up counter CNT (TIMERx_CNT[23:0]) value reaches to CMPDAT (TIMERx_CMP[23:0]) value.
     * |        |          |0 = No effect.
     * |        |          |1 = CNT value matches the CMPDAT value.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[1]     |TWKF      |Timer Wake-up Flag
     * |        |          |This bit indicates the interrupt wake-up flag status of timer.
     * |        |          |0 = Timer does not cause CPU wake-up.
     * |        |          |1 = CPU wake-up from Idle or Power-down mode if timer time-out interrupt signal generated.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * @var TIMER_T::CNT
     * Offset: 0x0C  Timer0~3 Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CNT       |Timer Data Register
     * |        |          |Read operation.
     * |        |          |Read this register to get CNT value. For example:
     * |        |          |If EXTCNTEN (TIMERx_CTL[24]) is 0, user can read CNT value for getting current 24-bit counter value.
     * |        |          |If EXTCNTEN (TIMERx_CTL[24]) is 1, user can read CNT value for getting current 24-bit event input counter value.
     * |        |          |Write operation.
     * |        |          |Writing any value to this register will reset current CNT value to 0 and reload internal 8-bit prescale counter.
     * |[31]    |RSTACT    |Timer Data Register Reset Active (Read Only)
     * |        |          |This bit indicates if the counter reset operation active.
     * |        |          |When user writes this CNT register, timer starts to reset its internal 24-bit timer up-counter to 0 and reload 8-bit pre-scale counter
     * |        |          |At the same time, timer set this flag to 1 to indicate the counter reset operation is in progress
     * |        |          |Once the counter reset operation done, timer clear this bit to 0 automatically.
     * |        |          |0 = Reset operation is done.
     * |        |          |1 = Reset operation triggered by writing TIMERx_CNT is in progress.
     * @var TIMER_T::CAP
     * Offset: 0x10  Timer0~3 Capture Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CAPDAT    |Timer Capture Data Register
     * |        |          |When CAPEN (TIMERx_EXTCTL[3]) bit is set, CAPFUNCS (TIMERx_EXTCTL[4]) bit is 0, and a transition on TMx_EXT pin matched the CAPEDGE (TIMERx_EXTCTL[14:12]) setting, CAPIF (TIMERx_EINTSTS[0]) will set to 1 and the current timer counter value CNT (TIMERx_CNT[23:0]) will be auto-loaded into this CAPDAT field.
     * @var TIMER_T::EXTCTL
     * Offset: 0x14  Timer0~3 External Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTPHASE  |Timer External Count Phase
     * |        |          |This bit indicates the detection phase of external counting pin TMx (x= 0~3).
     * |        |          |0 = A falling edge of external counting pin will be counted.
     * |        |          |1 = A rising edge of external counting pin will be counted.
     * |[3]     |CAPEN     |Timer Capture Enable Bit
     * |        |          |This bit enables the capture input function.
     * |        |          |0 = Capture source Disabled.
     * |        |          |1 = Capture source Enabled.
     * |[4]     |CAPFUNCS  |Capture Function Selection
     * |        |          |0 = External Capture Mode Enabled.
     * |        |          |1 = External Reset Mode Enabled.
     * |        |          |Note 1: When CAPFUNCS is 0, transition on TMx_EXT (x= 0~3) pin is using to save current 24-bit timer counter value (CNT value) to CAPDAT field.
     * |        |          |Note 2: When CAPFUNCS is 1, transition on TMx_EXT (x= 0~3) pin is using to save current 24-bit timer counter value (CNT value) to CAPDAT field then CNT value will be reset immediately.
     * |[5]     |CAPIEN    |Timer External Capture Interrupt Enable Bit
     * |        |          |0 = TMx_EXT (x= 0~3) pin, internal clock, or external clock detection Interrupt Disabled.
     * |        |          |1 = TMx_EXT (x= 0~3) pin, internal clock, or external clock detection Interrupt Enabled.
     * |        |          |Note: CAPIEN is used to enable timer external interrupt
     * |        |          |If CAPIEN enabled, timer will rise an interrupt when CAPIF (TIMERx_EINTSTS[0]) is 1.
     * |        |          |For example, while CAPIEN = 1, CAPEN = 1, and CAPEDGE = 00, a 1 to 0 transition on the TMx_EXT (x= 0~3) pin, internal clock, or external clock will cause the CAPIF to be set then the interrupt signal is generated and sent to NVIC to inform CPU.
     * |[6]     |CAPDBEN   |Timer External Capture Pin De-bounce Enable Bit
     * |        |          |0 = TMx_EXT (x= 0~3) pin de-bounce Disabled.
     * |        |          |1 = TMx_EXT (x= 0~3) pin de-bounce Enabled.
     * |        |          |Note: If this bit is enabled, the edge detection of TMx_EXT pin is detected with de-bounce circuit.
     * |[7]     |CNTDBEN   |Timer Counter Pin De-bounce Enable Bit
     * |        |          |0 = TMx (x= 0~3) pin de-bounce Disabled.
     * |        |          |1 = TMx (x= 0~3) pin de-bounce Enabled.
     * |        |          |Note: If this bit is enabled, the edge detection of TMx pin is detected with de-bounce circuit.
     * |[10:8]  |INTERCAPSEL|Internal Capture Source Select
     * |        |          |100 = Capture Function source is from HIRC.
     * |        |          |101 = Capture Function source is from LIRC.
     * |        |          |111 = Reserved.
     * |        |          |Note: these bits only available when CAPSRC (TIMERx_CTL[22]) is 1.
     * |[14:12] |CAPEDGE   |Timer External Capture Pin Edge Detect
     * |        |          |When first capture event is generated, the CNT (TIMERx_CNT[23:0]) will be reset to 0 and first CAPDAT (TIMERx_CAP[23:0]) should be to 0.
     * |        |          |000 = Capture event occurred when detect falling edge transfer on TMx_EXT (x= 0~3) pin.
     * |        |          |001 = Capture event occurred when detect rising edge transfer on TMx_EXT (x= 0~3) pin.
     * |        |          |010 = Capture event occurred when detect both falling and rising edge transfer on TMx_EXT (x= 0~3) pin, and first capture event occurred at falling edge transfer.
     * |        |          |011 = Capture event occurred when detect both rising and falling edge transfer on TMx_EXT (x= 0~3) pin, and first capture event occurred at rising edge transfer.
     * |        |          |110 = First capture event occurred at falling edge, follows capture events are at rising edge transfer on TMx_EXT (x= 0~3) pin.
     * |        |          |111 = First capture event occurred at rising edge, follows capture events are at falling edge transfer on TMx_EXT (x= 0~3) pin.
     * |        |          |100, 101 = Reserved.
     * |        |          |Note: Set CAPSRC (TIMERx_CTL[22]) and INTERCAPSEL (TIMERx_EXTCTL[10:8]) to select capture source.
     * |[18:16] |ECNTSSEL  |Event Counter Source Selection to Trigger Event Counter Function
     * |        |          |000 = Event Counter input source is from external TMx (x= 0~3) pin.
     * |        |          |101~111 = Reserved
     * |[21:20] |CAPLSEL   |Capture Trigger Length Selection
     * |        |          |00 = TMx_EXT (x= 0,2) pin input capture length 1 selection.
     * |        |          |01 = TMx_EXT (x= 0,2) pin input capture length 2 selection.
     * |        |          |10 = TMx_EXT (x= 0,2) pin input capture length 3 selection.
     * |        |          |11 = TMx_EXT (x= 0,2) pin input capture length 4 selection.
     * |[31:28] |CAPDIVSCL |Timer Capture Source Divider Scale
     * |        |          |This bits indicate the divide scale for capture source divider
     * |        |          |0000 = Capture source/1.
     * |        |          |0001 = Capture source/2.
     * |        |          |0010 = Capture source/4.
     * |        |          |0011 = Capture source/8.
     * |        |          |0100 = Capture source/16.
     * |        |          |0101 = Capture source/32.
     * |        |          |0110 = Capture source/64.
     * |        |          |0111 = Capture source/128.
     * |        |          |1000 = Capture source/256.
     * |        |          |1001~1111 = Reserved.
     * |        |          |Note: Set INTERCAPSEL (TIMERx_EXTCTL[10:8]) and CAPSRC (TIMERx_CTL[22]) to select capture source.
     * @var TIMER_T::EINTSTS
     * Offset: 0x18  Timer0~3 External Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CAPIF     |Timer External Capture Interrupt Flag
     * |        |          |This bit indicates the timer external capture interrupt flag status.
     * |        |          |0 = TMx_EXT (x= 0~3) pin, internal clock, or external clock interrupt did not occur.
     * |        |          |1 = TMx_EXT (x= 0~3) pin, internal clock, or external clock interrupt occurred.
     * |        |          |Note 1: This bit is cleared by writing 1 to it.
     * |        |          |Note 2: When CAPEN (TIMERx_EXTCTL[3]) bit is set, CAPFUNCS (TIMERx_EXTCTL[4]) bit is 0, and a transition on TMx_EXT (x= 0~3) pin, internal clock, or external clock matched the CAPEDGE (TIMERx_EXTCTL[2:1]) setting, this bit will set to 1 by hardware.
     * |        |          |Note 3: There is a new incoming capture event detected before CPU clearing the CAPIF status
     * |        |          |If the above condition occurred, the Timer will keep register TIMERx_CAP unchanged and drop the new capture value.
     * |[1]     |CAPIFOV   |Capture Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |0 = Capture latch happened when the corresponding CAPIF is 0.
     * |        |          |1 = Capture latch happened when the corresponding CAPIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CAPIF.
     * @var TIMER_T::TRGCTL
     * Offset: 0x1C  Timer0~3 Trigger Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |TRGSSEL   |Trigger Source Select Bit
     * |        |          |This bit is used to select internal trigger source is form timer time-out interrupt signal or capture interrupt signal.
     * |        |          |0 = Time-out interrupt signal is used to internal trigger PWM and ADC.
     * |        |          |1 = Capture interrupt signal is used to internal trigger PWM and ADC.
     * |[1]     |TRGPWM    |Trigger PWM Enable Bit
     * |        |          |If this bit is set to 1, each timer time-out event or capture event can be as PWM counter clock source.
     * |        |          |0 = Timer interrupt trigger PWM Disabled.
     * |        |          |1 = Timer interrupt trigger PWM Enabled.
     * |        |          |Note: If TRGSSEL (TIMERx_TRGCTL[0]) = 0, time-out interrupt signal as PWM counter clock source.
     * |        |          |If TRGSSEL (TIMERx_TRGCTL[0]) = 1, capture interrupt signal as PWM counter clock source.
     * |[2]     |TRGADC    |Trigger ADC Enable Bit
     * |        |          |If this bit is set to 1, each timer time-out event or capture event can be triggered ADC conversion.
     * |        |          |0 = Timer interrupt trigger ADC Disabled.
     * |        |          |1 = Timer interrupt trigger ADC Enabled.
     * |        |          |Note: If TRGSSEL (TIMERx_TRGCTL[0]) = 0, time-out interrupt signal will trigger ADC conversion.
     * |        |          |If TRGSSEL (TIMERx_TRGCTL[0]) = 1, capture interrupt signal will trigger ADC conversion.
     * @var TIMER_T::CAPNF
     * Offset: 0x24  Timer0~3 Capture Input Noise Filter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CAPNFEN   |Capture Noise Filter Enable
     * |        |          |0 = Capture Noise Filter function Disabled.
     * |        |          |1 = Capture Noise Filter function Enabled.
     * |[6:4]   |CAPNFSEL  |Capture Edge Detector Noise Filter Clock Selection
     * |        |          |000 = Noise filter clock is PCLKx.
     * |        |          |001 = Noise filter clock is PCLKx/2.
     * |        |          |010 = Noise filter clock is PCLKx/4.
     * |        |          |011 = Noise filter clock is PCLKx/8.
     * |        |          |100 = Noise filter clock is PCLKx/16.
     * |        |          |101 = Noise filter clock is PCLKx/32.
     * |        |          |110 = Noise filter clock is PCLKx/64.
     * |        |          |111 = Noise filter clock is PCLKx/128.
     * |[10:8]  |CAPNFCNT  |Capture Edge Detector Noise Filter Count
     * |        |          |These bits control the capture filter counter to count from 0 to CAPNFCNT.
     * @var TIMER_T::CAP1
     * Offset: 0x78  Timer0~3 Capture Data 1 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CAPDATn   |Timer Capture Data n Register
     * |        |          |When CAPEN (TIMERx_EXTCTL[3]) bit is set and CAPLSEL(TIMERx_EXTCTL[21:20]) not equal to 00b, CAPFUNCS (TIMERx_EXTCTL[4]) bit is 0, and a transition on TMx_EXT pin matched the CAPEDGE (TIMERx_EXTCTL[14:12]) setting, the current timer counter value CNT (TIMERx_CNT[23:0]) will be auto-loaded into this CAPDATn field.
     * @var TIMER_T::CAP2
     * Offset: 0x7C  Timer0~3 Capture Data 2 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CAPDATn   |Timer Capture Data n Register
     * |        |          |When CAPEN (TIMERx_EXTCTL[3]) bit is set and CAPLSEL(TIMERx_EXTCTL[21:20]) not equal to 00b, CAPFUNCS (TIMERx_EXTCTL[4]) bit is 0, and a transition on TMx_EXT pin matched the CAPEDGE (TIMERx_EXTCTL[14:12]) setting, the current timer counter value CNT (TIMERx_CNT[23:0]) will be auto-loaded into this CAPDATn field.
     * @var TIMER_T::CAP3
     * Offset: 0x80  Timer0~3 Capture Data 3 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CAPDATn   |Timer Capture Data n Register
     * |        |          |When CAPEN (TIMERx_EXTCTL[3]) bit is set and CAPLSEL(TIMERx_EXTCTL[21:20]) not equal to 00b, CAPFUNCS (TIMERx_EXTCTL[4]) bit is 0, and a transition on TMx_EXT pin matched the CAPEDGE (TIMERx_EXTCTL[14:12]) setting, the current timer counter value CNT (TIMERx_CNT[23:0]) will be auto-loaded into this CAPDATn field.
     */
    __IO uint32_t CTL;                   /*!< [0x0000] Timer Control Register                                           */
    __IO uint32_t CMP;                   /*!< [0x0004] Timer Comparator Register                                        */
    __IO uint32_t INTSTS;                /*!< [0x0008] Timer Interrupt Status Register                                  */
    __IO uint32_t CNT;                   /*!< [0x000c] Timer Data Register                                              */
    __I  uint32_t CAP;                   /*!< [0x0010] Timer Capture Data Register                                      */
    __IO uint32_t EXTCTL;                /*!< [0x0014] Timer External Control Register                                  */
    __IO uint32_t EINTSTS;               /*!< [0x0018] Timer External Interrupt Status Register                         */
    __IO uint32_t TRGCTL;                /*!< [0x001c] Timer Trigger Control Register                                   */
    __I  uint32_t RESERVE0[1];
    __IO uint32_t CAPNF;                 /*!< [0x0024] Timer Capture Input Noise Filter Register                        */
    __I  uint32_t RESERVE1[20];
    __I  uint32_t CAP1;                  /*!< [0x0078] Timer Capture 1 Data Register                                    */
    __I  uint32_t CAP2;                  /*!< [0x007c] Timer Capture 2 Data Register                                    */
    __I  uint32_t CAP3;                  /*!< [0x0080] Timer Capture 3 Data Register                                    */
    /** @endcond */

} TIMER_T;

/**
    @addtogroup TIMER_CONST TIMER Bit Field Definition
    Constant Definitions for TIMER Controller
@{ */

#define TIMER_CTL_PSC_Pos                (0)                                               /*!< TIMER_T::CTL: PSC Position             */
#define TIMER_CTL_PSC_Msk                (0xfful << TIMER_CTL_PSC_Pos)                     /*!< TIMER_T::CTL: PSC Mask                 */

#define TIMER_CTL_INTRGEN_Pos            (19)                                              /*!< TIMER_T::CTL: INTRGEN Position         */
#define TIMER_CTL_INTRGEN_Msk            (0x1ul << TIMER_CTL_INTRGEN_Pos)                  /*!< TIMER_T::CTL: INTRGEN Mask             */

#define TIMER_CTL_PERIOSEL_Pos           (20)                                              /*!< TIMER_T::CTL: PERIOSEL Position        */
#define TIMER_CTL_PERIOSEL_Msk           (0x1ul << TIMER_CTL_PERIOSEL_Pos)                 /*!< TIMER_T::CTL: PERIOSEL Mask            */

#define TIMER_CTL_TGLPINSEL_Pos          (21)                                              /*!< TIMER_T::CTL: TGLPINSEL Position       */
#define TIMER_CTL_TGLPINSEL_Msk          (0x1ul << TIMER_CTL_TGLPINSEL_Pos)                /*!< TIMER_T::CTL: TGLPINSEL Mask           */

#define TIMER_CTL_CAPSRC_Pos             (22)                                              /*!< TIMER_T::CTL: CAPSRC Position          */
#define TIMER_CTL_CAPSRC_Msk             (0x1ul << TIMER_CTL_CAPSRC_Pos)                   /*!< TIMER_T::CTL: CAPSRC Mask              */

#define TIMER_CTL_WKEN_Pos               (23)                                              /*!< TIMER_T::CTL: WKEN Position            */
#define TIMER_CTL_WKEN_Msk               (0x1ul << TIMER_CTL_WKEN_Pos)                     /*!< TIMER_T::CTL: WKEN Mask                */

#define TIMER_CTL_EXTCNTEN_Pos           (24)                                              /*!< TIMER_T::CTL: EXTCNTEN Position        */
#define TIMER_CTL_EXTCNTEN_Msk           (0x1ul << TIMER_CTL_EXTCNTEN_Pos)                 /*!< TIMER_T::CTL: EXTCNTEN Mask            */

#define TIMER_CTL_ACTSTS_Pos             (25)                                              /*!< TIMER_T::CTL: ACTSTS Position          */
#define TIMER_CTL_ACTSTS_Msk             (0x1ul << TIMER_CTL_ACTSTS_Pos)                   /*!< TIMER_T::CTL: ACTSTS Mask              */

#define TIMER_CTL_OPMODE_Pos             (27)                                              /*!< TIMER_T::CTL: OPMODE Position          */
#define TIMER_CTL_OPMODE_Msk             (0x3ul << TIMER_CTL_OPMODE_Pos)                   /*!< TIMER_T::CTL: OPMODE Mask              */

#define TIMER_CTL_INTEN_Pos              (29)                                              /*!< TIMER_T::CTL: INTEN Position           */
#define TIMER_CTL_INTEN_Msk              (0x1ul << TIMER_CTL_INTEN_Pos)                    /*!< TIMER_T::CTL: INTEN Mask               */

#define TIMER_CTL_CNTEN_Pos              (30)                                              /*!< TIMER_T::CTL: CNTEN Position           */
#define TIMER_CTL_CNTEN_Msk              (0x1ul << TIMER_CTL_CNTEN_Pos)                    /*!< TIMER_T::CTL: CNTEN Mask               */

#define TIMER_CTL_ICEDEBUG_Pos           (31)                                              /*!< TIMER_T::CTL: ICEDEBUG Position        */
#define TIMER_CTL_ICEDEBUG_Msk           (0x1ul << TIMER_CTL_ICEDEBUG_Pos)                 /*!< TIMER_T::CTL: ICEDEBUG Mask            */

#define TIMER_CMP_CMPDAT_Pos             (0)                                               /*!< TIMER_T::CMP: CMPDAT Position          */
#define TIMER_CMP_CMPDAT_Msk             (0xfffffful << TIMER_CMP_CMPDAT_Pos)              /*!< TIMER_T::CMP: CMPDAT Mask              */

#define TIMER_INTSTS_TIF_Pos             (0)                                               /*!< TIMER_T::INTSTS: TIF Position          */
#define TIMER_INTSTS_TIF_Msk             (0x1ul << TIMER_INTSTS_TIF_Pos)                   /*!< TIMER_T::INTSTS: TIF Mask              */

#define TIMER_INTSTS_TWKF_Pos            (1)                                               /*!< TIMER_T::INTSTS: TWKF Position         */
#define TIMER_INTSTS_TWKF_Msk            (0x1ul << TIMER_INTSTS_TWKF_Pos)                  /*!< TIMER_T::INTSTS: TWKF Mask             */

#define TIMER_CNT_CNT_Pos                (0)                                               /*!< TIMER_T::CNT: CNT Position             */
#define TIMER_CNT_CNT_Msk                (0xfffffful << TIMER_CNT_CNT_Pos)                 /*!< TIMER_T::CNT: CNT Mask                 */

#define TIMER_CNT_RSTACT_Pos             (31)                                              /*!< TIMER_T::CNT: RSTACT Position          */
#define TIMER_CNT_RSTACT_Msk             (0x1ul << TIMER_CNT_RSTACT_Pos)                   /*!< TIMER_T::CNT: RSTACT Mask              */

#define TIMER_CAP_CAPDAT_Pos             (0)                                               /*!< TIMER_T::CAP: CAPDAT Position          */
#define TIMER_CAP_CAPDAT_Msk             (0xfffffful << TIMER_CAP_CAPDAT_Pos)              /*!< TIMER_T::CAP: CAPDAT Mask              */

#define TIMER_EXTCTL_CNTPHASE_Pos        (0)                                               /*!< TIMER_T::EXTCTL: CNTPHASE Position     */
#define TIMER_EXTCTL_CNTPHASE_Msk        (0x1ul << TIMER_EXTCTL_CNTPHASE_Pos)              /*!< TIMER_T::EXTCTL: CNTPHASE Mask         */

#define TIMER_EXTCTL_CAPEN_Pos           (3)                                               /*!< TIMER_T::EXTCTL: CAPEN Position        */
#define TIMER_EXTCTL_CAPEN_Msk           (0x1ul << TIMER_EXTCTL_CAPEN_Pos)                 /*!< TIMER_T::EXTCTL: CAPEN Mask            */

#define TIMER_EXTCTL_CAPFUNCS_Pos        (4)                                               /*!< TIMER_T::EXTCTL: CAPFUNCS Position     */
#define TIMER_EXTCTL_CAPFUNCS_Msk        (0x1ul << TIMER_EXTCTL_CAPFUNCS_Pos)              /*!< TIMER_T::EXTCTL: CAPFUNCS Mask         */

#define TIMER_EXTCTL_CAPIEN_Pos          (5)                                               /*!< TIMER_T::EXTCTL: CAPIEN Position       */
#define TIMER_EXTCTL_CAPIEN_Msk          (0x1ul << TIMER_EXTCTL_CAPIEN_Pos)                /*!< TIMER_T::EXTCTL: CAPIEN Mask           */

#define TIMER_EXTCTL_CAPDBEN_Pos         (6)                                               /*!< TIMER_T::EXTCTL: CAPDBEN Position      */
#define TIMER_EXTCTL_CAPDBEN_Msk         (0x1ul << TIMER_EXTCTL_CAPDBEN_Pos)               /*!< TIMER_T::EXTCTL: CAPDBEN Mask          */

#define TIMER_EXTCTL_CNTDBEN_Pos         (7)                                               /*!< TIMER_T::EXTCTL: CNTDBEN Position      */
#define TIMER_EXTCTL_CNTDBEN_Msk         (0x1ul << TIMER_EXTCTL_CNTDBEN_Pos)               /*!< TIMER_T::EXTCTL: CNTDBEN Mask          */

#define TIMER_EXTCTL_INTERCAPSEL_Pos     (8)                                               /*!< TIMER_T::EXTCTL: INTERCAPSEL Position  */
#define TIMER_EXTCTL_INTERCAPSEL_Msk     (0x7ul << TIMER_EXTCTL_INTERCAPSEL_Pos)           /*!< TIMER_T::EXTCTL: INTERCAPSEL Mask      */

#define TIMER_EXTCTL_CAPEDGE_Pos         (12)                                              /*!< TIMER_T::EXTCTL: CAPEDGE Position      */
#define TIMER_EXTCTL_CAPEDGE_Msk         (0x7ul << TIMER_EXTCTL_CAPEDGE_Pos)               /*!< TIMER_T::EXTCTL: CAPEDGE Mask          */

#define TIMER_EXTCTL_ECNTSSEL_Pos        (16)                                              /*!< TIMER_T::EXTCTL: ECNTSSEL Position     */
#define TIMER_EXTCTL_ECNTSSEL_Msk        (0x7ul << TIMER_EXTCTL_ECNTSSEL_Pos)              /*!< TIMER_T::EXTCTL: ECNTSSEL Mask         */

#define TIMER_EXTCTL_CAPLSEL_Pos          (20)                                             /*!< TIMER_T::EXTCTL: CAPLSEL Position       */
#define TIMER_EXTCTL_CAPLSEL_Msk          (0x3ul << TIMER_EXTCTL_CAPLSEL_Pos)              /*!< TIMER_T::EXTCTL: CAPLSEL Mask           */

#define TIMER_EXTCTL_CAPDIVSCL_Pos       (28)                                              /*!< TIMER_T::EXTCTL: CAPDIVSCL Position    */
#define TIMER_EXTCTL_CAPDIVSCL_Msk       (0xful << TIMER_EXTCTL_CAPDIVSCL_Pos)             /*!< TIMER_T::EXTCTL: CAPDIVSCL Mask        */

#define TIMER_EINTSTS_CAPIF_Pos          (0)                                               /*!< TIMER_T::EINTSTS: CAPIF Position       */
#define TIMER_EINTSTS_CAPIF_Msk          (0x1ul << TIMER_EINTSTS_CAPIF_Pos)                /*!< TIMER_T::EINTSTS: CAPIF Mask           */

#define TIMER_EINTSTS_CAPIFOV_Pos        (1)                                               /*!< TIMER_T::EINTSTS: CAPIFOV Position     */
#define TIMER_EINTSTS_CAPIFOV_Msk        (0x1ul << TIMER_EINTSTS_CAPIFOV_Pos)              /*!< TIMER_T::EINTSTS: CAPIFOV Mask         */

#define TIMER_TRGCTL_TRGSSEL_Pos         (0)                                               /*!< TIMER_T::TRGCTL: TRGSSEL Position      */
#define TIMER_TRGCTL_TRGSSEL_Msk         (0x1ul << TIMER_TRGCTL_TRGSSEL_Pos)               /*!< TIMER_T::TRGCTL: TRGSSEL Mask          */

#define TIMER_TRGCTL_TRGPWM_Pos          (1)                                               /*!< TIMER_T::TRGCTL: TRGPWM Position       */
#define TIMER_TRGCTL_TRGPWM_Msk          (0x1ul << TIMER_TRGCTL_TRGPWM_Pos)                /*!< TIMER_T::TRGCTL: TRGPWM Mask           */

#define TIMER_TRGCTL_TRGADC_Pos          (2)                                               /*!< TIMER_T::TRGCTL: TRGADC Position       */
#define TIMER_TRGCTL_TRGADC_Msk          (0x1ul << TIMER_TRGCTL_TRGADC_Pos)                /*!< TIMER_T::TRGCTL: TRGADC Mask           */

#define TIMER_CAPNF_CAPNFEN_Pos          (0)                                               /*!< TIMER_T::CAPNF: CAPNFEN Position       */
#define TIMER_CAPNF_CAPNFEN_Msk          (0x1ul << TIMER_CAPNF_CAPNFEN_Pos)                /*!< TIMER_T::CAPNF: CAPNFEN Mask           */

#define TIMER_CAPNF_CAPNFSEL_Pos         (4)                                               /*!< TIMER_T::CAPNF: CAPNFSEL Position      */
#define TIMER_CAPNF_CAPNFSEL_Msk         (0x7ul << TIMER_CAPNF_CAPNFSEL_Pos)               /*!< TIMER_T::CAPNF: CAPNFSEL Mask          */

#define TIMER_CAPNF_CAPNFCNT_Pos         (8)                                               /*!< TIMER_T::CAPNF: CAPNFCNT Position      */
#define TIMER_CAPNF_CAPNFCNT_Msk         (0x7ul << TIMER_CAPNF_CAPNFCNT_Pos)               /*!< TIMER_T::CAPNF: CAPNFCNT Mask          */

#define TIMER_CAP1_CAPDAT_Pos            (0)                                               /*!< TIMER_T::CAP1: CAPDAT Position         */
#define TIMER_CAP1_CAPDAT_Msk            (0xfffffful << TIMER_CAP1_CAPDAT_Pos)             /*!< TIMER_T::CAP1: CAPDAT Mask             */

#define TIMER_CAP2_CAPDAT_Pos            (0)                                               /*!< TIMER_T::CAP2: CAPDAT Position         */
#define TIMER_CAP2_CAPDAT_Msk            (0xfffffful << TIMER_CAP2_CAPDAT_Pos)             /*!< TIMER_T::CAP2: CAPDAT Mask             */

#define TIMER_CAP3_CAPDAT_Pos            (0)                                               /*!< TIMER_T::CAP3: CAPDAT Position         */
#define TIMER_CAP3_CAPDAT_Msk            (0xfffffful << TIMER_CAP3_CAPDAT_Pos)             /*!< TIMER_T::CAP3: CAPDAT Mask             */

/**@}*/ /* TIMER_CONST */
/**@}*/ /* end of TIMER register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __TIMER_REG_H__ */
