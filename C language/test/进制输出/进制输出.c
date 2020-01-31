#include <stdio.h>

int main(void)
{
	int x = 100;

	printf("dec=%d ;octel=%o; hex=%x\n", x, x, x);
	printf("dec=%d; octel=%#o; hex=%#x\n",x,x,x);
}