#include <stdio.h>
int atoi(char s[]);

void putstar(char c, int lim)
{
    int j;
    
    for (j=0; j<=lim;++j)
        putchar(c);
    putchar('*');
}

int main(int argc, char * argv[])
{
    int i, height;
    height = (argc > 1) ? atoi(argv[1]) : 6;
    int sub_height = height/2;
    
    for (i=height; i>0; --i){
        putstar(' ',sub_height+i);
        if (sub_height >= i){
            putstar('\b',2 * i - 2);
        }
        putchar('\n');
    }
}


//gap = 2 * (i - 2)
//i - gap = i - 2i + 4 = 4 - i
//gap == 2i - 4; gap/2 + 2 == i; (4 > i) == (4 > gap/2 + 2) == (2 > gap/2) == (4 > gap)
