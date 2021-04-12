#include <cstdio>
int fahr;
float lower, upper, step, celsius;

main()
{
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr-32);
        printf("%3df %6.1fc\n", fahr, celsius);
        fahr = fahr + step;
    }
}
