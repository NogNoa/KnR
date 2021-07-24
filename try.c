#include <stdio.h>
#include "KnR_getline.lb.c"
#include "stoi.lb.c"
#include "control_flow.lb.c"


int main(int argc, char *argv[])
{
    char *s=0;
    int i=ptr_KnR_getline(s,128);
    printf("%s %d\n",s,i);
    itob(i,s,18);
    printf("%s %d\n",s,atoi("128"));

    return 0;

}
