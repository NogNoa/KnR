#include <stdio.h>

void putstar(char c, int lim)
{
    int j;
    
    for (j=0; j<=lim;++j)
        putchar(c);
    putchar('*');
}

int main()
{
    int i;
    
    for (i=7; i>1; --i){
        putstar(' ',i);
        if (4 >= i){
            putstar('\b',2 * i - 4);
        }
        putchar('\n');
    }
}


//gap = 2 * (i - 2)
//i - gap = i - 2i + 4 = 4 - i
//gap == 2i - 4; gap/2 + 2 == i; (4 > i) == (4 > gap/2 + 2) == (2 > gap/2) == (4 > gap)
