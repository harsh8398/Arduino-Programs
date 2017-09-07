#include<LiquidCrystal.h>
float vout;
LiquidCrystal lcd(11,10,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
  pinMode(A2,INPUT);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  vout=analogRead(A2);
  lcd.setCursor(0,0);
  lcd.print("Voltage: ");
  lcd.print(vout);
}
