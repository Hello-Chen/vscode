#include "hal_defs.h"
#include "hal_cc8051.h"
#include "hal_mcu.h"
#include "hal_digio.h"
#include "hal_int.h"
#include "hal_board.h"
#include "hal_uart.h"
#include "hal_rf.h"
#include "basic_rf.h"
#include "hal_clock.h"
#include "hal_led.h"
#include "TIMER.h"
#include "ioCC2530.h"
#include "sh10.h"
#include "UART_PRINT.h"
#include "get_adc.h"
#include "get_swsensor.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 128 //接收和发送的最大长度

#define SENSOR_START 0XCC
#define SENSOR_CMD 0X01
#define SENSOR_LEN 0X07
#define SENSOR_NUM1 0X01
#define SENSOR_NUM2 0X02
#define SENSOR_TEMP 0X01 //温度
#define SENSOR_RH 0X02   //湿度
#define SENSOR_FIRE 0X03 //火焰

#define SEND_ADDR 0X4321
#define MY_ADDR 0X1122
#define PAN_ID 0X8888
#define RF_CHANNEL 25
basicRfCfg_t basicrfConfig; // 定义结构体变量

uint8 send_data[MAX_LEN] = {0};    //存放发送数据的 数组
uint8 receive_data[MAX_LEN] = {0}; //存放接收数据的 数组

void basicRFConfig_Init()
{
    //结构体配置
    basicrfConfig.myAddr = MY_ADDR;
    basicrfConfig.panId = PAN_ID;
    basicrfConfig.channel = RF_CHANNEL;
    basicrfConfig.ackRequest = TRUE;
    //初始化成功才继续执行
    while (basicRfInit(&basicrfConfig) == FAILED)
        ;
    basicRfReceiveOn();
}

uint8 CHK(uint8 *data, uint8 len)
{
    uint8 i = 0;
    uint16 sum = 0;
    while (i < len)
    {
        sum += data[i];
        i++;
    }

    return sum & 0xFF;
}

void show_LED(uint8 i, uint16 ms)
{

    halLedSet(i);
    halMcuWaitMs(ms);
    halLedClear(i);
}

void main()
{
    // 第一步初始化硬件、外设等
    halBoardInit();
    // 第二步 初始化 basicRF ----- 配置结构体
    basicRFConfig_Init();

    Timer4_Init();
    Timer4_On();

    while (1)
    {
        if (GetSendDataFlag() == 1) //定时2s时间到达
        {

            uint16 fire = get_adc();
            //uint8 fire = get_swsensor();

#ifdef CC2530_DBG
            /*if(fire == 1)
 {
 uart_printf("着火了！ \r\n");
 }
 else
 {
 uart_printf("安全的很 \r\n");
 }*/

            uart_printf("火焰强度转化的电压为 %dmv \r\n", fire * 10);
//char show_buff[128] = {0};
//sprintf(show_buff,"温度为 %d ℃ 湿度为 %d %%RH",wendu,shidu);
//halUartWrite(show_buff, 128);
#endif

            send_data[0] = SENSOR_START; //起始位
            send_data[1] = SENSOR_CMD;   //数据采集
            send_data[2] = SENSOR_LEN;   //数据长度
            send_data[3] = SENSOR_NUM1;  //传感器个数
            send_data[4] = SENSOR_FIRE;  //传感器类型 火焰
            //模拟量传感器的数据一定是两个字节！！！！
            send_data[5] = (fire * 10) / 256; //火焰数据的高8位
            //send_data[5] = (fire*10) >> 8; //火焰数据的高8位
            send_data[6] = (fire * 10) & 0xFF;           //火焰数据的低8位
            send_data[7] = CHK(send_data, send_data[2]); //CHK校验

            //sprintf(send_data,"hello");
            basicRfSendPacket(SEND_ADDR, send_data, (uint8)(send_data[2] + 1));

            //show_LED(1,100);
            Timer4_On(); //重新打开定时器
        }
        /*
 //判断有无数据待接收
 if(basicRfPacketIsReady())
 {
 basicRfReceive(receive_data, MAX_LEN, NULL);
 
 }*/
    }
}