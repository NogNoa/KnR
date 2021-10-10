#include <stdio.h>

void *malloc(unsigned nbytes);
void free(void *ap);

int main(int argc, char *argv[])
{
    int *a;
    a = malloc(sizeof(int));
    printf("%p\n", a);
    free(a);
    printf("%p\n", a);
    *a=6;
    printf("%d\n", *a);
    //a still seems plenty reachable
    printf("%d\n", max_align_t);
}
