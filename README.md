# MPU6050 I2C communication

## Description

This project demonstrates how to read data from the MPU6050 sensor over I2C using an Arduino, The provided code requests 14 bytes of data from the sensor and extracts the last 2 bytes for yaw angle that we only care about .

## Code Explanation

### Includes and Definitions

```cpp
#include <Wire.h>  // Include the Wire library for I2C communication

#define MPU6050_ADDR 0x68  // MPU6050 I2C address (default)
#define TOTAL_BYTES 14     // Number of bytes to read from the sensor
