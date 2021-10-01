#include <stdio.h>
#include "numerals.h"

int main(int argc, char *argv[])
{
    bcd a[]={{1,7},{0,6}}, b[]={{0,3},{0,5}};
    printf("%d\n",binarise(a, 2)+binarise(b, 2));
    bcd c[3];
    reveal(decimise(620, c),3);

    FILE *codex;
    codex = fopen("try.c","r");

    return 0;
}
