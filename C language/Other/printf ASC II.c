/* print ASC II */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    for (a = 65; a < 128; a++)
    {
        printf("%c =: %d\t", a, a);
    }
    system("pause");
}