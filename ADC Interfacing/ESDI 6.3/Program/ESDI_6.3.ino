/****************************************************************************
 * Title  : Monitor the temperature using LM35 temperature sensor and       *
 *          display on LED                                                  *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define TempIN A0

float milliVolts;

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(TempIN, INPUT);
}

void loop() {
  // modify range from 0-1023 to 0-5000 mV
  milliVolts = (analogRead(TempIN) / 1023.0) * 5000.0;
  // 10 mV -> 1 C
  int Celsius = milliVolts / 10;
  PORTD = Celsius;
}
