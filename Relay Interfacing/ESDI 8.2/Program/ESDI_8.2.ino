/****************************************************************************
 * Title  : Monitor temperature using LM35 and display on lcd               *
 *          if temperature > 20,device on and buzzer on                     *
 *          if temperature < 20,device off and buzzer off                   *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = 0;
float tempC, tempF;
int RELAY = 13;

void setup() {
  lcd.begin(16, 2);
  pinMode(RELAY,OUTPUT);
}

void loop()
{
  int value = analogRead(sensorPin); // read the value from the sensor
  float millivolts = (value / 1024.0) * 5000; 
  tempC = millivolts / 10;
  tempF = (tempC * 9)/5 + 32; //turning the celsius into fahrenheit
  lcd.setCursor(0,0);
  lcd.print(tempC);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print(tempF);
  lcd.print(" F"); 
  if(tempC > 20.02)
      digitalWrite(RELAY,LOW);
  else
      digitalWrite(RELAY,HIGH);
  delay(100);
}
