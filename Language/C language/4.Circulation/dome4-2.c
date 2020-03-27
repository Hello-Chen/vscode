/* 加法表 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, val;
    printf("请输入一个数：");
    scanf("%d", &val);
    for (i = 0, j = val; i < val; i++, j--)
    {
        printf("%d+%d=%d\n", i, j, i + j);
    }

    system("pause");
}