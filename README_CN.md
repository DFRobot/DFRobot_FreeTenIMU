# DFRobot_FreeTenIMU

- [English Version](./README.md)

DFrobot的高集成度低成本的10自由度传感器,集合了ADXL345加速度计、QMC5883L磁罗盘、ITG3205陀螺仪以及BMP280气压传感器和温度传感器。内置了低噪声的低压线性稳压器，还扩展了电源电压输入范围，支持3V-5V电源电压。同时，10自由度IMU也可以直接和Arduino控制板兼容。

![正反面svg效果图](./resources/images/SEN0140.png)

## 产品链接(https://www.dfrobot.com.cn/goods-640.html)

    SKU: SEN0140

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性y)
* [历史](#历史)
* [创作者](#创作者)

## 概述

这个库提供了一个获取传感器速度计，陀螺仪，磁力计，温湿度传感的值

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

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
## 兼容性

主板               | 通过  | 未通过   | 未测试   | 备注
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32           |      √       |              |             | 
ESP8266           |      √       |              |             | 
Micro:bit           |      √       |              |             | 

## 历史

- 2022/3/4 - 1.0.0 版本

## 创作者

Written by Peng Kaixing(kaixing.peng@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))