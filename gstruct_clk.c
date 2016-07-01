#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_code.h"
#include <time.h>
#include "gstruct.h"
#define GPS_version_clk "V0.2 Beta"

void GenerateC_CLK_File(struct OporaDataStruct ors, char* file)
{
    char date[100];
        char filec[200];
        int i, j;
        unsigned int CLOCK_STATUS  = 0,
                     PLL_CONTROL   = 0,
                     HS_CONTROL    = 0,
                     CPU_CLOCK     = 0,
                     USB_CLOCK     = 0,
                     ADC_MCO_CLOCK = 0,
                     RTC_CLOCK     = 0,
                     PER_CLOCK     = 0,
                     CAN_CLOCK     = 0,
                     TIM_CLOCK     = 0,
                     UART_CLOCK    = 0,
                     SSP_CLOCK     = 0,
                     ETH_CLOCK     = 0;


        strcpy(filec,file);
        strcat(filec,"_clk.h");
        strcat(file,"_clk.c"); 
        FILE* fl = fopen(file,"w");
        struct tm* tkm;
        const time_t timer=time(NULL);
        tkm=localtime(&timer);
        strftime(date, 100,"%d.%m.%Y %H:%M:%S", tkm);
        fprintf(fl, "/*!\n\\file\n\\brief Заголовочный файл настройки тактирования\n\\author Gusenkov S.V.\n\\Version %s \n\\date %s\n*/\n", GPS_version_clk,date);
        fprintf(fl,"#include \"");
         strcpy(filec,strstr(filec,"\\"));
          while(strchr(filec,'\\'))
         {
             strcpy(filec,filec+1);
         }
        fprintf(fl,filec);
        fprintf(fl,"\"");
        fprintf(fl,"//Init Function_clk \n");
        fprintf(fl,"void InitFunction_clk() {");
        fprintf(fl, "\n");
        
        fprintf(fl, "/*!\n \\breif PLL_CONTROL\n");         
        
        if (ors.OPORA_CLOCK.PLL_CNTRL.PLL_USB == On)
        {
            fprintf(fl, "\nPLL_USB включен");
            PLL_CONTROL |= 1<<0;
        }
        else 
        {
            fprintf(fl, "\nPLL_USB выключен");
        }
        if (ors.OPORA_CLOCK.PLL_CNTRL.PLL_CPU_ON == On)
        {
            fprintf(fl, "\n PLL_CPU включен");
            PLL_CONTROL |= 1<<2;
        }
        else
        {
            fprintf(fl, "\n PLL_CPU вылючен");  
        }
        
        fprintf(fl, "\n значение множителя USB %d", ors.OPORA_CLOCK.PLL_CNTRL.PLL_USB_MUL);
        PLL_CONTROL |= ors.OPORA_CLOCK.PLL_CNTRL.PLL_USB_MUL << 4;
        
        fprintf(fl, "\n значение множителя CPU %d", ors.OPORA_CLOCK.PLL_CNTRL.PLL_CPU_MUL);
        PLL_CONTROL |= ors.OPORA_CLOCK.PLL_CNTRL.PLL_CPU_MUL << 8;
        
 //<<AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!       
        if (ors.OPORA_CLOCK.HS_CNTRL.HSE_ON == On)
        {
                fprintf(fl, "\n бит управления HSE осцилятором включен");
                HS_CONTROL |= 1 << 0;
        }
        else    fprintf(fl, "\n бит управления HSE осцилятором выключен");
        
        if (ors.OPORA_CLOCK.HS_CNTRL.HSE_BYP == mode_generator)
        {        
                fprintf(fl, "\n включен режим генератора для HSE");
                HS_CONTROL |= 1 << 1;           
        }
        else    fprintf(fl, "\n включен режим осцилятора для HSE");

        if (ors.OPORA_CLOCK.HS_CNTRL.HSE_ON2 == On)
        {        
                fprintf(fl, "\n бит управления HSE2 осцилятором включен");
                HS_CONTROL |= 1 << 2;           
        }
        else    fprintf(fl, "\n бит управления HSE2 осцилятором выключен");
        
        if (ors.OPORA_CLOCK.HS_CNTRL.HSE_BYP2 == mode_generator)
        {        
                fprintf(fl, "\n включен режим генератора для HSE2");
                HS_CONTROL |= 1 << 3;           
        }
        else    fprintf(fl, "\n включен режим осцилятора для HSE2");
 
 
 //0-1 не знаю
        
        switch (ors.OPORA_CLOCK.CPU_CLK.CPU_C1_SEL)
        {
            case     HSI:
                fprintf(fl, "\n выбор истоничка для CPU_C1 HSI");
                CPU_CLOCK |= 0b00;                
            break;
            
            case HSIDIV2:
                fprintf(fl, "\n выбор истоничка для CPU_C1 HSI/2");
                CPU_CLOCK |= 0b01;                 
            break;
            
            case HSE_CPU:
                fprintf(fl, "\n выбор истоничка для CPU_C1 HSE");
                CPU_CLOCK |= 0b10;                 
            break;    

            case HSEDIV2:
                fprintf(fl, "\n выбор истоничка для CPU_C1 HSE/2");
                CPU_CLOCK |= 0b11;                 
            break;   
     
        }
        
        if (ors.OPORA_CLOCK.CPU_CLK.CPU_C2_SEL == PLLCPUo)
        {
             fprintf(fl, "\n для источника выбран PLLZPUo");
             CPU_CLOCK |= 1 << 2;
        }
        else fprintf(fl, "\n для источника выбран CPU_C2");
        
        switch (ors.OPORA_CLOCK.CPU_CLK.CPU_C3_SEL)
        {
            case CPU_C2:
                fprintf(fl, "делитель для CPU_C3 - 1");
                CPU_CLOCK |= CPU_C2 << 4;
            break;
            
            case CPU_C2DIV2:
                fprintf(fl, "делитель для CPU_C3 - 2");
                CPU_CLOCK |= CPU_C2DIV2 << 4;
            break;

            case CPU_C2DIV4:
                fprintf(fl, "делитель для CPU_C3 - 4");
                CPU_CLOCK |= CPU_C2DIV4 << 4;
            break;
            
            case CPU_C2DIV8:
                fprintf(fl, "делитель для CPU_C3 - 8");
                CPU_CLOCK |= CPU_C2DIV8 << 4;
            break;            
            
            case CPU_C2DIV16:
                fprintf(fl, "делитель для CPU_C3 - 16");
                CPU_CLOCK |= CPU_C2DIV16 << 4;
            break; 
            
            case CPU_C2DIV32:
                fprintf(fl, "делитель для CPU_C3 - 32");
                CPU_CLOCK |= CPU_C2DIV32 << 4;
            break; 
            
            case CPU_C2DIV64:
                fprintf(fl, "делитель для CPU_C3 - 64");
                CPU_CLOCK |= CPU_C2DIV64 << 4;
            break; 
            
            case CPU_C2DIV128:
                fprintf(fl, "делитель для CPU_C3 - 128");
                CPU_CLOCK |= CPU_C2DIV128 << 4;
            break; 
            
            case CPU_C2DEIV256:
                fprintf(fl, "делитель для CPU_C3 - 128");
                CPU_CLOCK |= CPU_C2DEIV256 << 4;
            break; 
        }
        
        
        switch (ors.OPORA_CLOCK.CPU_CLK.HCLK_SEL)
        {
            case HSI: 
                fprintf(fl, "\n Источник для HCLK - HSI");
                CPU_CLOCK |= HSE << 8;
            break;
            
            case CPU_C3: 
                fprintf(fl, "\n Источник для HCLK - CPU_C3");
                CPU_CLOCK |= CPU_C3 << 8;
            break;
            
            case LSE: 
                fprintf(fl, "\n Источник для HCLK - LSE");
                CPU_CLOCK |= LSE << 8;
            break;
            
            case LSI: 
                fprintf(fl, "\n Источник для HCLK - LSI");
                CPU_CLOCK |= LSI << 8;
            break;
        }
        
        
        switch (ors.OPORA_CLOCK.USB_CLK.USB_C1_SEL)
        {
            case HSI:
                fprintf(fl, "\n Источник для USB_C1 - HSI");
                USB_CLOCK = HSI;
            break;
            
            case HSIDIV2:
                fprintf(fl, "\n Источник для USB_C1 - HSI/2");
                USB_CLOCK = HSIDIV2;
            break;
            
            case HSE_CPU:
                fprintf(fl, "\n Источник для USB_C1 - HSE");
                USB_CLOCK = HSE;
            break;
            
            case HSEDIV2:
                fprintf(fl, "\n Источник для USB_C1 - HSE/2");
                USB_CLOCK = HSEDIV2;
            break;
        }

        if (ors.OPORA_CLOCK.USB_CLK.USB_C2_SEL == PLLCPUo)
        {
             fprintf(fl, "\n источник для USB-C2 - PLLUSBo");
             USB_CLOCK |= 1 << 2;
        }
        else fprintf(fl, "\n источник для USB-C2 - USB_C1");
        
        fprintf(fl, "\n делитель для USB_C3 - %d", ors.OPORA_CLOCK.USB_CLK.USB_C3_SEL);
        USB_CLOCK |= ors.OPORA_CLOCK.USB_CLK.USB_C3_SEL << 4;
        
        if  (ors.OPORA_CLOCK.USB_CLK.USB_CLK_EN == On)
        {
             fprintf(fl, "\n тактирование USB разрешено");
             USB_CLOCK |= 1 << 9;
        }
        else fprintf(fl, "\n тактирование USB запрещено");
        
        
        switch (ors.OPORA_CLOCK.ADC_MCO_CLK.ADC_C1_SELL)
        {
            case CPU_C1_ADC:
                fprintf(fl, "\n для ADC_C1 выбран источник CPU_C1");
                ADC_MCO_CLOCK |= CPU_C1_ADC;
            break;
            
            case USB_C1_ADC:
                fprintf(fl, "\n для ADC_C1 выбран источник CPU_C1");
                ADC_MCO_CLOCK |= USB_C1_ADC;
            break;
            
            case CPU_C2_ADC:
                fprintf(fl, "\n для ADC_C1 выбран источник CPU_C2");
                ADC_MCO_CLOCK |= CPU_C2_ADC;
            break;      
      
            case USB_C2:
                fprintf(fl, "\n для ADC_C1 выбран источник USB_C2");
                ADC_MCO_CLOCK |= USB_C2;
            break;
        }
        
        switch (ors.OPORA_CLOCK.ADC_MCO_CLK.ADC_C2_SELL)
        {
            case LSE_ADC:
                fprintf(fl, "\n для ADC_C2 выбран источник LSE");
                ADC_MCO_CLOCK |= LSE << 4;
            break;
            
            case LSI_ADC:
               fprintf(fl, "\n для ADC_C2 выбран источник LSI");
               ADC_MCO_CLOCK |= LSI << 4;
            break;
            
            case ADC_C1:
                fprintf(fl, "\n для ADC_C2 выбран источник ADC_C1");
                ADC_MCO_CLOCK |= ADC_C1 << 4;
            break;
            
            case HSI_C1:
                fprintf(fl, "\n для ADC_C2 выбран источник HSI_C1");
                ADC_MCO_CLOCK |= HSI_C1 << 4;
            break;
        }
        

        fprintf(fl, "\n делитель для ADC_C3 %d", ors.OPORA_CLOCK.ADC_MCO_CLK.ADC_C3_SEll);
        ADC_MCO_CLOCK |= ors.OPORA_CLOCK.ADC_MCO_CLK.ADC_C3_SEll << 8;
        
        if (ors.OPORA_CLOCK.ADC_MCO_CLK.ADC_CLK_EN == On)
        {
             fprintf(fl, "\n тактовая частота ADC_CLK разрешена");
             ADC_MCO_CLOCK |= 1 << 13;
        }
        else fprintf(fl, "\n тактовая частота ADC_CLK запрещена");
        
        
        fprintf(fl, "\n делитель для HSE_C1 - %d", ors.OPORA_CLOCK.RTC_CLK.HSE_SEL);
        RTC_CLOCK |= ors.OPORA_CLOCK.RTC_CLK.HSE_SEL;
        
        fprintf(fl, "\n делитель для HSI_C1 - %d", ors.OPORA_CLOCK.RTC_CLK.HSI_SEL);
        RTC_CLOCK |= ors.OPORA_CLOCK.RTC_CLK.HSI_SEL << 4;
        
        if (ors.OPORA_CLOCK.RTC_CLK.HSE_RTC_EN == On)
        {
             fprintf(fl, "\n HSE_RTC разрешен");
             RTC_CLOCK |= 1 << 8;
        }
        else fprintf(fl, "\n HSE_RTC запрещен");
        
        if (ors.OPORA_CLOCK.RTC_CLK.HSI_RTC_EN == On)
        {
             fprintf(fl, "\n HSI_RTC разрешен");
             RTC_CLOCK |= 1 << 9;
        }
        else fprintf(fl, "\n HSI_RTC запрещен");        
        
 
        if (ors.OPORA_CLOCK.RER_CLK.CAN1_CLK == On)
        {
             fprintf(fl, "\n CAN1 включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.CAN1_CLK;
        }
        else fprintf(fl, "\n CAN1 выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.CAN1_CLK == On)
        {
             fprintf(fl, "\n CAN2 включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.CAN2_CLK;
        }
        else fprintf(fl, "\n CAN2 выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.USB_CLK == On)
        {
             fprintf(fl, "\n USB включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.USB_CLK;
        }
        else fprintf(fl, "\n USB выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.EEPROM_CNTRL_CLK == On)
        {
             fprintf(fl, "\n EEPROM_CNTRL_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.EEPROM_CNTRL_CLK;
        }
        else fprintf(fl, "\n EEPROM_CNTRL_CLK выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.RST_CLK_CLK == On)
        {
             fprintf(fl, "\n RST_CLK_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.RST_CLK_CLK;
        }
        else fprintf(fl, "\n RST_CLK_CLK выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.DMA_CLK == On)
        {
             fprintf(fl, "\n DMA_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.DMA_CLK;
        }
        else fprintf(fl, "\n DMA_CLK выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.UART1_CLK == On)
        {
             fprintf(fl, "\n UART1_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.UART1_CLK;
        }
        else fprintf(fl, "\n UART1_CLK выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.UART2_CLK == On)
        {
             fprintf(fl, "\n UART2_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.UART2_CLK;
        }
        else fprintf(fl, "\n UART2_CLK выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.MIL_STD_1553B1_CLK == On)
        {
             fprintf(fl, "\n MIL_STD_1553B1_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.MIL_STD_1553B1_CLK;
        }
        else fprintf(fl, "\n MIL_STD_1553B1_CLK выключен");  

        if (ors.OPORA_CLOCK.RER_CLK.MIL_STD_1553B2_CLK == On)
        {
             fprintf(fl, "\n MIL_STD_1553B2_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.MIL_STD_1553B2_CLK;
        }
        else fprintf(fl, "\n MIL_STD_1553B2_CLK выключен");      
 
        if (ors.OPORA_CLOCK.RER_CLK.POWER_CLK == On)
        {
             fprintf(fl, "\n POWER_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.POWER_CLK;
        }
        else fprintf(fl, "\n POWER_CLK выключен");  

        if (ors.OPORA_CLOCK.RER_CLK.WWDT_CLK == On)
        {
             fprintf(fl, "\n WWDT_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.WWDT_CLK;
        }
        else fprintf(fl, "\n WWDT_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.IWDT_CLK == On)
        {
             fprintf(fl, "\n IWWDT_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.IWDT_CLK;
        }
        else fprintf(fl, "\n IWWDT_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.TIMER1_CLK == On)
        {
             fprintf(fl, "\n TIMER1_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.TIMER1_CLK;
        }
        else fprintf(fl, "\n TIMER1_CLK выключен");  

        if (ors.OPORA_CLOCK.RER_CLK.TIMER1_CLK == On)
        {
             fprintf(fl, "\n TIMER2_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.TIMER2_CLK;
        }
        else fprintf(fl, "\n TIMER2_CLK выключен"); 

        if (ors.OPORA_CLOCK.RER_CLK.TIMER3_CLK == On)
        {
             fprintf(fl, "\n TIMER3_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.TIMER3_CLK;
        }
        else fprintf(fl, "\n TIMER3_CLK выключен"); 
        
        if (ors.OPORA_CLOCK.RER_CLK.ADC_CLK == On)
        {
             fprintf(fl, "\n ADC_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.ADC_CLK;
        }
        else fprintf(fl, "\n ADC_CLK выключен");         


        if (ors.OPORA_CLOCK.RER_CLK.DAC_CLK == On)
        {
             fprintf(fl, "\n DAC_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.DAC_CLK;
        }
        else fprintf(fl, "\n DAC_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.TIMER4_CLK == On)
        {
             fprintf(fl, "\n TIMER4_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.TIMER4_CLK;
        }
        else fprintf(fl, "\n TIMER4_CLK выключен");


        if (ors.OPORA_CLOCK.RER_CLK.SPI2_CLK == On)
        {
             fprintf(fl, "\n SPI2_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.SPI2_CLK;
        }
        else fprintf(fl, "\n SPI2_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.PORTA_CLK == On)
        {
             fprintf(fl, "\n PORTA_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.PORTA_CLK;
        }
        else fprintf(fl, "\n PORTA_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.PORTB_CLK == On)
        {
             fprintf(fl, "\n PORTB_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.PORTB_CLK;
        }
        else fprintf(fl, "\n PORTB_CLK выключен");        
        
         if (ors.OPORA_CLOCK.RER_CLK.PORTC_CLK == On)
        {
             fprintf(fl, "\n PORTC_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.PORTC_CLK;
        }
        else fprintf(fl, "\n PORTC_CLK выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.PORTD_CLK == On)
        {
             fprintf(fl, "\n PORTD_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.PORTD_CLK;
        }
        else fprintf(fl, "\n PORTD_CLK выключен");
        
        if (ors.OPORA_CLOCK.RER_CLK.PORTE_CLK == On)
        {
             fprintf(fl, "\n PORTE_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.PORTE_CLK;
        }
        else fprintf(fl, "\n PORTE_CLK выключен"); 

        if (ors.OPORA_CLOCK.RER_CLK.ARINC429R_CLK == On)
        {
             fprintf(fl, "\n ARINC429R_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.ARINC429R_CLK;
        }
        else fprintf(fl, "\n ARINC429R_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.BKP_CLK == On)
        {
             fprintf(fl, "\n BKP_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.BKP_CLK;
        }
        else fprintf(fl, "\n BKP_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.ARINC429T_CLK == On)
        {
             fprintf(fl, "\n ARINC429T_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.ARINC429T_CLK;
        }
        else fprintf(fl, "\n ARINC429T_CLK выключен");
 
        if (ors.OPORA_CLOCK.RER_CLK.PORTF_CLK == On)
        {
             fprintf(fl, "\n PORTF_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.PORTF_CLK;
        }
        else fprintf(fl, "\n PORTF_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.EXT_BUS_CNTRL_CLK == On)
        {
             fprintf(fl, "\n EXT_BUS_CNTRL_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.EXT_BUS_CNTRL_CLK;
        }
        else fprintf(fl, "\n EXT_BUS_CNTRL_CLK выключен");

        if (ors.OPORA_CLOCK.RER_CLK.SPI3_CLK == On)
        {
             fprintf(fl, "\n SPI3_CLK включен");
             PER_CLOCK |= ors.OPORA_CLOCK.RER_CLK.SPI3_CLK;
        }
        else fprintf(fl, "\n SPI3_CLK выключен");
   
   
        fprintf(fl, "\n делитель тактовой частоты для CAN1 %d", ors.OPORA_CLOCK.CAN_CLK.CAN1_BRG);
        CAN_CLOCK |= ors.OPORA_CLOCK.CAN_CLK.CAN1_BRG;
        
        fprintf(fl, "\n делитель тактовой частоты для CAN2 %d", ors.OPORA_CLOCK.CAN_CLK.CAN2_BRG);
        CAN_CLOCK |= ors.OPORA_CLOCK.CAN_CLK.CAN2_BRG << 8;  

        if (ors.OPORA_CLOCK.CAN_CLK.CAN1_CLK_EN == On)
        {
             fprintf(fl, "\n присутствует тактовая частота на CAN1");
             CAN_CLOCK |= 1 << 24;
        }
        else fprintf(fl, "\n отсутствует тактовая частота на CAN1");

        if (ors.OPORA_CLOCK.CAN_CLK.CAN2_CLK_EN == On)
        {
             fprintf(fl, "\n присутствует тактовая частота на CAN2");
             CAN_CLOCK |= 1 << 24;
        }
        else fprintf(fl, "\n отсутствует тактовая частота на CAN2");
        
        
        fprintf(fl, "\n делитель тактовой частоты TIM1 - %d", ors.OPORA_CLOCK.TIM_CLK.TIM1_BRG);
        TIM_CLOCK |= ors.OPORA_CLOCK.TIM_CLK.TIM1_BRG;
        
        fprintf(fl, "\n делитель тактовой частоты TIM2 - %d", ors.OPORA_CLOCK.TIM_CLK.TIM2_BRG);
        TIM_CLOCK |= ors.OPORA_CLOCK.TIM_CLK.TIM2_BRG << 8;

        fprintf(fl, "\n делитель тактовой частоты TIM3 - %d", ors.OPORA_CLOCK.TIM_CLK.TIM3_BRG);
        TIM_CLOCK |= ors.OPORA_CLOCK.TIM_CLK.TIM3_BRG << 16;

        if (ors.OPORA_CLOCK.TIM_CLK.TIM1_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота TIM1 разрешена");
             TIM_CLOCK |= 1 << 24;
        }
        else fprintf(fl, "\n Тактовая частота TIM1 запрещена");
        
        if (ors.OPORA_CLOCK.TIM_CLK.TIM2_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота TIM2 разрешена");
             TIM_CLOCK |= 1 << 25;
        }
        else fprintf(fl, "\n Тактовая частота TIM2 запрещена");

        if (ors.OPORA_CLOCK.TIM_CLK.TIM3_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота TIM3 разрешена");
             TIM_CLOCK |= 1 << 26;
        }
        else fprintf(fl, "\n Тактовая частота TIM3 запрещена");
        

        fprintf(fl, "\n Делитель тактовой частоты UART1 - %d", ors.OPORA_CLOCK.U_CLK.UART1_BRG);
        UART_CLOCK |= ors.OPORA_CLOCK.U_CLK.UART1_BRG;
        
        fprintf(fl, "\n Делитель тактовой частоты UART2 - %d", ors.OPORA_CLOCK.U_CLK.UART2_BRG);
        UART_CLOCK |= ors.OPORA_CLOCK.U_CLK.UART2_BRG << 8;

        fprintf(fl, "\n Делитель тактовой частоты TIM4 - %d", ors.OPORA_CLOCK.U_CLK.TIM4_BRG);
        UART_CLOCK |= ors.OPORA_CLOCK.U_CLK.TIM4_BRG << 16;
        
        if (ors.OPORA_CLOCK.U_CLK.UART1_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота UART1 разрешена");
             UART_CLOCK |= 1 << 24;
        }
        else fprintf(fl, "\n Тактовая частота UART1 запрещена");        

        if (ors.OPORA_CLOCK.U_CLK.UART2_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота UART2 разрешена");
             UART_CLOCK |= 1 << 25;
        }
        else fprintf(fl, "\n Тактовая частота UART2 запрещена"); 

        if (ors.OPORA_CLOCK.U_CLK.TIM4_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота TIM4 разрешена");
             UART_CLOCK |= 1 << 26;
        }
        else fprintf(fl, "\n Тактовая частота TIM4 запрещена"); 


        fprintf(fl, "\n Делитель тактовой частоты SPP1 - %d", ors.OPORA_CLOCK.SSP_CLK.SSP1_BRG);
        UART_CLOCK |= ors.OPORA_CLOCK.SSP_CLK.SSP1_BRG;

        fprintf(fl, "\n Делитель тактовой частоты SPP2 - %d", ors.OPORA_CLOCK.SSP_CLK.SSP2_BRG);
        UART_CLOCK |= ors.OPORA_CLOCK.SSP_CLK.SSP2_BRG << 8;

        fprintf(fl, "\n Делитель тактовой частоты SPP3 - %d", ors.OPORA_CLOCK.SSP_CLK.SSP3_BRG);
        UART_CLOCK |= ors.OPORA_CLOCK.SSP_CLK.SSP3_BRG << 16;    

        if (ors.OPORA_CLOCK.SSP_CLK.SSP1_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота SSP1 разрешена");
             UART_CLOCK |= 1 << 24;
        }
        else fprintf(fl, "\n Тактовая частота SSP1 запрещена"); 

        if (ors.OPORA_CLOCK.SSP_CLK.SSP2_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота SSP2 разрешена");
             UART_CLOCK |= 1 << 25;
        }
        else fprintf(fl, "\n Тактовая частота SSP2 запрещена"); 
        
        if (ors.OPORA_CLOCK.SSP_CLK.SSP3_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота SSP3 разрешена");
             UART_CLOCK |= 1 << 26;
        }
        else fprintf(fl, "\n Тактовая частота SSP3 запрещена"); 
        
        fprintf(fl, "\n делитель тактовой частоты контроллера - %в", ors.OPORA_CLOCK.ETH_CLK.MAN_BRG);
        ETH_CLOCK |= ors.OPORA_CLOCK.ETH_CLK.MAN_BRG << 8;

        fprintf(fl, "\n делитель тактовой частоты PHY - %в", ors.OPORA_CLOCK.ETH_CLK.PHY_BRG);
        ETH_CLOCK |= ors.OPORA_CLOCK.ETH_CLK.PHY_BRG << 16;
        
        if (ors.OPORA_CLOCK.ETH_CLK.ETH_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота на Ethernet MAC разрешена");
             ETH_CLOCK |= 1 << 24;
        }
        else fprintf(fl, "\n Тактовая частота Ethernet MAC запрещена");
        
        if (ors.OPORA_CLOCK.ETH_CLK.MAN_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота на ГОСТТР52070-2003 разрешена");
             ETH_CLOCK |= 1 << 25;
        }
        else fprintf(fl, "\n Тактовая частота ГОСТТР52070-2003 запрещена");        

        if (ors.OPORA_CLOCK.ETH_CLK.SLEEP == slow_energy)
        {
             fprintf(fl, "\n Включен режим пониженного элекропотребления");
             ETH_CLOCK |= 1 << 26;
        }
        else fprintf(fl, "\n Выключен режим пониженного элекропотребления");  

        if (ors.OPORA_CLOCK.ETH_CLK.PHY_CLK_EN == On)
        {
             fprintf(fl, "\n Тактовая частота на Ethernet PHY разрешена");
             ETH_CLOCK |= 1 << 27;
        }
        else fprintf(fl, "\n Тактовая частота Ethernet PHY запрещена");
        
        switch (ors.OPORA_CLOCK.ETH_CLK.PHY_CLK_SEL)
        {
            case HSI_PHY:
                fprintf(fl, "\n Источник частоты для Ethernet Phy - HSI");
                ETH_CLOCK |= HSI << 28;
            break;
            
            case HSE_PHY:
                fprintf(fl, "\n Источник частоты для Ethernet Phy - HSE");
                ETH_CLOCK |= HSE << 28;
            break;
            
            case PLLCPUo_PHY:
                fprintf(fl, "\n Источник частоты для Ethernet Phy - PLLCPUo");
                ETH_CLOCK |= PLLCPUo << 28;
            break;          

            case HSE2:
                fprintf(fl, "\n Источник частоты для Ethernet Phy - HSE");
                ETH_CLOCK |= HSE2 << 28;
            break;           
        }
        
        fprintf(fl,"}");
        fclose(fl);
        
}
void GenerateHeader_CLK_File(struct OporaDataStruct ors, char* file)
{
    int i, j;
    unsigned int REG_SETTX=0;
    unsigned int REG_CLRTX=0;
    char* ports="ABCDEF";    

    strcat(file,"_clk.h"); 
    FILE* fl = fopen(file,"w");
  
        fprintf(fl,"//Init Function_clk \n");
        fprintf(fl,"void InitFunction_clk();");
        fclose(fl);
}