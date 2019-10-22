#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "Grinterface.h"
Grinterface GR;
LiquidCrystal_I2C lcd(0x27,16,2); 
String LoRaData;

    
int val; 

void Grinterface::StartSysGr() // Графика для старта системы
{
Wire.begin(22, 13); 
lcd.init();
lcd.clear();
lcd.backlight();
//int a=0;
/*while (a!=16)
{
lcd.setCursor(a,0);
lcd.print("-");
lcd.setCursor(a,1);
lcd.print("-");
delay (300);
a++;
}
*/
lcd.clear();
lcd.setCursor(3,0);
lcd.print("S");
delay (300);
lcd.setCursor(4,0);
lcd.print("m");
delay (300);
lcd.setCursor(5,0);
lcd.print("a");
delay (300);
lcd.setCursor(6,0);
lcd.print("r");
delay (300);
lcd.setCursor(7,0);
lcd.print("t");
delay (300);
lcd.setCursor(9,1);
lcd.print("G");
delay (300);
lcd.setCursor(10,1);
lcd.print("l");
delay (300);
lcd.setCursor(11,1);
lcd.print("o");
delay (300);
lcd.setCursor(12,1);
lcd.print("w");
delay (1000);
}


void Grinterface::Ready() // Графика для подтверждения старта системы
{
lcd.clear();
lcd.setCursor(5,0);
lcd.print("System");
lcd.setCursor(4,1);
lcd.print("is ready");
delay(1000);
}

// Вывод  данных по шаблону
void Grinterface::WriteDataOn(int n,String DataLoraRX)
{
lcd.clear();
lcd.setCursor(0,0);
String CAMINFO ("----" + String (n) + " camera----");
lcd.println(CAMINFO);
lcd.setCursor(0,1);
lcd.print(DataLoraRX);
delay(1000);    
}

// Вывод данных
void  Grinterface::WriteService(char Mes) 
{
lcd.clear();
lcd.setCursor(0,0);
lcd.println(String(Mes));
}


int Grinterface::Keyboardcheck( int PinROW1,int PinROW2, int PinROW3, int PinROW4, int PinCOL1, int PinCOL2, int PinCOL3, int PinCOL4) // Обработка клавиатуры (пины выхода, пины входа)
{   
const int del=100;             
 
pinMode(PinCOL1, OUTPUT);
pinMode(PinCOL2, OUTPUT);
pinMode(PinCOL3, OUTPUT);
pinMode(PinCOL4, OUTPUT);
pinMode(PinROW1, INPUT);
pinMode(PinROW2, INPUT);
pinMode(PinROW3, INPUT);
pinMode(PinROW4, INPUT);
digitalWrite(PinCOL1, LOW);
digitalWrite(PinCOL2, LOW);
digitalWrite(PinCOL3, LOW);
digitalWrite(PinCOL4, LOW);
// Первая строчка
digitalWrite(PinCOL1, HIGH);
//1
if (analogRead(PinROW1)==4095)
{
val=1;
lcd.clear();
lcd.print(val);
}
delay(del);
//2
if (analogRead(PinROW2)==4095)
{
val=2;
lcd.clear();
lcd.print(val);
}
delay(del);
//3
if (analogRead(PinROW3)==4095)
{
val=3;
lcd.clear();
lcd.print(val);
}
delay(del);
//A
if (analogRead(PinROW4)==4095)
{
val=100;
lcd.clear();
lcd.print("A");
}
delay(del);

// Вторая строчка

digitalWrite(PinCOL1, LOW);
digitalWrite(PinCOL2, HIGH);
//4
if (analogRead(PinROW1)==4095)
{
val=4;
lcd.clear();
lcd.print(val);
}
delay(del);
//5
if (analogRead(PinROW2)==4095)
{
val=5;
lcd.clear();
lcd.print(val);
}
delay(del);
//6
if (analogRead(PinROW3)==4095)
{
val=6;
lcd.clear();
lcd.print(val);
}
delay(del);

//B
if (analogRead(PinROW4)==4095)
{
val=200;
lcd.clear();
lcd.print("B");
}
delay(del);

// Третья строчка

digitalWrite(PinCOL2, LOW);
digitalWrite(PinCOL3, HIGH);
//7
if (analogRead(PinROW1)==4095)
{
val=7;
lcd.clear();
lcd.print(val);
}
delay(del);
//8
if (analogRead(PinROW2)==4095)
{
val=8;
lcd.clear();
lcd.print(val);
}
delay(del);
//9
if (analogRead(PinROW3)==4095)
{
val=9;
lcd.clear();
lcd.print(val);
}
delay(del);

//С
if (analogRead(PinROW4)==4095)
{
val=300;
lcd.clear();
lcd.print("С");
}
delay(del);
// Четвертая строчка

digitalWrite(PinCOL3, LOW);
digitalWrite(PinCOL4, HIGH);
//*
if (analogRead(PinROW1)==4095)
{
val=400;
lcd.clear();
lcd.print("*");
}
delay(del);
//0
if (analogRead(PinROW2)==4095)
{
val=0;
lcd.clear();
lcd.print(val);
}
delay(del);
//#
if (analogRead(PinROW3)==4095)
{
val=500;
lcd.clear();
lcd.print("#");
}
delay(del);

//D
if (analogRead(PinROW4)==4095)
{
val=600;
lcd.clear();
lcd.print("D");
}
delay(del);
return val;

}

void Grinterface::Ch(int nd)
{ 
  LoRa.setSyncWord(nd);
  int packetSize = LoRa.parsePacket();
  if (packetSize) 
    {
      while (LoRa.available()) 
        {
          LoRaData = LoRa.readString ();
          GR.WriteDataOn(nd,LoRaData);
        }
    }

  }

















