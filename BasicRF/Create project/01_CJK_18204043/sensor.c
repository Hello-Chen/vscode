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

/*��Ե�ͨѶ��ַ����*/
#define RF_CHANNEL                16         // Ƶ�� 11~26  
#define PAN_ID                    0xD0C2     //����id  
#define MY_ADDR                   0xC2BD     //����ģ���ַ
#define SEND_ADDR                 0xB4F3     //���͵�ַ
/* �Զ�����Ϣ��ʽ */
#define START_HEAD    0xCC//֡ͷ
#define CMD_READ      0x01//������������
#define SENSOR_TEMP   0x01//�¶�
#define SENSOR_RH     0x02//ʪ��
#define SENSOR_FIRE   0x03//����
/*  LED n ��˸ time ���� �� */
#define FlashLed(n,time) do{\
                   halLedSet(n);\
                   halMcuWaitMs(time);\
                   halLedClear(n);\
                   }while(0)
/*�����С*/
#define MAX_SEND_BUF_LEN  128 //������������ͳ���
#define MAX_RECV_BUF_LEN  128 //�������������ճ���


int main(void){

}