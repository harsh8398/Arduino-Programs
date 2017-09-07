/****************************************************************************
 * Title  : Monitor temperature using LM35 and display on 7-segment         *
 *          if temperature > 20,device on and buzzer on                     *
 *          if temperature < 20,device off and buzzer off                   *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define E1 8
#define E2 9
#define E3 10
#define E4 11
#define E6 12
#define TEMPIN A0
#define RELAY 13

char num[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
char num1[] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

float temp;
void setup() {
  for(int i=0;i<12;i++)
    pinMode(i,OUTPUT);
  pinMode(TEMPIN,INPUT);
  pinMode(RELAY,OUTPUT); 
}

void loop() {
   temp = analogRead(TEMPIN);
   temp = temp * 500 / 1024.0 ;
   temperature(temp); 
}
