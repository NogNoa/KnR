#include <stdio.h>
int atoi(char s[]);

void putstar(int lim)
{
    int j;
    
    for (j=0; j<=lim;++j)
        putchar(' ');
    putchar('*');
}

int main(int argc, char * argv[])
{
    int i, height;
    
    height = (argc > 1) ? atoi(argv[1]) : 6;
    int sub_height = height/2;
    
    for (i=height; i>0; --i){
        putstar(sub_height+i);
        if (sub_height >= i){
            putchar('\r');
            putstar(sub_height-i+2);
        }
        putchar('\n');
    }
}


//gap = 2 * (i - 1)
//i - gap = i - 2i + 2 = 2 - i
//gap == 2i - 2; gap/2 + 1 == i; (3 > i) == (3 > gap/2 + 1) == (1 > gap/2) == (2 > gap)
//sublim=num(spaces)+num(1st *)-num(\b)=sub_height+i+1-(2 * i - 2)=sub_height-i+3
