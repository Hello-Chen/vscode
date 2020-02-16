/* print ASC II */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    for (a = 32; a < 256; a++)
    {
        printf("%c => %d\t", a, a);
    }
    system("pause");
}