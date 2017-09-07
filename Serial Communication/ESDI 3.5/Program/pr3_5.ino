/****************************************************************************
 * Title  : Receive data between 0 t0 9 and display on segment              *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
int numB[10] = {0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b};
int numC[10] = {0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void setup() {
  for(int i = 8; i < 15; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Enter here...");
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    if(isdigit(data)) {
      PORTC = numC[int(data - '0')];
      PORTB = numB[int(data - '0')];
    }
  }
}

