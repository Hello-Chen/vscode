//Hellochen.c 英寸转换为厘米
#include <stdio.h>
//#pragma warning(disable:4996)
//设置SDl代码安全检查，解决scanf返回值错误问题，或用scanf_s
int main(void)
{
	double inch, centimeter;

	printf("请输入要转换的英寸值\n");
	scanf("%lf",&inch);
	centimeter = inch * 2.54;
	printf("%lf", centimeter);

	return 0;
}