# DFRobot_FreeTenIMU

- [中文版](./README_CN.md)

The 10 DOF(degrees of the freedom) IMU sensor is a compact and low-cost IMU from DFRobot. It integrates ADXL345 accelerometer, QMC5883L magnetometer, ITG3205 gyro, BMP280 barometric sensor and temperature sensor. This sensor embeds a low noise LDO regulator for supplying a wide range of power input, and works with a 3V-5V power supply. Certainly, it is compatible with the Arduino board.

![正反面svg效果图](./resources/images/SEN0140.png)

## Product Link (https://www.dfrobot.com/product-818.html)

    SKU: SEN0140

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

This library provides a routine to get the value of the accelerometer, gyro, magnetometer, and temperature and humidity sensor.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

    /**
     * @fn begin
     * @brief Sensor init 
     * @return  bool 
     * @retval  true init succeeded
     * @retval  false init failed
     */
    bool begin(void);

    /**
     * @fn getEul
     * @brief Get the elevation, roll and yaw angle of the sensor
     * @return sEulAnalog_t save the three angles
     */
    sEulAnalog_t  getEul(void);

```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32           |      √       |              |             | 
ESP8266           |      √       |              |             | 
micro:bit        |      √       |              |             | 

## History

- 2022/3/4 - Version 1.0.0 released.

## Credits

Written by Peng Kaixing(kaixing.peng@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))
