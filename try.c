#include <stdio.h>
#include <stdlib.h>
#include "add_remove-string.lb.c"

int main(int argc, char *argv[])
{
    char s[]="molon ";
    char sh[]="labe! ";
    printf("%s\n",alt_strcat(s,sh));
    printf("%d\n",strend("vga\0brr","ga"));
    char *t = malloc(1024);
    t=alt_strncpy(t, "atzmi", 6);
    printf("%s\n",alt_strncpy(t, "ani", 3));
    t = alt_strncat(t," veatzmi",7);
    printf("%s\n",t);
    printf("%d\n",alt_strncmp("vfb","vga",2));

    return 0;

}
