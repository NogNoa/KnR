// Ritchie, D.M. and Kernighan, B.W. (1988) p30

#include "KnR_getline.h"

int KnR_getline(char s[], int lim)
{  // read a line into s, return length

	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c== '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{  // copy 'from' into 'to'; assume 'to' is big enough

	for (int i = 0;(to[i] = from[i]) != '\0'; ++i)
		;
}

// original

_Bool pascal_getline(char s[], int lim)
{ // give a line with length in the beginning
		// high byte is ones-complement, hence breaks at lengths > 0xFEFF = 65279

	char c;
	int len;

	for (len=2; len < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++len)
		s[len] = c;
	if (c== EOF)
		return 0;
	if (c== '\n') {
		s[len++] = c;
	}
	s[len] = '\0';

	len = (short) len - 2;
	s[1] = len & 0xFF;
	s[0] = (len >> 8) ^ 0xFF ;

	return 1;
}

int ptr_KnR_getline(char *s, int n)
{  // read a line into s, return length

	char c;
	int lim=n;

	for (; n > 1 && (c=getchar()) !=EOF && c!='\n'; n--)
		*s++ = c;
	if (c== '\n') {
		*s++ = c;
	}
	*s = '\0';
	return lim-n;
}

int linearise(void)
{
	char *line,*p; //line: buffer for each line
	int nline,len = 0; //nline: number of lines

	linlen = calloc(MAXLINE, sizeof(int)); //extern array for the length of each line
	lini = calloc(MAXLINE, sizeof(char*));	//extern array of pointers to each line
	mxlen=0;

	size_t* maxline;
    *maxline = MAXLINE;

	for (nline=0; (len = getline(&line, maxline, stdin)) > 0; ++nline)
	{	if (nline >= MAXLINE || (p=malloc(len)) == NULL)
			return -1;
		strncpy(p,line, len);
		lini[nline] = p;
		if (len>mxlen)
			mxlen=len;
		linlen[nline]=len;
	}
	linlen = (int *) realloc(linlen, nline * sizeof(int));
	lini = (char **) realloc(lini, nline * sizeof(char*));
	return nline;
}
