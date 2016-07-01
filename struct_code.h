#ifndef STRUCT_CODE_H
#define STRUCT_CODE_H
/**
*\file
*\brief Файл данных для генератора кода
*\author Гусенков.С.В
*\version 1.0
*\date 23 Декабря 2015 года
*В этом файле находится набор стрктур для генерации кода
*/

#include "struct_gpio.h" ///< Артур
#include "struct_clk.h" ///< Артур
#include "struct_timer.h" ///< Миша
#include "struct_uart.h" ///< Ира
#include "struct_ssp.h" ///< Леша
/**
*\brief Настройка опоры
*Эта структура предназначена для настройки опоры микроконтроллера 1986VE1T
*/
struct OporaDataStruct
{
struct GPIOStruct GPIOPort[6]; ///< настройка портов микроконтроллера
struct CLK_GLOBAL OPORA_CLOCK;
//struct TIMER_Global PER_TIMER[4];
struct uart_global PER_UART[2];
struct global_SSP PER_SSP[3];
};

#endif // STRUCT_CODE_H

