#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_code.h"
#include <time.h>
#include "gstruct.h"
#define GPS_version_pvdcs "V0.2 Beta"

void GenerateC_PVDCS_File(struct OporaDataStruct ors, char* file)
{
    char  date[100];
    char filec[200];
    int i, j;
    unsigned int PVDCS;
    
        strcpy(filec,file);
        strcat(filec,"_pvdcs.h");
        strcat(file,"_pvdcs.c"); 
        FILE* fl = fopen(file,"w");
        struct tm* tkm;
        const time_t timer=time(NULL);
        tkm=localtime(&timer);
        strftime(date, 100,"%d.%m.%Y %H:%M:%S", tkm);
        fprintf(fl, "/*!\n\\file\n\\brief Заголовочный файл настройки детектора напряжения\n\\author Cosov O.O\n\\Version %s \n\\date %s\n*/\n", GPS_version_pvdcs,date);
        fprintf(fl,"#include \"");
         strcpy(filec,strstr(filec,"\\"));
          while(strchr(filec,'\\'))
         {
             strcpy(filec,filec+1);
         }
        fprintf(fl,filec);
        fprintf(fl,"\"");
        fprintf(fl,"//Init Function_pvdcs \n");
        fprintf(fl,"void InitFunction_pvdcs() {");
        fprintf(fl, "\n");        
        fprintf(fl, "/*!\n \\breif PVDCS\n");


        fprintf(fl, "\n Регистр детектора напряжения питания");
        
        if (ors.PVDCS.PVDEN == On)
        {
             fprintf(fl, "\n Датчик напряжения питания Ucc включен");
             PVDCS |= 1;
        }
        else fprintf(fl, "\n Датчик напряжения питания Ucc выключен");
        

        fprintf(fl, "\n уровень напряжения для сравнения с напряжением батарейного питания - %d", ors.PVDCS.PBLS);
        PVDCS |= ors.PVDCS.PBLS << 1;
        
        fprintf(fl, "\n Уровень напряжения для сравнения с напряжением основного пиания - %d", ors.PVDCS.PLS);
        PVDCS |= ors.PVDCS.PLS << 3;
        
        if (ors.PVDCS.PVBD == lower)
        {
             fprintf(fl, "\n Напряжение питания меньше чем уровень задаваемый PBLS");
             PVDCS |= 1 << 6;
        }
        else fprintf(fl, "\n Напряжение питания больше чем уровень задаваемый PBLS");
        
        if (ors.PVDCS.PVD == lower)
        {
             fprintf(fl, "\n Напряжение питания меньше чем уровень задаваемый PLS");
             PVDCS |= 1 << 7;
        }
        else fprintf(fl, "\n Напряжение питания больше чем уровень задаваемый PLS");
        
        if (ors.PVDCS.IEPVBD == On)
        {
             fprintf(fl, "\n Прерывание датчика PVBD разрешено");
             PVDCS |= 1 << 8;
        }
        else fprintf(fl, "\n Прерывание датчика PVBD запрещено"); 
        
        if (ors.PVDCS.IEPVD == On)
        {
             fprintf(fl, "\n Прерывание датчика PVD разрешено");
             PVDCS |= 1 << 9;
        }
        else fprintf(fl, "\n Прерывание датчика PVD запрещено"); 
        
        if (ors.PVDCS.INVB == On)
        {
             fprintf(fl, "\n На датчике PVBD присутствует инверсия");
             PVDCS |= 1 << 10;
        }
        else fprintf(fl, "\n На датчике PVBD отсутствует инверсия"); 
        
        if (ors.PVDCS.INV == On)
        {
             fprintf(fl, "\n На датчике PVD присутствует инверсия");
             PVDCS |= 1 << 11;
        }
        else fprintf(fl, "\n На датчике PVD отсутствует инверсия");   

        if (ors.PVDCS.PVDBEN == On)
        {
             fprintf(fl, "\n Датчик напряжения питания Bucc включен");
             PVDCS |= 1 << 12;
        }
        else fprintf(fl, "\n Датчик напряжения питания Bucc выключен");      
} 



void GenerateHeader_PVDCS_File(struct OporaDataStruct ors, char* file)
{
    int i, j;
    unsigned int REG_SETTX=0;
    unsigned int REG_CLRTX=0;
    char* ports="ABCDEF";    

    strcat(file,"_clk.h"); 
    FILE* fl = fopen(file,"w");
  
        fprintf(fl,"//Init Function_pvdcs \n");
        fprintf(fl,"void InitFunction_pvdcs();");
        fclose(fl);
}