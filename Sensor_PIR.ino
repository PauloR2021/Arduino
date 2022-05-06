#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pinosensor = 2;
int pinolampada = 3;

void setup()
{
  pinMode(pinosensor, INPUT);
  pinMode(pinolampada,OUTPUT);
}

void loop()
{
  if(digitalRead(pinosensor)==HIGH)
  {
    digitalWrite(pinolampada,LOW);
    lcd.setCursor(0,0);
    lcd.print("LIGADO");
  }
  else{
    digitalWrite(pinolampada,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DESLIGADO");
  }
}
