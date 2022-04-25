/*!
 * @file imuShow.ino
 * @brief Read the sensor elevation Angle, roll Angle and yaw Angle through the I2C interface, and print the read data through the serial port
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2022-3-4
 * @url https://github.com/DFRobot/DFRobot_FreeTenIMU
 */
#include "DFRobot_FreeTenIMU.h"

DFRobot_BMP280_IIC bmp(&Wire, DFRobot_BMP280_IIC::eSdoLow);
DFRobot_ADXL345_I2C ADXL345(&Wire,0x53);
DFRobot_ITG3200 gyro(&Wire, 0x68);
DFRobot_QMC5883 compass(&Wire, /*I2C addr*/VCM5883L_ADDRESS);
DFRobot_FreeTenIMU FreeTenIMU(&ADXL345,&gyro,&compass,&bmp);

void setup() {
  Serial.begin(9600);
  FreeTenIMU.begin();
}

void loop() {
  sEulAnalog_t   sEul;
  sEul = FreeTenIMU.getEul();
  Serial.print("pitch:");
  Serial.print(sEul.pitch, 3);
  Serial.print(" ");
  Serial.print("roll:");
  Serial.print(sEul.roll, 3);
  Serial.print(" ");
  Serial.print("yaw:");
  Serial.print(sEul.head, 3);
  Serial.println(" ");
  delay(80);
}
