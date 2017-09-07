/****************************************************************************
 * Title  : Rotate motor clockwise and anticlockwise for 1second.           *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define MP 1
#define MN 0

void setup() {
  pinMode(MP, OUTPUT);
  pinMode(MN, OUTPUT);
}

void loop() {
  digitalWrite(MP, HIGH);
  digitalWrite(MN, LOW);
  delay(1000);
  digitalWrite(MP, LOW);
  digitalWrite(MN, HIGH);
  delay(1000);
}
