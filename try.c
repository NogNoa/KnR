#include <stdio.h>
#include <stddef.h>
#include <limits.h>

void *KnR_malloc(unsigned nbytes);
void *dep_calloc(long unsigned const n, size_t size);
void free(void *ap);

int main(int argc, char *argv[])
{
    int *a, *b;
    
    a = KnR_malloc(UINT_MAX - 32);
    b = dep_calloc(2,sizeof(int));
    free(a);
    *a=6;
    a = KnR_malloc(3);
    *a = 0x006968;
    char *c= (char *) a;
    b[0]=12;
    b[1]=3;
    printf("%s: %d\n",c,b[0]*b[1]);
}
