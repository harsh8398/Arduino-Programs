/****************************************************************************
 * Title  : Using PWM control the brigESDIness of LED.                      *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define LED 9
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  LEDFade();
}

void LEDFade() {
  for(int i = 0; i < 256; i++) {
    analogWrite(LED, i);
    delay(50);
  }
  delay(500);
  for(int i = 255; i > 0; i--) {
    analogWrite(LED, i);
    delay(50);
  }
  delay(500);
}

