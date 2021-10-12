#include <stdio.h>
#include <stddef.h>

void *KnR_malloc(unsigned nbytes);
void free(void *ap);

int main(int argc, char *argv[])
{
    int *a, *b;
    
    a = KnR_malloc(sizeof(int));
    b = KnR_malloc(sizeof(int));
    free(a);
    *a=6;
    a = KnR_malloc(3);
    *a = 0x006968;
    char c[3]= (char *) a;
    printf("%s\n",c);
}
