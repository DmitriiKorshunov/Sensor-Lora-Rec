#ifndef Grinterface_H
#define Grinterface_H
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "heltec.h"




class Grinterface
{
public:    
void StartSysGr (); // Графика для старта системы
void Ready();       // Графика для подтверждения работы системы
void WriteDataOn(int n, String DataLoraRX); // Вывод  данных по шаблону
void WriteService(char Mes); // Вывод  данных 
int Keyboardcheck(int PinROW1,int PinROW2, int PinROW3, int PinROW4, int PinCOL1, int PinCOL2, int PinCOL3, int PinCOL4); // Обработка клавиатуры ({пины выхода}, {пины входа})
void Menu(int val);
void Ch(int nd);
};



#endif