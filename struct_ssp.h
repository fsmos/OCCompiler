/**
*\file
*\brief Файл данных для генератора кода SSP
*\author Меловидов Алексей
*\version 1.0
*\date 30 июня 2016 года
*В этом файле находится набор стрктур для генерации кода SSP
*/

#ifndef STRUCT_SSP_H
#define STRUCT_SSP_H

enum SSP_FRF
{
    SPI_M = 0b00,
    SSI_TI = 0b01,
    MW_NS = 0b10,
    RSRV = 0b11
};

enum SSP_DSS
{
    RSRV1 = 0b0000,
    RSRV2 = 0b0001,
    RSRV3 = 0b0010,
    bit4 = 0b0011,
    bit5 = 0b0100,
    bit6 = 0b0101,
    bit7 = 0b0110,
    bit8 = 0b0111,
    bit9 = 0b1000,
    bit10 = 0b1001,
    bit11 = 0b1010,
    bit12 = 0b1011,
    bit13 = 0b1100,
    bit14 = 0b1101,
    bit15 = 0b1110,
    bit16 = 0b1111
};

struct SSP_CR0
{
    unsigned char SCR;
    enum SSP_DSS DDS;
    enum Switches SPH;
    enum Switches SPO;
    enum SSP_FRF FRF;
};

struct SSP_CR1
 {
    enum Switches SOD;
    enum Switches MS;
    enum Switches SSE;
    enum Switches LBM;
};

struct SSP_DR
{
    enum Switches SSP_read_DATA;
};

struct SSP_SR
{
    enum Switches read_BSY;
    enum Switches read_RFF;
    enum Switches read_RNE;
    enum Switches read_TNF;
    enum Switches read_TFE;
};

struct SSP_CPSR
{
    unsigned char CPSDVSR;
};

struct SSP_IMSC
{
    enum Switches TXIM;
    enum Switches RXIM;
    enum Switches RTIM;
    enum Switches RORIM;
};

struct SSP_RIS
{
    enum Switches read_TXRIS;
    enum Switches read_RXRIS;
    enum Switches read_RTRIS;
    enum Switches read_RORRIS;
};

struct SSP_MIS
{
   enum Switches read_TXMIS;
   enum Switches read_RXMIS;
   enum Switches read_RTMIS;
   enum Switches read_RORMIS;
};

struct SSP_ICR
{
   enum Switches write_RTIC;
   enum Switches write_RORIC;
};

struct SSP_DMACR
{
   enum Switches TXDMAE;
   enum Switches RXDMAE;
};

struct global_SSP
{
  struct SSP_CR0 SSP_CR0R;
  struct SSP_CR1 SSP_CPR;
  struct SSP_DR SSP_DRR;
  struct SSP_SR SSP_SRR;
  struct SSP_CPSR SSP_CPSRR;
  struct SSP_IMSC SSP_IMSCR;
  struct SSP_RIS SSP_RISR;
  struct SSP_MIS SSP_MISR;
  struct SSP_ICR SSP_ICRR;
  struct SSP_DMACR SSP_DMACRR;
};

#endif // STRUCT_SSP_H
