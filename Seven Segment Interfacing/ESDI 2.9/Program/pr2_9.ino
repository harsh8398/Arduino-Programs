/****************************************************************************
 * Title  : Set the time using four switch and display the clock on segment *
 *          SW1 : when press, increment 1 digit                             *
 *          SW2 : when press, decrement 1 digit                             *
 *          SW3 : when press, display set time                              *
 *          SW4 : when press, start the clock                               *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define SETUP 14
#define START 15
#define UP 16
#define DOWN 17

int num1[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
// num2 - with decimal segment value high always
int num2[10] = {0xbf, 0x86, 0xdb, 0xcf, 0xe6, 0xed, 0xfd, 0x87, 0xff, 0xef};
int digit[6] = {0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};
long timer;
int h = 10, m = 10, s = 0, setCnt = 0, blinkCnt = 0;
char mode = 's';     // 's' -> setup mode, 'r' -> running mode

void showTime(int h, int m, int s, char blinkSeg = 'n');
void setupMode();
void runningMode();
void resetMethod();
void startMethod();

void setup() {
  for(int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  for(int i = 14; i < 18; i++) {
    pinMode(i, INPUT);
  }
  timer = millis();
}

void loop() {
  if(digitalRead(SETUP)) {
    if(setCnt<2)setCnt++;
    else setCnt = 0;
    delay(200);
  } else if(digitalRead(START)) {
    setCnt = 0;
    delay(200);
  }
  switch(setCnt) {
    case 0:
      runningMode();
      showTime(h,m,s);break;
    case 1:
      setupMode();
      showTime(h,m,s,'h');break;
    case 2:
      setupMode();
      showTime(h,m,s,'m');break;
  }
}

void showTime(int h, int m, int s, char blinkSeg = 'n') {
  switch(blinkSeg) {
    case 'h':
      if(blinkCnt <= 100) break;
      else if(blinkCnt >= 200) blinkCnt = 0;
    default:
      // Hh:mm:ss
      PORTB = digit[0];
      PORTD = num1[h/10];
      delay(1);
      // hH:mm:ss
      PORTB = digit[1];
      PORTD = num2[h%10];
      delay(1);
  }
  switch(blinkSeg) {
    case 'm':
      if(blinkCnt <= 100) break;
      else if(blinkCnt >= 200) blinkCnt = 0;
    default:
      // hh:Mm:ss
      PORTB = digit[2];
      PORTD = num1[m/10];
      delay(1);
      // hh:mM:ss
      PORTB = digit[3];
      PORTD = num2[m%10];
      delay(1);
  }
  // hh:mm:Ss
  PORTB = digit[4];
  PORTD = num1[s/10];
  delay(1);
  // hh:mm:sS
  PORTB = digit[5];
  PORTD = num1[s%10];
  delay(1);
  blinkCnt++;
}

void runningMode() {
  if(millis()-timer>1000) {
    timer = millis();
    s++;
  }
  if(s >= 60) {
    s = 0;
    m++;
    if(m >= 60) {
      m = 0;
      h++;
      if(h >= 24) {
        h = 0;
      }
    }
  }
}

void setupMode() {
  if(digitalRead(UP)) {
    if(setCnt == 1) {
      if(h<23) h++;
      else h = 0;
    }
    else {
      if(m<59) m++;
      else m = 0;
    }
    delay(200);
  }
  else if(digitalRead(DOWN)) {
    if(setCnt == 1) {
      if(h>0) h--;
      else h = 23;
    }
    else {
      if(m>0) m--;
      else m = 59;
    }
    delay(200);
  }
  runningMode();
}
