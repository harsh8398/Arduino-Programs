/****************************************************************************
 * Title  : Rotate motor clockwise and anticlockwise using switch           *
 *          If SW open, rotate clockwise                                    *
 *          If SW close, rotate anticlockwise                               *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define MP 1
#define MN 0
#define Switch 2

void setup() {
  pinMode(MP, OUTPUT);
  pinMode(MN, OUTPUT);
  pinMode(Switch, INPUT);
}

void loop() {
  digitalWrite(MP, !digitalRead(Switch));
  digitalWrite(MN, digitalRead(Switch));
}
