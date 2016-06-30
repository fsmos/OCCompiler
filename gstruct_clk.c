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