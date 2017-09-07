/****************************************************************************
 * Title  : Monitor the temperature using LM35 temperature sensor and       *
 *          display on 7-segment                                            *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define TempIN A0

int num[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
float milliVolts;

void showTemp(int temp);

void setup() {
  for(int i = 0; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(TempIN, INPUT);
}

void loop() {
  // modify range from 0-1023 to 0-5000 mV
  milliVolts = (analogRead(TempIN) / 1023.0) * 5000.0;
  // 10 mV -> 1 C
  int Celsius = milliVolts / 10;
  showTemp(Celsius);
}

void showTemp(int temp) {
  PORTB = 0x0E;
  PORTD = num[temp/10];
  delay(1);
  PORTB = 0x0D;
  PORTD = num[temp%10];
  delay(1);
  PORTB = 0x07;
  PORTD = 0b00111001;
  delay(1);
}

