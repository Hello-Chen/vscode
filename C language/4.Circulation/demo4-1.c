/* 循环输入某同学专业阶段考试的5门课成绩，并计算平均分 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    float count=0,sum=0;
    for ( i = 0; i < 5; i++)
    {
        printf("请输入第%d成绩",i+1);
        scanf("%f",&count);
        sum+=count;
    }

    printf("平均分为：%f",sum/5);
    system("pause");
}