#include<LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
boolean comparatorOutput;

ISR(ANALOG_COMP_vect)
{
  comparatorOutput = true;
}
void setup() 
{
  // put your setup code here, to run once:
ADCSRB = 0;
ACSR =_BV(ACI) | _BV(ACIE)| _BV(ACIS1);
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Analog Comparator");
}

void loop() 
{
  // put your main code here, to run repeatedly:
if(comparatorOutput == true)
{
  lcd.setCursor(0,1);
  lcd.print("Comparator High");
  comparatorOutput = false;
}
else
{
  lcd.setCursor(0,1);
  lcd.print("Comparator Low  ");
}
delay(500);
}
