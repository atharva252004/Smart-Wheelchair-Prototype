//Receiver code 
//all the best
#include<SoftwareSerial.h>
//SoftwareSerial mybt(2,3);
char m;

void setup() {
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
Serial.begin(38400);
//S.begin(9600);
}

void loop() {
if(Serial.available()>0)
{
m= Serial.read();
Serial.println(m);
delay(100);

if(m=='F')


{
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);

}

else if(m=='B')

{
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, HIGH);

}

else if(m=='R')

{
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);

}
else if(m=='L')

{
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, HIGH);

}

else if(m=='S')

{
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);

}
//else
//
//{
//digitalWrite(10, LOW);
//digitalWrite(11, LOW);
//digitalWrite(12, LOW);
//digitalWrite(13, LOW);

//}


}}
