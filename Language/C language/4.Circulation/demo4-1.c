/* ѭ������ĳͬѧרҵ�׶ο��Ե�5�ſγɼ���������ƽ���� */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    float count=0,sum=0;
    for ( i = 0; i < 5; i++)
    {
        printf("�������%d�ɼ�",i+1);
        scanf("%f",&count);
        sum+=count;
    }

    printf("ƽ����Ϊ��%f",sum/5);
    system("pause");
}