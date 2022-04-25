/*!
 * @file readData.ino
 * @brief 读取10Dof模块采集到的温度、大气压、海拔等信息，并通过串口打印出数值
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2022-3-4
 * @url https://github.com/DFRobot/DFRobot_FreeTenIMU
 */
#include "DFRobot_BMP280.h"

// use abbreviations instead of full names
typedef DFRobot_BMP280_IIC    BMP;    
BMP   bmp(&Wire, DFRobot_BMP280_IIC::eSdoHigh);

// sea level pressure
#define SEA_LEVEL_PRESSURE    1015.0f   

// show last sensor operate status
void printLastOperateStatus(BMP::eStatus_t eStatus)
{
  switch(eStatus) 
  {
    case BMP::eStatusOK:    
      Serial.println("everything ok"); 
      break;
    case BMP::eStatusErr:   
      Serial.println("unknow error"); 
      break;
    case BMP::eStatusErrDeviceNotDetected:  
      Serial.println("device not detected");
      break;
    case BMP::eStatusErrParameter:    
      Serial.println("parameter error"); 
      break;
    default: 
      Serial.println("unknow status"); 
      break;
  }
}

void setup()
{
  Serial.begin(9600);
  bmp.reset();
  Serial.println("bmp read data test");
  while(bmp.begin() != BMP::eStatusOK) 
  {
    Serial.println("bmp begin faild");
    printLastOperateStatus(bmp.lastOperateStatus);
    delay(2000);
  }
  Serial.println("bmp begin success");
  delay(100);
}

void loop()
{
  float   temp = bmp.getTemperature();
  uint32_t    press = bmp.getPressure();
  float   alti = bmp.calAltitude(SEA_LEVEL_PRESSURE, press);
  Serial.println();
  Serial.println("======== start print ========");
  Serial.print("temperature (unit Celsius): "); Serial.println(temp);
  Serial.print("pressure (unit pa):         "); Serial.println(press);
  Serial.print("altitude (unit meter):      "); Serial.println(alti);
  Serial.println("========  end print  ========");
  delay(1000);
}
