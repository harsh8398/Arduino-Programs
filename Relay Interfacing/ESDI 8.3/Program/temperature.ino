void temperature(float temp)
{
  if(temp > 20.02)
    digitalWrite(RELAY,LOW);
  else
    digitalWrite(RELAY,HIGH);
  int inter;
  digitalWrite(E1,HIGH);
  inter = (int)temp/10;
  PORTD = num[inter];
  delay(2);
  digitalWrite(E1,LOW);

  digitalWrite(E2,HIGH);
  inter = ((int)(temp))%10;
  PORTD = num1[inter];
  delay(2);
  digitalWrite(E2,LOW);

  digitalWrite(E3,HIGH);
  inter = ((int)(temp*10))%10;
  PORTD = num[inter];
  delay(2);
  digitalWrite(E3,LOW);

  digitalWrite(E4,HIGH);
  inter = ((int)(temp*100))%10;
  PORTD = num[inter];
  delay(2);
  digitalWrite(E4,LOW);

  digitalWrite(E6,HIGH);
  PORTD = 0xC6;
  delay(2);
  digitalWrite(E6,LOW);
  
  delay(2);
}
