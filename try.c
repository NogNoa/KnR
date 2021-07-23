#include <stdio.h>
#include "add_remove-string.lb.c"


int main(int argc, char *argv[])
{
    char s[]="molon ";
    char sh[]="labe! ";
    printf("%s\n",ptr_strcat(s,sh));
    printf("%d\n",strend("vga\0brr","ga"));
    //char *v="atzmi";
    printf("%s\n",alt_strncpy("ani","atzmi",4));
    char *t= "ani";
    alt_strncat(t," veatzmi",6);
    printf("%s\n",t);
    printf("%d\n",alt_strncmp("vfb","vga",2));


    return 0;

}
