#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("ADC Example on A0");
analogReference(INTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned int dataADC = analogRead(A0);
lcd.clear();
lcd.setCursor(0,1);
lcd.print("Value = ");
lcd.print(dataADC);
delay(500);
}
