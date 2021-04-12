#include <stdio.h>
/* count lines in input */
main()
{
    int c;
    int nl = 0;
    while ((c = getchar()) != EOF)
            ++nl;
    printf("%d\n", nl);
}
