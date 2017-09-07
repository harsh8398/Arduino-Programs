#include<LiquidCrystal.h>
const int sensor=A1; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
LiquidCrystal lcd(11,10,5,4,3,2);
void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
Serial.begin(9600);
lcd.begin(16,2);
}
void loop() 
{
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit 
lcd.setCursor(0,0);
lcd.print("In C= ");
lcd.print(tempc);
lcd.setCursor(0,1);
lcd.print("In F=");
lcd.print(tempf);
delay(1000); //Delay of 1 second for ease of viewing 
}
