/* Programming Exercise 5-1 */
#include <stdio.h>
#include "stdlib.h"
int main(void)
{
    const int minperhour = 60;
    int minutes, hours, mins;
    printf("Enter the number of minutes to convert: ");
    scanf("%d", &minutes);
    while (minutes > 0)
    {
        hours = minutes / minperhour;
        mins = minutes % minperhour;
        printf("%d minutes = %d hours, %d minutes\n", minutes, hours, mins);
        printf("Enter next minutes value (0 to quit): ");
        scanf("%d", &minutes);
    }
    printf("Bye\n");
    system("pause");
}