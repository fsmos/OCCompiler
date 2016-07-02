/**
*\file
*\brief Файл данных для генератора кода настроек детектора напряжение
*\author Евгений КОсов
*\version 1.0
*\date 1 июля 2016 года
*В этом файле находится набор стрктур для генерации кода настроек детектора напряжения
*/

#ifndef STRUCT_PVDCS_H
#define STRUCT_PVDCS_H

enum result
{
    higher,
    lower
};

struct PVDCS_GLOBAL
{
    enum Switches PVDBEN;
    enum Switches INV;
    enum Switches INVB;
    enum Switches IEPVD;
    enum Switches IEPVBD;
    enum result PVD;
    enum result PVBD;
    unsigned int PLS;
    unsigned int PBLS;
    enum Switches PVDEN;

};

#endif // STRUCT_PVDCS_H
