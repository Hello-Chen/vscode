/* 计算1+1/2+1/3+1/4...+1/n */
/* 计算1-1/2+1/3-1/4...+1/n */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,i = 1;
    int cnt = 1;
    float sum=0;
    scanf("%d", &n);
    for( i = 1; i <= n; i++)
    {
        sum += cnt*1.0 / i;
        cnt = -cnt;
    }
    printf("f(%d)=%f",n, sum);
    system("pause");
}