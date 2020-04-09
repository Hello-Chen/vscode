/*  判断数的位数 */
#include <stdio.h>

int main()
{
    int a, cnt = 0;
    scanf("%d", &a);
    cnt++;
    a /= 10;
    while (a > 0)
    {
        cnt++;
        a /= 10;
    }
    printf("%d", cnt);

    return 0;
}