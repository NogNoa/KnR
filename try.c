#include <stdio.h>
#include "add_remove-string.lb.c"


int main(int argc, char *argv[])
{
    char s[]="molon ";
    char sh[]="labe! ";
    printf("%s\n",ptr_strcat(s,sh));
    printf("%d\n",strend("vga\0brr","ga"));
    char *t="ani";
    //char *v="atzmi";
    alt_strncpy(t,"atzmi",3);
    printf("%s\n",t);
    
    printf("%d\n",alt_strncmp("vfb","vga",2));
    
    t = alt_strncat("ani"," veatzmi",5);
    printf("%s\n",t);


    return 0;

}
