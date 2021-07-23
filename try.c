#include <stdio.h>
#include "add_remove-string.lb.c"


int main(int argc, char *argv[])
{
    char s[]="molon ";
    char sh[]="labe! ";
    printf("%s\n",ptr_strcat(s,sh));
    printf("%d\n",strend("vga\0brr","ga"));
    //char *t="ani";
    //char *v="atzmi";
    //printf("%s\n",alt_strncpy(t,v,1));
    printf("%d\n",alt_strncmp("vfb","vga",2));
    //printf("%s\n",alt_strncat("ani"," veatzmi",4));


    return 0;

}
