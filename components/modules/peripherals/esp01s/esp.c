#include "esp.h"
#include "string.h"

/************************************
*******************************************
* 函 数 名         : SendStr
* 函数功能		   : 发送一个字符串
* 输    入         : 字符串S的首地址
* 输    出         : 无
*******************************************************************************/
void SendStr(uchar *s)
{
while(*s)//收到结束符跳出循环
  {
Send_rt(*s);//发送S地址里面的字符
s++;//S地址加一，发送下一个字符
  }
}
/*******************************************************************************
* 函 数 名         : Send_rt
* 函数功能		   : 发送一个字符
* 输    入         : 字符串c
* 输    出         : 无
*******************************************************************************/
void Send_rt(uchar ch)
{
	//uart_write(UART1, ch , 1);
	uart_putc_noint(UART0, ch);
}

void Wifi_Init(void)
{

	/*system_set_port_pull(GPIO_PA2, true);
    system_set_port_mux(GPIO_PORT_A, GPIO_BIT_2, PORTA2_FUNC_UART1_RXD);
    system_set_port_mux(GPIO_PORT_A, GPIO_BIT_3, PORTA3_FUNC_UART1_TXD);
    uart_init(UART0, BAUD_RATE_115200); */
       system_set_port_pull(GPIO_PD4, true);
        system_set_port_mux(GPIO_PORT_D, GPIO_BIT_4, PORTD4_FUNC_UART0_RXD);
        system_set_port_mux(GPIO_PORT_D, GPIO_BIT_5, PORTD5_FUNC_UART0_TXD);
		uart_init(UART0, BAUD_RATE_115200);
}

void Wifi_delay_1ms(uint32_t ms)
{
	uint32_t i;
	for(i=0;i<ms;i++)
	{
		co_delay_100us(10);
	}

}

void Wifi_Rst(void)
{
	SendStr("AT+RST");
	SendLR();
	
}

void Wifi_Connect(void)
{
	//SendStr("AT+CIPSTART=\"TCP\",\"115.29.109.104\",6545");
	SendStr("AT+CWJAP=\"YYYYY\",\"aihui1314.\"");
	SendLR();
}

void Wifi_ConnectIP(void)
{
	SendStr("AT+CIPSTART=\"TCP\",\"115.29.109.104\",6545");
	SendLR();
}

void Wifi_SendMode(void)
{
	SendStr("AT+CIPMODE=1");
	SendLR();
}

void Wifi_SendData(void)
{
	SendStr("AT+CIPSEND");
	SendLR();
}

void esp_init(void)
{
	Wifi_Init();
	Wifi_delay_1ms(100);
	Wifi_Rst();
	Wifi_delay_1ms(7000);
	//Wifi_Connect();
	//Wifi_delay_1ms(3000);
	Wifi_ConnectIP();
	Wifi_delay_1ms(1000);
	Wifi_SendMode();
	Wifi_delay_1ms(1000);
	Wifi_SendData();
	Wifi_delay_1ms(1000);
}

void esp_send(uchar *s)
{
	SendStr(s);
}