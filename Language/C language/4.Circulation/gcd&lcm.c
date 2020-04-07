/* gcd & lcm
1.枚举算法：
先判断两个变量谁最大
对两个变量取余，直到两个变量都能被整除
2.辗转相除：
如果b不等于0，计算结束，a就是最大公约数
否则，计算a除以b的余数，让a等于b，而b等于那个余数
回到第一步
3.lcm=两个变量乘积/gcd
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*int a, b, min;
    scanf("%d %d",&a,&b);
    if (a < b)
    {
        min = a;
    }
    else
    {
        min = b;
    }
    int i, x;
    for (i = 1; i < min; i++)
    {
        if (a % i == 0)
        {
            if (b % i == 0)
            {
                x = i;
            }
        }
    }
    printf("%d和%d最大公约数是%d", a, b, x); */

    int a, b, c,x;
    scanf("%d %d", &a, &b);
    x = a * b;
    while (b!=0)
    {
        c=a % b;
        a = b;
        b = c;
    printf("a=%4d  b=%4d  c=%4d\n", a, b, c);
    }
    printf("gcd=%d lcm=%d",a,x/a);
    system("pause");
}