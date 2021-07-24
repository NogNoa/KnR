#include <stdio.h>
#include <stdlib.h>
#include "KnR_getline.lb.c"
#include "stoi.lb.c"
#include "control_flow.lb.c"


int main(int argc, char *argv[])
{
    char *s=malloc(1024);
    int i=ptr_KnR_getline(s,128);
    printf("%s %d\n",s,i);
    s=itob(i,18);
    printf("%s %d\n",s,btoi("128",16));

    return 0;

}
