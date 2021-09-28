#include <stdio.h>
#include "numerals.h"

int main(int argc, char *argv[])
{
    bcd a[]={{1,7},{0,6}, NULL}, b[]={{0,3},{0,5}, NULL};
    printf("%d\n",binarise(a, 4)+binarise(b, 4));

    return 0;
}
