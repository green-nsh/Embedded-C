#include <stdio.h>

#define DEBUG
#define VERSION 1.0
#define MULTI(a, b) ((a) * (b))

int main()
{
#ifdef DEBUG
    printf("Debug mode is enabled \n");
    printf("Current version: %.1f \n", VERSION);

    int a = 10, b = 5;
	int c = MULTI(a, b);
    printf("Multiplication of %d and %d is %d \n", a, b, c);
#else
    printf("Debug mode is disabled \n");
#endif
    return 0;
}