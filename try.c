#include <stdio.h>
#include <stddef.h>

void *malloc(unsigned nbytes);
void free(void *ap);

int main(int argc, char *argv[])
{
    int *a, *b;
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    free(a);
    *a=6;
    a = malloc(sizeof(int));
    //a still seems plenty reachable
    printf("%ld\n", sizeof(max_align_t));
    /*It's 32B i.e 356 bits. More than 
    just the size of the biggest types 
    long double and __float128which is 
    just 16B.*/
}
