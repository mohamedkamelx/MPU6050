#include <Wire.h>
#define MPUaddress 0x68  

void setup() 
{
  
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(MPUaddress);
  Wire.write(0x6B);  // powering the sensor
  Wire.write(0x00);  // waking it up from speed which is its default state
  Wire.endTransmission();
}


void loop() 
{
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);  // starting accelerometer
  Wire.endTransmission();
  
  /*   
  request 14 bytes of data which includes :
  X     (2 bytes) 
  Y     (2 bytes)
  Z     (2 bytes)
  temp  (2 bytes)
  roll  (2 bytes)
  pitch (2 bytes)
  yaw   (2 bytes)

  */ 
  
  Wire.requestFrom(MPU6050_ADDR, 14);
  
  
  

  // since read function only gets 8 bits by 8 bits
   
  if (Wire.available())
  {
    for (int i = 0; i < 12; i++) 
    {
      Wire.read();
    }
     int16_t yaw = Wire.read() << 8 | Wire.read();

  }

  Serial.print("yaw = "); Serial.println(yaw);

  delay(1000); 
}