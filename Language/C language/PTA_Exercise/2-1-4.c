/* 已知某位学生的数学、英语和计算机课程的成绩分别是87分、72分和93分，求该生3门课程的平均成绩（结果按整型输出）。 */
/* math = 87, eng = 72, comp = 93, average = 计算所得的平均成绩 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 0,math = 87, eng = 72, comp = 93;
    a = (math + eng + comp) / 3;
    printf("math = %d, eng = %d, comp = %d, average =%d",math, eng, comp,a);
    system("pause");
    return 0;
}