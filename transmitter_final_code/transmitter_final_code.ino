#include<SoftwareSerial.h>
#include <SPI.h>
#include<Wire.h>
//SoftwareSerial mybt(0,1);
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int m=0,n=0;
const int MPU_addr=0x68;
int dupa=0;
int joystick[2];
 
void setup() {
  // put your setup code here, to run once:
//  mybt.begin(38400);
  Serial.begin(38400);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  joystick[0]=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  joystick[1]=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  joystick[2]=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
     
    AcX = joystick[0];
    AcY = joystick[1];
    if(AcX<-6000){      //Forward
//    mybt.write("F");
    Serial.println('F');
    }
    else if(AcX>6000){
//    mybt.write("F");
    Serial.println('B');
    }
    else if(AcY>6000){
//    mybt.write("R");
    Serial.println('R');
    }
    else if(AcY<-6000){
//    mybt.write("L");
    Serial.println('L');
    }
    else if(AcX<6000 && AcX>-6000 && AcX<6000 && AcX>-6000){
//    mybt.write("S");
    Serial.println('S');
    }
    delay(1000);

}
