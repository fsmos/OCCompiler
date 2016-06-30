/**
*\file
*\brief Файл данных для генератора кода UART
*\author Шепелева Ирина
*\version 1.0
*\date 30 июня 2016 года
*В этом файле находится набор стрктур для генерации кода UART
*/
#ifndef STRUCT_UART_H
#define STRUCT_UART_H

struct uart_DR
{
    enum Switches uart_Enable_read;

};
struct uart_RSR_ECR
{
    enum Switches uart_read_OE;
    enum Switches uart_read_BE;
    enum Switches uart_read_PE;
     enum Switches uart_read_FE;
};
struct uart_FR
{
   enum Switches uart_read_RI;
   enum Switches uart_read_TXFE;
   enum Switches uart_read_RXFF;
   enum Switches uart_read_TXFF;
   enum Switches uart_read_RXFE;
   enum Switches uart_read_BUSY;
   enum Switches uart_read_DCD;
   enum Switches uart_read_DSR;
   enum Switches uart_read_CTS;
};
struct uart_ILPR
{
 unsigned char uart_ILPDVSR;
};
struct uart_IBRD
{
 unsigned short uart_BAUDDIV_INT;
};
struct uart_FBRD
{
unsigned char uart_BAUDDIV_FRAC;
};
enum WLENE
{
    bit_8=0b11,
    bit_7=0b10,
    bit_6=0b01,
    bit_5=0b00
};
enum STP2M
{
    stopbit1=0,
    stopbit2=1
};
enum RXIFLSELA
{
   bit_1div8=0b000,
   bit_1div4=0b001,
   bit_1div2=0b010,
   bit_3div4=0b011,
    bit_7div8=0b100
};

enum EPSS
{
    chet=1,
    nechet=0
};


struct uart_LCR_H
{
enum Switches uart_SPS;//Передача бита четности с фиксированным значением.0 – запрещена;
//1 – на месте бита четности передается инверсное значение бита EPS, оно же проверяется при приеме данных. (При EPS=0 на месте бита четности передается 1, при EPS=1 – передается 0).
//Значение бита SPS не играет роли в случае, если битом PEN формирование и проверка бита четности запрещено (Таблица 385).
enum WLENE  uart_WLEN;
enum Switches uart_FEN;
enum STP2M uart_STP2;
enum EPSS uart_EPS;
enum EPSS uart_PEN;
enum Switches uart_read_BRK;
};
struct uart_CR
{
enum Switches uart_CTSEn;
enum Switches uart_RTSEn;
enum Switches uart_Out2;
enum Switches uart_Out1;
enum Switches uart_RTS;
enum Switches uart_DTR;
enum Switches uart_RXE;
enum Switches uart_TXE;
enum Switches uart_LBE;
enum Switches uart_SIRLP;
enum Switches uart_SIREN;
enum Switches uart_UARTEN;
};
struct uart_IFLS
{
 enum RXIFLSELA uart_RXIFLSEL;
 enum RXIFLSELA uart_TXIFLSEL;
};
struct uart_IMSC
{
enum  Switches uart_OEIM;
enum  Switches uart_BEIM;
enum  Switches uart_PEIM;
enum  Switches uart_FEIM;
enum  Switches uart_RTIM;
enum  Switches uart_TXIM;
enum  Switches uart_RXIM;
enum  Switches uart_DSRMIM;
enum  Switches uart_DCDMIM;
enum  Switches uart_CTSMIM;
enum  Switches uart_RIMIM;
};
struct uart_RIS
{
enum Switches uart_read_OERIS;
enum Switches uart_read_BERIS;
enum Switches uart_read_PERIS;
enum Switches uart_read_FERIS;
enum Switches uart_read_RTRIS;
enum Switches uart_read_TXRIS;
enum Switches uart_read_RXRIS;
enum Switches uart_read_DSRRMIS;
enum Switches uart_read_DCDRMIS;
enum Switches uart_read_CTSRMIS;
enum Switches uart_read_RIRMIS;
};
struct uart_MIS
{
enum Switches uart_read_OEMIS;
enum Switches uart_read_BEMIS;
enum Switches uart_read_PEMIS;
enum Switches uart_read_FEMIS;
enum Switches uart_read_RTMIS;
enum Switches uart_read_TXMIS;
enum Switches uart_read_RXMIS;
enum Switches uart_read_DSRMMIS;
enum Switches uart_read_DCDMMIS;
enum Switches uart_read_CTSMMIS;
enum Switches uart_read_RIMMIS;
};
struct uart_ICR
{
enum Switches uart_write_OEIC;
enum Switches uart_write_BEIC;
enum Switches uart_write_PEIC;
enum Switches uart_write_FEIC;
enum Switches uart_write_RTIC;
enum Switches uart_write_TXIC;
enum Switches uart_write_RXIC;
enum Switches uart_write_DSRMIC;
enum Switches uart_write_DCDMIC;
enum Switches uart_write_CTSMIC;
enum Switches uart_write_RIMIC;
};
struct uart_DMACR
{
 enum Switches uart_DMAONERR;
  enum Switches uart_TXDMAE;
   enum Switches uart_RXDMAE;
};
struct uart_TCR
{
 enum Switches uart_SIRTEST;
  enum Switches uart_TESTFIFO;
   enum Switches uart_ITEN;
};
struct uart_global
{
  struct uart_DR DRR;
  struct uart_RSR_ECR RSRECRR;
  struct uart_FR FRR;
  struct uart_ILPR ILPRR;
  struct uart_IBRD IBRDD;
  struct uart_FBRD FBRDD;
  struct uart_LCR_H LCRH;
  struct uart_CR CRR;
  struct uart_IFLS IFLSS;
  struct uart_IMSC IMCSS;
  struct uart_RIS RISI;
  struct uart_MIS MISI;
  struct uart_ICR ICRI;
  struct uart_DMACR DMARKI;
  struct uart_TCR TCRKI;
};

#endif // STRUCT_UART_H
