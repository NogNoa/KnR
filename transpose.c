#include <stdio.h>
#define MAX 1024

void linearise(char * lini[])
int KnR_getline(char s[], int lim)
void expose(char * lini[])

int KnR_getline(char s[], int lim)
{  /* read a line into s, return lenght
    imported as is from longest_line.c*/

	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c== '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void expose(char * lini[], nline)
{
    char line[Max]= '\0';

    do{
        for (i=0; i <= nline; ++i){
            for (j=0)
        }

        }while (line != '\0')
}


void linearise(char * lini[])
    int len, i;
    char line[MAX];

    for (i=0; (len = KnR_getline(line, MAX)) > 0; ++i)
        lini[i] = line;
    return (i)


void main()
{
    char * lini[MAX];
    int nline;

    nline = liearise(lini);

}
