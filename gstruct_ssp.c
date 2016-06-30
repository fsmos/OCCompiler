#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_code.h"
#include <time.h>
#include "gstruct.h"
#define GPS_version_ssp "V0.2 Beta"

void GenerateC_SSP_File(struct OporaDataStruct ors, char* file)
{
    char date[100];
        char filec[200];
        int i, j;
        unsigned int SSPx_CR0 = 0,
                     SSPx_CR1 = 0,
                     SSPx_DR = 0,
                     SSPx_SR = 0,
                     SSPx_CPSR = 0,
                     SSPx_IMSC = 0,
                     SSPx_RIS = 0,
                     SSPx_MIS = 0,
                     SSPx_ICR = 0,
                     SSPx_DMACR = 0;


        strcpy(filec,file);
        strcat(filec,"_ssp.h");
        strcat(file,"_ssp.c"); 
        FILE* fl = fopen(file,"w");
        struct tm* tkm;
        const time_t timer=time(NULL);
        tkm=localtime(&timer);
        strftime(date, 100,"%d.%m.%Y %H:%M:%S", tkm);
        fprintf(fl, "/*!\n\\file\n\\brief Заголовочный файл для настройки SSP\n\\author Milovidov A.E.\n\\Version %s \n\\date %s\n*/\n", GPS_version_ssp,date);
        fprintf(fl,"#include \"");
         strcpy(filec,strstr(filec,"\\"));
          while(strchr(filec,'\\'))
         {
             strcpy(filec,filec+1);
         }
        fprintf(fl,filec);
        fprintf(fl,"\"");
        fprintf(fl,"//Init Function_ssp \n");
        fprintf(fl,"void InitFunction_ssp() {");
        fprintf(fl, "\n");
        
                
        
        for (i=0; i<4; i++)
        {
          fprintf(fl, "/*!\n \\breif SSP%u\n",i);
        switch (ors.PER_SSP[i].SSP_CR0R.DDS)
        {
            case RSRV1:
            SSPx_CR0 |= 0b0000;
            fprintf(fl, "/*!\nРазмер слова данных: Reserved");
            break;
            
            case RSRV2:
            SSPx_CR0 |= 0b0001;
            fprintf(fl, "/*!\nРазмер слова данных: Reserved");
            break;
            
            case RSRV3:
            SSPx_CR0 |= 0b0010;
            fprintf(fl, "/*!\nРазмер слова данных: Reserved");
            break;
            
            case bit4:
            SSPx_CR0 |= 0b0011;
            fprintf(fl, "/*!\nРазмер слова данных: 4 бита");
            break;
            
            case bit5:
            SSPx_CR0 |= 0b0100;
            fprintf(fl, "/*!\nРазмер слова данных: 5 бит");
            break;
            
            case bit6:
            SSPx_CR0 |= 0b0101;
            fprintf(fl, "/*!\nРазмер слова данных: 6 бит");
            break;
            
            case bit7:
            SSPx_CR0 |= 0b0110;
            fprintf(fl, "/*!\nРазмер слова данных: 7 бит");
            break;
            
            case bit8:
            SSPx_CR0 |= 0b0111;
            fprintf(fl, "/*!\nРазмер слова данных: 8 бит");
            break;
            
            case bit9:
            SSPx_CR0 |= 0b1000;
            fprintf(fl, "/*!\nРазмер слова данных: 9 бит");
            break;
            
            case bit10:
            SSPx_CR0 |= 0b1001;
            fprintf(fl, "/*!\nРазмер слова данных: 10 бит");
            break;
            
            case bit11:
            SSPx_CR0 |= 0b1010;
            fprintf(fl, "/*!\nРазмер слова данных: 11 бит");
            break;
            
            case bit12:
            SSPx_CR0 |= 0b1011;
            fprintf(fl, "/*!\nРазмер слова данных: 12 бит");
            break;
            
            case bit13:
            SSPx_CR0 |= 0b1100;
            fprintf(fl, "/*!\nРазмер слова данных: 13 бит");
            break;
            
            case bit14:
            SSPx_CR0 |= 0b1101;
            fprintf(fl, "/*!\nРазмер слова данных: 14 бит");
            break;
            
            case bit15:
            SSPx_CR0 |= 0b1110;
            fprintf(fl, "/*!\nРазмер слова данных: 15 бит");
            break;
            
            case bit16:
            SSPx_CR0 |= 0b1111;
            fprintf(fl, "/*!\nРазмер слова данных: 16 бит");
            break;
        }
        
        switch (ors.PER_SSP[i].SSP_CR0R.FRF)
        {
            case SPI_M:
            SSPx_CR0 |= 0b00<<4;
            fprintf(fl, "/*!\nФормат информационного кадра: протокол SPI фирмы Motorola");
            break;
            
            case SSI_TI:
            SSPx_CR0 |= 0b01<<4;
            fprintf(fl, "/*!\nФормат информационного кадра: протокол SSI фирмы Texas Instruments");
            break;
            
            case MW_NS:
            SSPx_CR0 |= 0b10<<4;
            fprintf(fl, "/*!\nФормат информационного кадра: протокол Microwire фирмы National Semiconductor");
            break;
            
            case RSRV:
            SSPx_CR0 |= 0b11<<4;
            fprintf(fl, "/*!\nФормат информационного кадра: Reserved");
            break;
        }
        
        if (ors.PER_SSP.SSP_CR0R.SPO == On)
        {
            fprintf(fl, "\nПолярность  сигнала  SSPCLK включена");
            SSPx_CR0 |= 1<<6;
        }
        else fprintf(fl, "\nПолярность  сигнала  SSPCLK выключена");

        
        if (ors.PER_SSP.SSP_CR0R.SPH == On)
        {
            fprintf(fl, "\nФаза  сигнала  SSPCLK включена");
            SSPx_CR0 |= 1<<7;
        }
        else fprintf(fl, "\nФаза  сигнала  SSPCLK выключена");
        
        
        if (ors.PER_SSP.SSP_CPR.LBM == On)
        {
            fprintf(fl, "\nТестирование по шлейфу: выход  регистра  сдвига  передатчика  соединен  сo входом регистра сдвига приемника");
            SSPx_CR1 |= 1<<0; 
        }
        else fprintf(fl, "\nТестирование по шлейфу: нормальный режим работы приемопередатчика");
        
    
        if (ors.PER_SSP.SSP_CPR.SSE == On)
        {
            fprintf(fl, "\nРазрешение работы приемопередатчика: работа разрешена");
            SSPx_CR1 |= 1<<1;
        }
        else fprintf(fl, "\nРазрешение работы приемопередатчика: работа запрещена");
        
        if (ors.PER_SSP.SSP_CPR.MS == On)
        {
            fprintf(fl, "\nВыбор ведущего или ведомого режима работы: ведомый модуль");
            SSPx_CR1 |= 1<<2;
        }
        else fprintf(fl, "\nВыбор ведущего или ведомого режима работы:  ведущий модуль");
        
        if (ors.PER_SSP.SSP_CPR.SOD == On)
        {
           fprintf(fl, "\nЗапрет выходных линий в режиме ведомого устройства: управление  линией  SSPTXD  в  ведомом  режиме запрещена");
            SSPx_CR1 |= 1<<3; 
        }
        else fprintf(fl, "\nЗапрет выходных линий в режиме ведомого устройства: управление  линией  SSPTXD  в  ведомом  режиме разрешена");
        
        if (ors.PER_SSP.SSP_DMACRR.RXDMAE == On)
        {
            fprintf(fl, "\nИспользование DMA при приеме: разрешено  формирование  запросов  DMA  для обслуживания буфера FIFO приемника");
            SSPx_DMACR |= 1<<0;
        }
        else fprintf(fl, "\nИспользование DMA при приеме: запрещено  формирование  запросов  DMA  для обслуживания буфера FIFO приемника");
        
        if (ors.PER_SSP.SSP_DMACRR.TXDMAE == On)
        {
            fprintf(fl, "\nИспользование DMA при передаче: разрешено  формирование  запросов  DMA  для обслуживания буфера FIFO приемника");
            SSPx_DMACR |= 1<<1;
        }
        else fprintf(fl, "\nИспользование DMA при передаче: запрещено  формирование  запросов  DMA  для обслуживания буфера FIFO передатчика");
        
        fprintf(fl, "*/\n"); 
         fprintf(fl,"SPI%c->SSPx_CR0=0x%08x;\n", i, SSPx_CR0);
         fprintf(fl,"SPI%c->SSPx_CR1=0x%08x;\n", i, SSPx_CR1);
         fprintf(fl, "SPI%c->SSPx_DMACR=0x%08x;\n", i, SSPx_DMACR);
         fprintf(fl,"\n");
        }
        fprintf(fl,"}");
        fclose(fl);
        }
    
void GenerateHeader_SSP_File(struct OporaDataStruct ors, char* file)
{
    int i, j;
    unsigned int REG_SETTX=0;
    unsigned int REG_CLRTX=0;
    char* ports="ABCDEF";    

    strcat(file,"_ssp.h"); 
    FILE* fl = fopen(file,"w");
  
        fprintf(fl,"//Init Function_ssp \n");
        fprintf(fl,"void InitFunction_ssp();");
        fclose(fl);
}