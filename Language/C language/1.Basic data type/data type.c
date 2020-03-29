/* 以十进制打印 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x =100;
    printf("dec=%d;octal=%o;hex=%x\n",x,x,x);
    printf("dec=%d;octal=%#o;hex=%#x\n",x,x,x);

    system("pause");
}

