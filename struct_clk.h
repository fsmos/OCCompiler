/**
*\file
*\brief Файл данных для генератора кода настроек тактирования
*\author Ярошенко Артур
*\version 1.0
*\date 30 июня 2016 года
*В этом файле находится набор стрктур для генерации кода настроек тактирования
*/
#ifndef STRUCT_CLK_H
#define STRUCT_CLK_H

struct CLOCK_STATUS
{
    enum Switches HSE_RDY2_READ_ENABLE;
    enum Switches HSE_RDY_READ_ENABLE;
    enum Switches PLL_CPU_RDY_READ_ENABLE;
    enum Switches PLL_USB_RDY_READ_ENABLE;
};

struct PLL_CONTROL
{
   unsigned char PLL_CPU_MUL;
   unsigned char PLL_USB_MUL;
   enum Switches PLL_CPU_PLD_RESET_ENABLE; ///<При смене коэффициента умножения в рабочем режиме необходимо задать равным 1, а после этого сбросить в ноль
   enum Switches PLL_CPU_ON;
   enum Switches PLL_USB_RLD_RESET_ENABLE; ///<При смене коэффициента умножения в рабочем режиме необходимо задать равным 1, а после этого сбросить в ноль
   enum Switches PLL_USB;
};

enum HSE_SORCE_TYPE
{
    mode_oscilator,
    mode_generator
};
struct HS_CONTROL
{
    enum HSE_SORCE_TYPE HSE_BYP2;
    enum Switches HSE_ON2;
    enum HSE_SORCE_TYPE HSE_BYP;
    enum Switches HSE_ON;
};

enum HCLK
{
    HSE = 0b00,
    CPU_C3 = 0b01,
    LSE = 0b10,
    LSI = 0b11
};
enum CPU_C3
{
    CPU_C2 = 0b0000,
    CPU_C2DIV2 = 0b1000,
    CPU_C2DIV4 = 0b1001,
    CPU_C2DIV8 = 0b1010,
    CPU_C2DIV16 = 0b1011,
    CPU_C2DIV32 = 0b1100,
    CPU_C2DIV64 = 0b1101,
    CPU_C2DIV128 = 0b1110,
    CPU_C2DEIV256 = 0b1111

};
enum CPU_C2
{
    CPU_C1 = 0b0000,
    PLLCPUo = 0b0001
};
enum CPU_C1
{
    HSI = 0b0000,
    HSIDIV2 = 0b0001,
    HSE_CPU = 0b0010,
    HSEDIV2 = 0b0011
};

struct CPU_CLOCK
{
    enum HCLK HCLK_SEL;
//    enum CPU_C3 CPU_C3_SEL;
    unsigned char CPU_C3_SEL;
    enum CPU_C2 CPU_C2_SEL;
    enum CPU_C1 CPU_C1_SEL;
};

enum USB_C2
{
    USB_C1 = 0b0000,
    PLLUSBo = 0b0001
};


struct USB_CLOCK
{
    enum Switches USB_CLK_EN;
    enum Switches USB_C3_SEL; ///<биты делителя на USB_C3
    enum USB_C2 USB_C2_SEL;
    enum CPU_C1 USB_C1_SEL;
};

enum ADC_C2
{
    LSE_ADC = 0b0000,
    LSI_ADC = 0b0001,
    ADC_C1 = 0b0010,
    HSI_C1 = 0b0011
};

enum ADC_C1
{
    CPU_C1_ADC = 0b0000,
    USB_C1_ADC = 0b0001,
    CPU_C2_ADC = 0b0010,
    USB_C2 = 0b0011
};

struct ADC_MCO_CLOCK
{
    enum Switches ADC_CLK_EN;
    unsigned char ADC_C3_SEll;
    enum ADC_C2 ADC_C2_SELL;
    enum ADC_C1 ADC_C1_SELL;
};

struct RTC_CLOCK
{
    enum Switches HSI_RTC_EN;
    enum Switches HSE_RTC_EN;
    unsigned char HSI_SEL;
    unsigned char HSE_SEL;
};

struct PER_CLOCK
{
    enum Switches CAN1_CLK;
    enum Switches CAN2_CLK;
    enum Switches USB_CLK;
    enum Switches EEPROM_CNTRL_CLK;
    enum Switches RST_CLK_CLK;
    enum Switches DMA_CLK;
    enum Switches UART1_CLK;
    enum Switches UART2_CLK;
    enum Switches SPI1_CLK;
    enum Switches MIL_STD_1553B1_CLK;
    enum Switches MIL_STD_1553B2_CLK;
    enum Switches POWER_CLK;
    enum Switches WWDT_CLK;
    enum Switches IWDT_CLK;
    enum Switches TIMER1_CLK;
    enum Switches TIMER2_CLK;
    enum Switches TIMER3_CLK;
    enum Switches ADC_CLK;
    enum Switches DAC_CLK;
    enum Switches TIMER4_CLK;
    enum Switches SPI2_CLK;
    enum Switches PORTA_CLK;
    enum Switches PORTB_CLK;
    enum Switches PORTC_CLK;
    enum Switches PORTD_CLK;
    enum Switches PORTE_CLK;
    enum Switches ARINC429R_CLK;
    enum Switches BKP_CLK;
    enum Switches ARINC429T_CLK;
    enum Switches PORTF_CLK;
    enum Switches EXT_BUS_CNTRL_CLK;
    enum Switches SPI3_CLK;
};

enum CAN_CLK_DIV
{
    HCLK = 0b000,
    HCLKDIV2 = 0b001,
    HCLKDIV4 = 0b010,
    HCLKDIV8 = 0b011,
    HCLKDIV16 = 0b100,
    HCLKDIV32 = 0b101,
    HCLKDIV64 = 0b110,
    HCLKDIV128 = 0b111
};

struct CAN_CLOCK
{
    enum Switches CAN2_CLK_EN;
    enum Switches CAN1_CLK_EN;
    unsigned char CAN2_BRG;
    unsigned char CAN1_BRG;
};

struct TIM_CLOCK
{
    enum Switches TIM3_CLK_EN;
    enum Switches TIM2_CLK_EN;
    enum Switches TIM1_CLK_EN;
    unsigned char TIM3_BRG;
    unsigned char TIM2_BRG;
    unsigned char TIM1_BRG;
};

struct UART_CLOCK
{
    enum Switches TIM4_CLK_EN;
    enum Switches UART2_CLK_EN;
    enum Switches UART1_CLK_EN;
    unsigned char TIM4_BRG;
    unsigned char UART2_BRG;
    unsigned char UART1_BRG;
};

struct SSP_CLOCK
{
    enum Switches SSP3_CLK_EN;
    enum Switches SSP2_CLK_EN;
    enum Switches SSP1_CLK_EN;
    unsigned char SSP3_BRG;
    unsigned char SSP2_BRG;
    unsigned char SSP1_BRG;
};

enum PHY_CLK
{
    HSI_PHY = 0b00,
    HSE_PHY = 0b01,
    PLLCPUo_PHY = 0b10,
    HSE2 = 0b11
};

enum sleep_mode
{
    work_mode,
    slow_energy
};

struct ETH_CLOCK
{
    enum PHY_CLK PHY_CLK_SEL;
    enum Switches PHY_CLK_EN;
    enum sleep_mode SLEEP;
    enum Switches MAN_CLK_EN;
    enum Switches ETH_CLK_EN;
    unsigned char PHY_BRG;
    unsigned char MAN_BRG;
};

struct CLK_GLOBAL
{
    struct CLOCK_STATUS CLK_ST;
    struct PLL_CONTROL PLL_CNTRL;
    struct HS_CONTROL HS_CNTRL;
    struct CPU_CLOCK CPU_CLK;
    struct USB_CLOCK USB_CLK;
    struct ADC_MCO_CLOCK ADC_MCO_CLK;
    struct RTC_CLOCK RTC_CLK;
    struct PER_CLOCK RER_CLK;
    struct CAN_CLOCK CAN_CLK;
    struct TIM_CLOCK TIM_CLK;
    struct UART_CLOCK U_CLK;
    struct SSP_CLOCK SSP_CLK;
    struct ETH_CLOCK ETH_CLK;
};



#endif // STRUCT_CLK_H

