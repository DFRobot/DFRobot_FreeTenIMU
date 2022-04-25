/*!
 * @file DFRobot_FreeTenIMU.cpp
 * @brief 使用加速度计，陀螺仪，磁力计，温湿度传感器的库
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2022-3-4
 * @url https://github.com/DFRobot/DFRobot_FreeTenIMU
 */

#include "DFRobot_FreeTenIMU.h"

DFRobot_FreeTenIMU::DFRobot_FreeTenIMU(DFRobot_ADXL345_I2C *ADXL345, DFRobot_ITG3200 *gyro, DFRobot_QMC5883* compass, DFRobot_BMP280_IIC* bmp)
{
    _ADXL345 = ADXL345;
    _gyro = gyro;
    _compass = compass;
    _bmp = bmp;
}

bool DFRobot_FreeTenIMU::begin(void)
{
  _ADXL345->begin();
  _gyro->begin();
  _compass->begin();
  _bmp->begin();
  _ADXL345->powerOn();
  return true;
}

sEulAnalog_t DFRobot_FreeTenIMU::getEul(void)
{
  sEulAnalog_t  sEulAnalog;
  int accval[3];
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / PI);
  _compass->setDeclinationAngle(declinationAngle);
  sVector_t mag = _compass->readRaw();
  _compass->getHeadingDegrees();
  sEulAnalog.head = mag.HeadingDegress;
  _ADXL345->readAccel(accval);
  _ADXL345->RPCalculate(accval);
  sEulAnalog.roll = _ADXL345->RP.roll;
  sEulAnalog.pitch = _ADXL345->RP.pitch;
  return sEulAnalog;
}

