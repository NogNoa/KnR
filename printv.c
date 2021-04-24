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
    int i, gap;
    
    for (i=7; i>1; --i)
    {
        putstar(' ',i);
        gap = 2 * (i - 2);
        if (i - gap >= 0)
            putstar('\b',gap);
        putchar('\n');
    }
}
