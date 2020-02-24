/* Hello Chen C program */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int hour,minute,minutes,second;
    const int minperhour = 60;
    printf("Please input minute:\n");
    scanf("%d",&minute);

    while (minute >0)
    {
        hour=minute/minperhour;
        minutes=minute%minperhour;
        printf("%d minute = %d hour %d minute\n",minute,hour,minutes);
        printf("Continue typing to convert (input 0 to exit)\n");
        scanf("%d",&minute);
    }
    printf("bye\n");
    system("pause");
}
