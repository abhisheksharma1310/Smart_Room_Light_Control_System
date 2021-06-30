//Program for smart room light control
#include<LiquidCrystal.h>
//port c of ATmeg328 is Ao-A5 of Arduino
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); //LCD display pins RS,E,D4,D5,D6,D7

volatile int detect1 = 0;
volatile int detect2 = 0;

const int light = 5;
int i = 0;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); //LCD as 16x2
  lcd.setCursor(0,0);
  lcd.print("Smart Room Light");
  delay(2000);
  lcd.clear();
  pinMode(light,OUTPUT); 

  attachInterrupt(digitalPinToInterrupt(2),ir1,FALLING); //function to create Interrupt 
  attachInterrupt(digitalPinToInterrupt(3),ir2,FALLING);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  if(detect1==1)
  {
    if(detect2==1)
    {
      i--;
      detect1 = detect2 = 0;
    }
    
  }
  else
  {
    if(detect2==1)
    {
      if(detect1==1)
      {
        i++;
        detect1 = detect2 = 0;
      }      
    }
  }
  lcd.print("Person:");
  lcd.print(i);
  if(i>0)
  {
    digitalWrite(light,HIGH);
  }
  else
  {
    digitalWrite(light,LOW);
  }
}

void ir1()
{
  detect1 = 1; 
}

void ir2()
{
  detect2 = 1;
}
