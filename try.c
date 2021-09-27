#include <stdio.h>
#include "numerals.h"

int main(int argc, char *argv[])
{
    bcd a={1,7}, b={0,3};
    printf("%d\n",binarise(a)+binarise(b));

    return 0;
}
