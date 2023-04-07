#include <stdio.h>

int main()
{
    float lower = -20, upper = 150, step = 10, fahr;
    int cels = lower;
    
    while (cels <= upper)
    {
        // (9.0/5.0) * celsius + 32 =  fahr;
        fahr = (9.0/5.0) * cels + 32.0;
        printf("%3dc %6.0ff\n", cels, fahr);
        cels = cels + step;
    }
    return 0;
}
