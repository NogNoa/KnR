#include <stdio.h>

int main(){
    int cels;

    for (cels = -20; cels <= 150;cels = cels + 10)
        printf("%3d %6.1f\n", cels, (5.0/9.0)*(cels-32));
    return 0;
}
