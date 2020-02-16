//Judge triangle.c 输入三个数判断是否构成三角形，构成怎样的三角形
#include "stdio.h"
int main(void)
{
	int a, b, c;                                    //定义变量
	printf("input three number\n");             //输入三个值
	while (1)                                    //循环
	{
		scanf_s("%d %d %d", &a, &b, &c);                 //获取三个值

		if ((a + b) <= c || (b + c) <= a || (a + c) <= b) //判断是否为三角形
		{
			printf("error 不能构成三角形\n");
		}                       //不是三角形输出error

		else if (a == b && b == c)                  //等边三角形判断条件
		{
			printf("此三角形为等边三角形\n");
		}

		else if (a == b || b == c || a == c)         //等腰三角形判断条件
		{
			printf("此三角形为等腰三角形\n");
		}

		else if (a == b || b == c || a == c && (a * a + b * b) == c * c || (b * b + c * c) == a * a || (a * a + c * c) == b * b)
		{
			printf("此三角形为等腰直角三角形\n");
		}

		else if ((a * a + b * b) == c * c || (b * b + c * c) == a * a || (a * a + c * c) == b * b)
		{
			printf("此三角形为直角三角形\n");
		}

		else if ((a * a + b * b) > c* c || (b * b + c * c) > a* a || (a * a + c * c) > b* b)
		{
			printf("此三角形为锐角三角形\n");
		}

		else if ((a * a + b * b) < c * c || (b * b + c * c) < a * a || (a * a + c * c) < b * b)
		{
			printf("此三角形为钝角三角形\n");
		}
	}
}
