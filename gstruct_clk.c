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
 
        if (ors.OPORA_CLOCK.CPU_CLK.CPU_C1_SEL == HSI)
        {
            fprintf(fl, )
            CPU_CLOCK |= 0b00;
        }
 
        if (ors.OPORA_CLOCK.CPU_CLK.CPU_C2_SEL == PLLCPUo)
        {
            CPU_CLOCK |= 
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