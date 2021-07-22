#include <stdio.h>
#include "add_remove-string.lb.c"


int main(int argc, char *argv[])
{
    char s[]="molon ";
    char sh[]="labe! ";
    printf("%s\n",ptr_strcat(s,sh));
    printf("%d\n",strend("ga\0brr","m"));

    return 0;

}
