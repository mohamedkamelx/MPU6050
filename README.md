# MPU6050 I2C communication

## Description

This project demonstrates how to read data from the MPU6050 sensor over I2C using an Arduino, The provided code requests 14 bytes of data from the sensor and extracts the last 2 bytes for yaw angle that we only care about .

## Code Explanation

### setup
starts the communication and power the sensor and exit sleep state
```cpp
void setup() 
{
  
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(MPUaddress);
  Wire.write(0x6B);  // powering the sensor
  Wire.write(0x00);  // waking it up from sleep which is its default state
  Wire.endTransmission();
}
```


### loop
1. start the accelerometer sensor
2. request the data
3. skip the not required part
4. print the yaw angle
