#include <stdio.h>

double celsius(int fahr)
{
	return (5.0/9.0) * (fahr-32);
}

void main()
{
	int fahr;
	float lower = 0, upper = 300, step = 20;

    for (fahr = lower; fahr <= upper; fahr = fahr + step)
        printf("%3df %6.1fc\n", fahr, celsius(fahr));;
}
