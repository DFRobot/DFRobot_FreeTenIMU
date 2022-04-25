/*!
 * @file DFRobot_FreeTenIMU.h
 * @brief Use accelerometer, gyroscope, magnetometer, temperature and humidity sensor library
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
 * @brief Save the actual roll Angle, yaw Angle, elevation Angle
 */
typedef struct
{
  float head, roll, pitch;
} sEulAnalog_t;

/**
 * @struct sEulData_t
 * @brief Save the actual raw values
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
     * @brief Sensor initialization
     * @return  bool
     * @retval  true Initialization succeeded
     * @retval  false Initialization failed
     */
    bool begin(void);

    /**
     * @fn getEul
     * @brief Get sensor elevation Angle, roll Angle, yaw Angle
     * @return sEulAnalog_t Save three angles
     */
    sEulAnalog_t  getEul(void);
  private:
    DFRobot_ADXL345_I2C* _ADXL345;
    DFRobot_ITG3200* _gyro;
    DFRobot_QMC5883* _compass;
    DFRobot_BMP280_IIC* _bmp;
};