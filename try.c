#include <stdio.h>
#include "add_remove-string.lb.c"

int main(int argc, char *argv[])
{
    char s[]="molon ";
    char sh[]="labe! ";
    printf("%s\n",ptr_strcat(s,sh));
    printf("%d\n",strend("vga\0brr","ga"));
    char *t= "atzmi";
    t=alt_strncpy(t, "ani", 3);
    printf("%s\n",t);
    t = alt_strncat(t," veatzmi",7);
    printf("%s\n",t);
    printf("%d\n",alt_strncmp("vfb","vga",2));


    return 0;

}
