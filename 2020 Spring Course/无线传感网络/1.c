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
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 128 //接收和发送的最大长度

#define SENSOR_START 0XCC
#define SENSOR_CMD 0X01
#define SENSOR_LEN 0X08
#define SENSOR_NUM1 0X01
#define SENSOR_NUM2 0X02
#define SENSOR_TEMP 0X01 //温度
#define SENSOR_RH 0X02   //湿度
#define SENSOR_FIRE 0X03 //火焰

#define SEND_ADDR 0X4321
#define MY_ADDR 0X1234
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
            /*
send_data[0] = 0xCC; //起始位
send_data[1] = 0x01; //数据采集
send_data[2] = 8; //数据长度
send_data[3] = 2; //传感器个数
send_data[4] = 1; //传感器类型 温度
send_data[5] = 0x1B; //温度 27
send_data[6] = 2; //传感器类型 湿度
 send_data[7] = 0x32; //湿度 50
 send_data[8] = CHK(send_data,send_data[2]); //CHK校验
 */
            unsigned int wendu = 0;
            unsigned int shidu = 0;
            call_sht11(&wendu, &shidu);

            send_data[0] = SENSOR_START;                 //起始位
            send_data[1] = SENSOR_CMD;                   //数据采集
            send_data[2] = SENSOR_LEN;                   //数据长度
            send_data[3] = SENSOR_NUM2;                  //传感器个数
            send_data[4] = SENSOR_TEMP;                  //传感器类型 温度
            send_data[5] = wendu;                        //温度 27
            send_data[6] = SENSOR_RH;                    //传感器类型 湿度
            send_data[7] = shidu;                        //湿度 50
            send_data[8] = CHK(send_data, send_data[2]); //CHK校验
#ifdef CC2530_DBG
            uart_printf("温度为 %d ℃ 湿度为 %d %%RH \r\n", wendu, shidu);
//char show_buff[128] = {0};
//sprintf(show_buff,"温度为 %d ℃ 湿度为 %d %%RH",wendu,shidu);
//halUartWrite(show_buff, 128);
#endif
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