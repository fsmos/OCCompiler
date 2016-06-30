/**
*\file
*\brief Файл данных для генератора кода GPIO
*\author Ярошенко Артур
*\version 1.0
*\date 23 Декабря 2015 года
*В этом файле находится набор стрктур для генерации кода GPIO
*/
#ifndef STRUCT_GPIO
#define STRUCT_GPIO

enum Switches
{
    On,
    Off
};
enum Forward
{
    Input,
    Output
};
enum PortFunction
{
    port1,
    mainfuction,
    alternain_function,
    refrange_function
};
enum PortD_A
{
    analog,
    digital
};
struct PortXPull
{
    enum Switches port_up;
    enum Switches port_down;
};

enum Control_type
{
    Controls,
    Opendrain
};

struct PortPD
{
    enum Switches Shmidt_port;
    enum Control_type control;
};
enum PortX_PWR
{
   reserved1,
    slow_front,
    fast_front,
    max_fast_front
};
struct port_CMD
{
    enum Switches CMD_ENABLE;
    enum Switches CMD_DISABLE;
};


/**
*\brief Структура вывода для микроконтроллера
*Эта структура предназначена для управления выводом микроконтроллера
*/
struct GPIOPin
{
 enum Switches RXTX; ///< управление портом
 enum Forward OE; ///< режим работы вывода порта
 enum PortFunction Function; ///< режим работы вывода порта
 enum PortD_A Analog; ///< режим работы вывода порта
 struct PortXPull PULL; ///< подтяжка порта
 struct PortPD PD; ///< режим работы выходого драйвера
 enum PortX_PWR PWR; ///< режим работы выходного фильтра
 enum Switches GFEN;///< режим работы входного фильтра
 struct port_CMD PCMD;///< команды управления




};
/**
*\brief Настройка порта Gpio
*Эта структура предназначена для управления портом микроконтроллера
*/
struct GPIOStruct
{
struct GPIOPin Pin[16]; ///< вывод микроконтроллера
};

#endif // STRUCT_GPIO

