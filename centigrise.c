#include <stdio.h>
#include <stdlib.h>

double celsius(int fahr)
{
	return (5.0/9.0) * (fahr-32);
}

int main(int argc, char *argv[])
{
	float lower = 0;
	
	float upper = (argc > 1) ? atof(argv[1]) : 300;
	float step  = (argc > 2) ? atof(argv[2]) :  20;

    for (float fahr = lower; fahr <= upper; fahr = fahr + step)
        printf("%3.ff %6.1fc\n", fahr, celsius(fahr));

    return 0;
}
