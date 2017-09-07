/****************************************************************************
 * Title  : Using PWM control the speed of DC motor.                        *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define MP 10
#define MN 9
void setup() {
  pinMode(MP, OUTPUT);
  pinMode(MN, OUTPUT);
}

void loop() {
  motorFade();
}

void motorFade() {
  for(int i = 0; i < 256; i++) {
    analogWrite(MP, i);
    analogWrite(MN, 0);
    delay(50);
  }
  delay(500);
  for(int i = 0; i < 256; i++) {
    analogWrite(MP, 0);
    analogWrite(MN, i);
    delay(50);
  }
  delay(500);
}

