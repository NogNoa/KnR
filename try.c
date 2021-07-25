#include <stdio.h>
#include <stdlib.h>
#include "KnR_getline.lb.c"
#include "stoi.lb.c"
#include "control_flow.lb.c"
#include "add_remove-string.lb.c"


int main(int argc, char *argv[])
{
    char *s=malloc(1024);
    s=itob(i,18);
    printf("%s %d\n",s,btoi("128",16));
    i=charindex_1st("char *calls",'a');
    int j=strindex_last("abanibiabonibe", "ib");
    printf("%x %x\n",i,j);

    return 0;

}
