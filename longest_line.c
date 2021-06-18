// Ritchie, D. and Kernighan, W. (1988) p30

#include "KnR_getline.h"

int KnR_main()
{  /* print the longest input line */

    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = KnR_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("%s", longest);
    return 0;
}


//original

int main()
{   /* print the longest input line */

    int len, dumlen;
    int max = 0;
    char line[MAXLINE];
    char dummy[MAXLINE];
    char longest[MAXLINE];

    while ((len = KnR_getline(line, MAXLINE)) > 0)
    {
        if (len == MAXLINE-1 && line[MAXLINE-2] != '\n')
        {   
            line[MAXLINE-1] = '\n'; line[MAXLINE] = '\0';
            do {
            	len += (dumlen = KnR_getline(dummy, MAXLINE));
            } while(dummy[dumlen-1] != '\n');
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("%d: %s", max, longest);
    return 0;
}
