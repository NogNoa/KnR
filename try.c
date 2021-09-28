#include <stdio.h>
#include "numerals.h"

int main(int argc, char *argv[])
{
    bcd a[]={{1,7},{0,6}}, b[]={{0,3},{0,5}};
    printf("%d\n",binarise(a, 1)+binarise(b, 1));

    return 0;
}
