//Judge triangle.c �����������ж��Ƿ񹹳������Σ�����������������
#include "stdio.h"
int main(void)
{
	int a, b, c;                                    //�������
	printf("input three number\n");             //��������ֵ
	while (1)                                    //ѭ��
	{
		scanf_s("%d %d %d", &a, &b, &c);                 //��ȡ����ֵ

		if ((a + b) <= c || (b + c) <= a || (a + c) <= b) //�ж��Ƿ�Ϊ������
		{
			printf("error ���ܹ���������\n");
		}                       //�������������error

		else if (a == b && b == c)                  //�ȱ��������ж�����
		{
			printf("��������Ϊ�ȱ�������\n");
		}

		else if (a == b || b == c || a == c)         //�����������ж�����
		{
			printf("��������Ϊ����������\n");
		}

		else if (a == b || b == c || a == c && (a * a + b * b) == c * c || (b * b + c * c) == a * a || (a * a + c * c) == b * b)
		{
			printf("��������Ϊ����ֱ��������\n");
		}

		else if ((a * a + b * b) == c * c || (b * b + c * c) == a * a || (a * a + c * c) == b * b)
		{
			printf("��������Ϊֱ��������\n");
		}

		else if ((a * a + b * b) > c* c || (b * b + c * c) > a* a || (a * a + c * c) > b* b)
		{
			printf("��������Ϊ���������\n");
		}

		else if ((a * a + b * b) < c * c || (b * b + c * c) < a * a || (a * a + c * c) < b * b)
		{
			printf("��������Ϊ�۽�������\n");
		}
	}
}
