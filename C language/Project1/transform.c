//Hellochen.c Ӣ��ת��Ϊ����
#include <stdio.h>
//#pragma warning(disable:4996)
//����SDl���밲ȫ��飬���scanf����ֵ�������⣬����scanf_s
int main(void)
{
	double inch, centimeter;

	printf("������Ҫת����Ӣ��ֵ\n");
	scanf("%lf",&inch);
	centimeter = inch * 2.54;
	printf("%lf", centimeter);

	return 0;
}