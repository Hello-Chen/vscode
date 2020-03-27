#include "ioCC2530.h"
#include "hal_defs.h"  
#include "hal_cc8051.h"  
#include "hal_int.h"  
#include "hal_mcu.h"  
#include "hal_board.h"  
#include "hal_led.h"  
#include "hal_adc.h"  
#include "hal_rf.h"  
#include "basic_rf.h"  
#include "hal_uart.h"   
#include "TIMER.h"  
#include "get_adc.h"  
#include "sh10.h"  
#include "UART_PRINT.h"  
#include "util.h"  
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>  
#include <math.h>

/*点对点通讯地址设置*/
#define RF_CHANNEL                16         // 频道 11~26  
#define PAN_ID                    0xD0C2     //网络id  
#define MY_ADDR                   0xC2BD     //本机模块地址
#define SEND_ADDR                 0xB4F3     //发送地址
/* 自定义消息格式 */
#define START_HEAD    0xCC//帧头
#define CMD_READ      0x01//读传感器数据
#define SENSOR_TEMP   0x01//温度
#define SENSOR_RH     0x02//湿度
#define SENSOR_FIRE   0x03//火焰
/*  LED n 闪烁 time 毫秒 宏 */
#define FlashLed(n,time) do{\
                   halLedSet(n);\
                   halMcuWaitMs(time);\
                   halLedClear(n);\
                   }while(0)
/*数组大小*/
#define MAX_SEND_BUF_LEN  128 //无线数据最大发送长度
#define MAX_RECV_BUF_LEN  128 //无线数据最大接收长度


int main(void){

}