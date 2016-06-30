/* 
 * File:   main.c
 * Author: Ярошенко Артур
 *
 * Created on 8 декабря 2015 г., 15:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_code.h"
#include <time.h>
#include "gstruct.h"
#define GPS_version "V0.2 Beta"

void GenerateC_Gpio_File(struct OporaDataStruct ors, char* file)
{
    char date[100];
        char filec[200];
        int i, j;
        char* ports="ABCDEF";
        strcpy(filec,file);
        strcat(filec,"_gpio.h");
        strcat(file,"_gpio.c"); 
        FILE* fl = fopen(file,"w");
        struct tm* tkm;
        const time_t timer=time(NULL);
        tkm=localtime(&timer);
        strftime(date, 100,"%d.%m.%Y %H:%M:%S", tkm);
        fprintf(fl, "/*!\n\\file\n\\brief Заголовочный файл инициализации перефирии\n\\author Gusenkov S.V.\n\\Version %s \n\\date %s\n*/\n", GPS_version,date);
        fprintf(fl,"#include \"");
         strcpy(filec,strstr(filec,"\\"));
          while(strchr(filec,'\\'))
         {
             strcpy(filec,filec+1);
         }
        fprintf(fl,filec);
        fprintf(fl,"\"");
        fprintf(fl,"//Init Function_GPIO \n");
        fprintf(fl,"void InitFunction_GPIO() {");
        fprintf(fl, "\n");
        
        for (i=0; i<6; ++i)
        {
            unsigned int REG_RXTX=0;
            unsigned int REG_OE=0;
            unsigned int REG_FUNC=0;
            unsigned int REG_ANALOG=0;
            unsigned int REG_PULL=0;  
            unsigned int REG_PD=0;
            unsigned int REG_PWR=0;
            unsigned int REG_GFEN=0;
        fprintf(fl, "/*!\n \\breif PORT%c\n", ports[i]);  
            for (j=0; j<16; ++j)
            {
                fprintf(fl,"Пин %d <br>\n", j);
             if (ors.GPIOPort[i].Pin[j].RXTX==On) 
             {
              REG_RXTX |= 1<<j; 
              fprintf(fl, "Состояние: включено\n");
             } 
             else
             {
                 fprintf(fl, "Состояние: выключено\n");
             }
             if (ors.GPIOPort[i].Pin[j].OE==Output)
             {
                REG_OE |= 1<<j; 
                fprintf(fl, "Направление: выход\n");
             }
             else 
             {
                fprintf(fl, "Направление: вход\n"); 
             }
          switch (ors.GPIOPort[i].Pin[j].Function)
        {
            case port1:
            fprintf(fl, "Режим работы вывода порта: порт\n");
            break;
            case mainfuction:
            fprintf(fl, "Режим работы вывода порта: основная функция\n"); 
            REG_FUNC |= 1<<(2*j);
            break;
            case alternain_function:
            fprintf(fl, "Режим работы вывода порта: альтернативная функция\n");
            REG_FUNC |= 2<<(2*j);
            break;
            case refrange_function:
            fprintf(fl, "Режим работы вывода порта: переопределенная функция\n");
            REG_FUNC |= 3<<(2*j);
            break;   
        }     
          if (ors.GPIOPort[i].Pin[j].Analog==digital)
          {
              fprintf(fl, "Вывод порта: цифровой\n");
              REG_ANALOG |= 1<<j;
          }
          else 
          {
              fprintf(fl, "Вывод порта: аналоговый\n");
          }
          if (ors.GPIOPort[i].Pin[j].PULL.port_down==On)
          {
              fprintf(fl, "Подтяжка к нулю включена\n");
              REG_PULL |= 1<<j;
          }
          if (ors.GPIOPort[i].Pin[j].PULL.port_up==On)
          {
              fprintf(fl, "Подтяжка к питанию включена\n");
              REG_PULL |= (1<<(j+16));
          }
          if (ors.GPIOPort[i].Pin[j].PD.control==Opendrain)
          {
              fprintf(fl, "Режим работы вывода: открытый сток\n");
              REG_PD |= 1<<j;
          }
          else
          {
              fprintf(fl, "Режим работы вывода: управляемый драйвер\n");  
          }
          if (ors.GPIOPort[i].Pin[j].PD.Shmidt_port==On)
          {
              fprintf(fl, "Триггер Шмитта: включен\n");
              REG_PD |= 1<<(j+16);
          }
          else 
          {
            fprintf(fl, "Триггер Шмитта: выключен\n");  
          }
          switch (ors.GPIOPort[i].Pin[j].PWR)
          {
              case reserved1: 
                  fprintf(fl, "Режим работы порта: зарезервировано\n");
                  break;
              case slow_front: 
                  fprintf(fl, "Режим работы порта: медленный фронт\n");
                  REG_PWR |= 1<<(2*j);
                  break;
              case fast_front: 
                  fprintf(fl, "Режим работы порта: быстрый фронт\n");
                  REG_PWR |= 2<<(2*j);
                  break;
              case max_fast_front:
                  fprintf(fl, "Режим работы порта: максимально быстрый фронт\n");
                  REG_PWR |= 3<<(3*j);
                  break;
          }
          if (ors.GPIOPort[i].Pin[j].GFEN==On)
          {
              fprintf(fl, "Входной фильтр : включен\n");
              REG_GFEN |= 1<<j;
          }
          else 
          {
              fprintf(fl, "Входной фильтр : выключен\n");
          }
          }
         fprintf(fl, "*/\n"); 
         fprintf(fl,"PORT%c->RXTX=0x%08x;\n", ports[i], REG_RXTX);
         fprintf(fl,"PORT%c->OE=0x%08x;\n", ports[i], REG_OE);
         fprintf(fl, "PORT%c->FUNC=0x%08x;\n", ports[i], REG_FUNC);
         fprintf(fl, "PORT%c->ANAlOG=0x%08x;\n", ports[i], REG_ANALOG);
         fprintf(fl, "PORT%c->PULL=0x%08x;\n", ports[i], REG_PULL);
         fprintf(fl, "PORT%c->PD=0x%08x;\n", ports[i], REG_PD);
         fprintf(fl, "PORT%c->PWR=0x%08x;\n", ports[i], REG_PWR);
         fprintf(fl, "PORT%c->GFEN=0x%08x;\n", ports[i], REG_GFEN);
         fprintf(fl,"\n");
         
        }
        //fprintf(fl,"Example=%d;",ors.Er1.el1.ExampleParamet);
        fprintf(fl,"}");
        fclose(fl);
        
}
void GenerateHeader_GPIO_File(struct OporaDataStruct ors, char* file)
{
    int i, j;
    unsigned int REG_SETTX=0;
    unsigned int REG_CLRTX=0;
    char* ports="ABCDEF";    

    strcat(file,"_gpio.h"); 
    FILE* fl = fopen(file,"w");
    for (i=0; i<6; ++i)
    {
        for (j=0; j<16; ++j)
        {
            if (ors.GPIOPort[i].Pin[j].PCMD.CMD_ENABLE==On)
            {
                REG_SETTX=1<<j;
                fprintf(fl, "#define PORT%c%d_ENABLE PORT%c->SETTX=0x%08x; /*!< Включить порт %c%d*/\n", ports[i], j, ports[i], REG_SETTX, ports[i], j);
            }
            if (ors.GPIOPort[i].Pin[j].PCMD.CMD_ENABLE==On)
            {
                REG_CLRTX=1<<j;
                fprintf(fl, "#define PORT%c%d_DISABLE PORT%c->CLRTX=0x%08x; /*!< Выключить порт %c%d*/\n", ports[i], j, ports[i], REG_CLRTX, ports[i], j);               
            }
        }
        fprintf(fl, "\n"); 
    }
        fprintf(fl,"//Init Function_GPIO \n");
        fprintf(fl,"void InitFunction_GPIO();");
        fclose(fl);
}