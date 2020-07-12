#ifndef __ESP_H
#define __ESP_H

#include "co_printf.h"
#include <stdbool.h>
#include <stdio.h>
#include "sys_utils.h"

#include "driver_uart.h"
#include "driver_gpio.h"
#include "driver_iomux.h"
#include "os_timer.h"
#include "driver_system.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

#define SendLR()  Send_rt(0x0D);Send_rt(0x0A) //发送回车换行
void SendStr(uchar *s);
void Send_rt(uchar ch);
void Wifi_Init(void);
void Wifi_Rst(void);
void Wifi_Connect(void);
void Wifi_ConnectIP(void);
void Wifi_SendMode(void);
void Wifi_SendData(void);
void esp_init(void);
void esp_send(uchar *s);

#endif /*__ESP_H*/
