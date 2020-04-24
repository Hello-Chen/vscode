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
#define SENSOR_LEN 0X06
#define SENSOR_NUM1 0X01
#define SENSOR_NUM2 0X02
#define SENSOR_TEMP 0X01 //温度
#define SENSOR_RH 0X02   //湿度
#define SENSOR_FIRE 0X03 //火焰

#define MY_ADDR 0X4321
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

// 传入普通 数组 (204 01) 转化为 16进制的字符串数组 “CC 01”
void GetHexStr(uint8 *input, uint8 len, int8 *output)
{
    uint8 i = 0;

    while (i < len)
    {
        // 转换的 16进制保存 2位 后再跟1位 空格
        sprintf(output + i * 3, "%02x ", input[i]);
        i++;
    }
}

void main()
{
    // 第一步初始化硬件、外设等
    halBoardInit();
    // 第二步 初始化 basicRF ----- 配置结构体
    basicRFConfig_Init();

    while (1)
    {

        //判断有无数据待接收
        if (basicRfPacketIsReady())
        {
            //basicRfReceive 返回 实际接收的数据长度
            uint8 len = basicRfReceive(receive_data, MAX_LEN, NULL);
            int8 show_buff[MAX_LEN] = {0};
            GetHexStr(receive_data, len, show_buff);
            uart_printf("接收的数据为： %s \r\n", show_buff);

            if (len != receive_data[2] + 1)
            {
                uart_printf("数据接收有误1 \r\n");
            }

            if (CHK(receive_data, receive_data[2]) != receive_data[len - 1])
            {
                uart_printf("数据接收有误2 \r\n");
            }
            if (receive_data[3] == 1)
            {
                if (receive_data[4] == SENSOR_FIRE)
                {
                    uint16 fire_num = receive_data[5];
                    fire_num <<= 8;
                    fire_num += receive_data[6];
                    uart_printf("火焰数据为 %d mv \r\n", fire_num);
                }
            }
            if (receive_data[3] == 2)
            {

                if (receive_data[4] == SENSOR_TEMP)
                {
                    uart_printf("这组数据温度为： %d \r\n" ℃, receive_data[5]);
                }
                if (receive_data[6] == SENSOR_RH)
                {
                    uart_printf("这组数据湿度为： %d%%RH \r\n", receive_data[7]);
                }
            }
        }
    }
}