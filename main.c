/* 
 * File:   main.c
 * Author: Гусенков С.В
 *
 * Created on 8 декабря 2015 г., 15:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_code.h"
#include "gstruct.h"
#include <time.h>
#define GPS_version "V0.2 Beta"
/*
 * 
 */

void DelRash(char *out, char* in)
{
    int i;
    for(i=0; i<strlen(in);i++)
    { 
        if(in[i]=='.') 
        {
         out[i]=0;
            break;
        }
        out[i]=in[i];
       
    }
}
int main(int argc, char** argv) {

    if(argc==2)
    {
        char filen[200];
        FILE* fl = fopen(argv[1],"r");
        struct OporaDataStruct ors;
        fread(&ors,sizeof(ors),1,fl);
        //printf("%d",ors.Er1.el1.ExampleParamet);
        DelRash(filen,argv[1]);
        GenerateC_Gpio_File(ors,filen);
        DelRash(filen,argv[1]);
        GenerateC_CLK_File(ors, filen);
        DelRash(filen,argv[1]);
        GenerateC_SSP_File(ors, filen);
        DelRash(filen,argv[1]);
        GenerateC_PVDCS_File(ors, filen);
        DelRash(filen,argv[1]);
        
        GenerateHeader_GPIO_File(ors,filen); 
        DelRash(filen,argv[1]);       
        GenerateHeader_CLK_File(ors, filen);
        DelRash(filen,argv[1]);
        GenerateHeader_SSP_File(ors, filen);
        DelRash(filen,argv[1]);
        GenerateHeader_PVDCS_File(ors, filen);
        fclose(fl);
    }
    // printf(argv[0]);
    //printf("%d",argc);
    return 0;
    
}

