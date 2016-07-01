/**
*\file
*\brief Файл данных для генератора кода таймера
*\author Михаил Жидков
*\version 1.0
*\date 30 июня 2016 года
*В этом файле находится набор стрктур для генерации кода таймера
*/
#ifndef STRUCT_TIMER_H
#define STRUCT_TIMER_H


struct TIMER_CNT
       {
    int CNT;
};

struct TIMER_ARR
{
    int ARR;
};

struct TIMER_PSG
{
    short PSG;
};

struct TIMER_CCRy
{
    int CCR;
};

struct TIMER_CCRy1
{
    int CCR1;
};

struct TIMER_Chy_CNTRL
{
    int CAP;
};


enum EVENT_TIMER
{
  TIM_Clock=0b0000,
  ARRTIM1=0b0001,
  ARRTIM2=0b0010,
  ARRTIM3=0b0011,
  Event_Chanel1=0b0100,
  Event_Chanel2=0b0101,
  Event_Chanel3=0b0110,
  Event_Chanel4=0b0111,
  Event_Front_ETR_P=0b1000,
  Event_Front_ETR_Z=0b1001,
  ARR_TIMER4=0b1010,
};

enum CNT_TIMER
{
  Timer_UP=0b00,
  Timer_UP_Down=0b01,
  Timer_Down=0b10,
};

enum FDTS_TIMER
{
    TIM_CLICK = 0b00,
    TIM_CLICK2 = 0b01,
    TIM_CLICK3 = 0b10,
    TIM_CLICK4 = 0b11,
};

enum DIR_Timer
{
    Up,
    Down
};

enum WR_CMPL_TIMER
{
    Record,
    NewRecord
};

enum Record_TIMER
{
    ARR_Moment_Record,
    ARR_Finish_Record
};


struct TIMER_CNTRL
{
 enum EVENT_TIMER EVENT_SEL;
 enum CNT_TIMER  CNT_MODE;
 enum FDTS_TIMER FDTS;
 enum DIR_Timer DIR;
 enum WR_CMPL_TIMER  WR_CMPL;
 enum Record_TIMER ARRB_EN;
 enum Switches CNT_EN;
};

enum CAP_Timer
{
    Mode_Capture,
    Mode_SHIM
};

enum Reset
{
  Banned,
  Allowed
};

enum WORK_ETR
{
    Banned_ETR,
    Allowed_ETR
};

enum Signal_CHFLTR
{
    TIM_CLK1 = 0b0000,
    TIM_CLK2 = 0b0001,
    TIM_CLK3 = 0b0010,
    TIM_CLK4 = 0b0011,
    FDTS2_6 = 0b0100,
    FDTS2_8  = 0b0101,
    FDTS4_6 = 0b0110,
    FDTS4_8 = 0b0111,
    FDTS8_6 = 0b1000,
    FDTS8_8 = 0b1001,
    FDTS16_5 = 0b1010,
    FDTS16_8 = 0b1011,
    FDTS16_6 = 0b1100,
    FDTS32_5 = 0b1101,
    FDTS32_6 = 0b1110,
    FDTS32_8 = 0b1111,

};

enum CHSEL_TIMER
{
    plus_front_CHxi=0b00,
    minus_front_CHxi=0b01,
    plus_front_12_23_34_41=0b10,
    plus_front_13_24_31_42=0b11
};

enum CHPSC_TIMER
{
    Not_Div=0b00,
    Div2=0b01,
    Div4=0b10,
    Div8=0b11
};

enum OCCM_TIMER
{
  //Формат выработки сигнала REF в режиме ШИМ Если CCR1_EN = 0:
//000 – всегда 0 001 – 1, если CNT = CCR;
//010 – 0, если CNT = CCR
//100 – всегда 0;
//    101 – всегда 1; 110 – 1,
//    если DIR= 0 (счет вверх), CNT<CCR, иначе 0;     0,
//    если DIR= 1 (счет вниз), CNT>CCR, иначе 1;  111 – 0,
//    если DIR= 0 (счет вверх), CNT<CCR, иначе 1;            1,
//    если DIR= 1 (счет вниз), CNT>CCR, иначе 0.
//Если CCR1_EN = 1:  000 – всегда 0; 001 – 1, если CNT = CCR или CNT = CCR1 010 – 0, если CNT = CCR или CNT = CCR1; 011 – переключение REF, если CNT =CCR или CNT =CCR1; 100 – всегда 0; 101 – всегда 1; 110 – 1, если DIR = 0 (счет вверх), CCR< CNT< CCR1, иначе 0;            0, если DIR = 1 (счет вниз), CCR < CNT < CCR1, иначе 1;  111 – 0, если DIR = 0 (счет вверх), CCR< CNT < CCR1, иначе 1;            1, если DIR = 1 (счет вниз), CCR< CNT< CCR1, иначе 0. При условии, что CCR < CCR1
};

struct Chy_CNTRL
{
enum CAP_Timer CAP;
enum Record_TIMER   WR;
enum Reset ETREN;
enum Reset BRKEN;
enum OCCM_TIMER OCCM;
enum WORK_ETR OCCE;
enum CHPSC_TIMER CHPSC;
enum CHSEL_TIMER CHSEL;
enum Signal_CHFLTR CHFLTR;
};

enum Invert
{
  Not_Invert,
  Invert
};

enum Work_Invert_Chanel
{
    Chanel_Not_Working_0=0b00,
    Chanel_Working_1=0b01,
    signal_REF=0b10,
    signal_DTG=0b11
};

enum Mode_Exit_Straight
{
    Chanel_Not_Working_1=0b00,
    Chanel_Working_Exit_1=0b01,
    Signal_REF=0b10
};

struct Chy_CNTRL1
{
enum Invert NINV;
enum Work_Invert_Chanel NSELO;
enum Work_Invert_Chanel NSELOE;
enum Invert INV;
enum Work_Invert_Chanel SELO;
enum Mode_Exit_Straight SELOE;
};


enum Update_CCR_CRR1
{
    Update_any_moment,
    Update_cnt_0
};

enum Work_CRR1
{
    CRR1_Not_Working,
    CRR1_Works
};

struct Chy_CNTRL2
{
   enum Update_CCR_CRR1 CRRRLD;
   enum Work_CRR1 CCR1_EN;
   enum CHSEL_TIMER CHSEL1;
};

enum Work_DTG
{
    TIM_CLK,
    FDTS
};

struct CHy_DTG
{
 unsigned charDTGx;
 enum Work_DTG EDTS;
 unsigned char DTG;
};

struct BRKETR_CNTRL
{
enum Signal_CHFLTR ETR_FILTER;
enum CHPSC_TIMER ETRPSC;
enum Reset ETR_INV;
enum Reset BRK_INV;
};

struct STATUS
{
   enum Switches CCR_CAP1_EVENT;
   enum Switches CCR_REF_EVENT;
   enum Switches CCR_CAP_EVENT;
   enum Switches BRK_EVENT;
   enum Switches ETR_FE_EVENT;
   enum Switches ETR_RE_EVENT;
   enum Switches CNT_ARR_EVENT;
   enum Switches CNT_ZERO_EVENT;
};

struct IE
{
 enum Switches CRR_CAP1_EVENT_IE;
 enum Switches CRR_REF_EVENT_IE;
 enum Switches CCR_CAP_EVENT_IE;
 enum Switches BRK_EVENT_IE;
 enum Switches ETR_FE_EVENT_IE;
 enum Switches ETR_RE_EVENT_IE;
 enum Switches CNT_ARR_EVENT_IE;
 enum Switches CNT_ZERO_EVENT_IE;

};

struct DMA_RE
{
    enum Switches CRR_CAP1_EVENT_RE;
    enum Switches CRR_REF_EVENT_RE;
    enum Switches CCR_CAP_EVENT_RE;
    enum Switches BRK_EVENT_RE;
    enum Switches ETR_FE_EVENT_RE;
    enum Switches ETR_RE_EVENT_RE;
    enum Switches CNT_ARR_EVENT_RE;
    enum Switches CNT_ZERO_EVENT_RE;
};

struct TIMER_Global
{
    struct TIMER_CCRy1 CCR1[4];
    struct TIMER_CCRy CCR[4];
    struct PSG ;
    struct CNT;
    struct ARR;
    struct CNTRL;
    struct Chy_CNTRL Chy_CNTRL[4];
    struct Chy_CNTRL1 Chy_CNTRL1[4];
    struct Chy_CNTRL2 Chy_CNTRL2[4];
    struct Chy_DTG;
    struct BRKETR_CNTRL;
    struct IE;
    struct DMA_RE DMA_RE[4];
};

#endif // STRUCT_TIMER_H
