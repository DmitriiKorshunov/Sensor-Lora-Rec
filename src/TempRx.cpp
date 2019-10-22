#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "heltec.h"
#include "Grinterface.h"
#define BAND    433E6   //you can set band here directly,e.g. 868E6,915E6

/*
1) Var DMax - количество девайсов в системе
*/

const int Dmax = 2;
const int buttonPin = 27;     // номер входа, подключенный к кнопке
int buttonState = 0;         // переменная для хранения состояния кнопки
int n=1;
Grinterface grint; // Класс библиотеки графического интерфейса







void setup()
{
grint.StartSysGr();
Serial.begin(115200);
Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
grint.Ready();
}

void loop() 
{
  int val=grint.Keyboardcheck(36,37,38,39,12,33,0,2);
  grint.Ch(val);
//grint.Keyboardcheck();
}

