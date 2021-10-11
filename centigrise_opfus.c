#include <stdlib.h>

int main(int argc, char *argv[]) {for (float fahr = 0;
fahr <= ((argc > 1) ? atof(argv[1]) : 300); fahr = fahr\
+ ((argc > 2) ? atof(argv[2]) :  20)) printf("%3.ff %6.1fc\n",\
fahr, (5.0/9.0) * (fahr-32)); return 0;}
