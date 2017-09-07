/****************************************************************************
 * Title  : Monitor the temperature using LM35 temperature sensor and       *
 *          display on LCD.                                                 *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#include<LiquidCrystal.h>
#define TempIN A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float milliVolts;

void setup() {
  pinMode(TempIN, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
}

void loop() {
  // modify range from 0-1023 to 0-5000 mV
  milliVolts = (analogRead(TempIN) / 1023.0) * 5000.0;
  // 10 mV -> 1 C
  int Celsius = milliVolts / 10;
  lcd.setCursor(0, 1);
  lcd.print(Celsius);
  lcd.print(" C");
}
