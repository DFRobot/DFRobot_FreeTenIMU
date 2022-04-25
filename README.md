# DFRobot_FreeTenIMU

- [中文版](./README_CN.md)

DFrobot的高集成度低成本的10自由度传感器,集合了ADXL345加速度计、QMC5883L磁罗盘、ITG3205陀螺仪以及BMP280气压传感器和温度传感器。内置了低噪声的低压线性稳压器，还扩展了电源电压输入范围，支持3V-5V电源电压。同时，10自由度IMU也可以直接和Arduino控制板兼容。

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

这个库提供了一个获取传感器速度计，陀螺仪，磁力计，温湿度传感的值

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

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