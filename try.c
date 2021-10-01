#include <stdio.h>
#include "istable.lb.h"

int main(int argc, char *argv[])
{
    tis_init();
    printf("%d", tisprint(';'));
    printf("%d\n", tisprint(' '));
    return 0;
}
