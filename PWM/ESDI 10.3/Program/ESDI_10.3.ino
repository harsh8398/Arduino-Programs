/****************************************************************************
 * Title  : Interface three push button. If                                 *
 *          SW1 pressed, rotate motor with full speed.                      *
 *          SW2 pressed, rotate motor with 1/2 speed.                       *
 *          SW3 pressed, rotate motor with 1/3 speed.                       *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define MP 10
#define MN 9
#define SW1 2
#define SW2 3
#define SW3 4
void setup() {
  pinMode(MP, OUTPUT);
  pinMode(MN, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
}

void loop() {
  if(digitalRead(SW1)) {
    analogWrite(MP, 255);
    analogWrite(MN, 0);
  } else if(digitalRead(SW2)) {
    analogWrite(MP, 255/2);
    analogWrite(MN, 0);
  } else if(digitalRead(SW3)) {
    analogWrite(MP, 255/3);
    analogWrite(MN, 0);
  } else {
    analogWrite(MP, 0);
    analogWrite(MN, 0);
  }
}
