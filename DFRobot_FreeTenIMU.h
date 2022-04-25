/*!
 * @file DFRobot_FreeTenIMU.h
 * @brief 使用加速度计，陀螺仪，磁力计，温湿度传感器的库
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2022-3-4
 * @url https://github.com/DFRobot/DFRobot_FreeTenIMU
 */

#include <DFRobot_ADXL345.h>
#include <DFRobot_ITG3200.h>
#include <DFRobot_QMC5883.h>
#include <DFRobot_BMP280.h>

/**
 * @struct sEulAnalog_t
 * @brief 保存实际的翻滚角，偏航角，仰角
 */
typedef struct
{
  float head, roll, pitch;
} sEulAnalog_t;

/**
 * @struct sEulData_t
 * @brief 保存实际的原始值
 */
typedef struct
{
  int16_t head, roll, pitch;
} sEulData_t;

class DFRobot_FreeTenIMU
{
  public:
    DFRobot_FreeTenIMU(DFRobot_ADXL345_I2C* ADXL345,DFRobot_ITG3200* gyro,DFRobot_QMC5883* compass,DFRobot_BMP280_IIC* bmp);
    /**
     * @fn begin
     * @brief 传感器初始化 
     * @return  bool 
     * @retval  true 初始化成功
     * @retval  false 初始化失败
     */
    bool begin(void);

    /**
     * @fn getEul
     * @brief 获取传感器的仰角、翻滚角、偏航角
     * @return sEulAnalog_t 保存三个角度
     */
    sEulAnalog_t  getEul(void);
  private:
    DFRobot_ADXL345_I2C* _ADXL345;
    DFRobot_ITG3200* _gyro;
    DFRobot_QMC5883* _compass;
    DFRobot_BMP280_IIC* _bmp;
};