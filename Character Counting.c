#include <stdio.h>
/* count lines in input */
int main()
{
    int c, nl = 0;
    while ((c = getchar()) != EOF)
            ++nl;
    printf("%d\n", nl);
    return 0;
}
