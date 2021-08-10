// Ritchie, D. and Kernighan, W. (1988) p97
// Ritchie, D. and Kernighan, W. (1988) p106

#include "KnR_getline.h"
#include <ctype.h>
#define MAXLINES 5120 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *snglptr);
void writelines(char *lineptr[], int nlines);
void KnR_qsort(void *lineptr[], int left, int right,
	int (*comp)(void *, void *));
int numcmp(char *s1, char *s2);
int astrcmp (char *s1, char *s2);
int lexcmp(char *cs,char *ct);
#define MAXLEN 1024 /* max length of any input line */

_Bool numeric = 0; /* 1 if numeric sort */
_Bool reverse = 0; /* 1 if reverse sort */
_Bool casefld = 0; /* 1 if case insensitive sort */

int main(int argc, char *argv[])
{	/* sort input lines */
	int nlines; /* number of input lines re'd */
	char buffer[MAXLEN];

	
	//stdin = fopen("a.txt", "r");

	while (--argc > 0 && (*++argv)[0] == '-')
	{	char c;
		while ((c = *++argv[0]))
		{	numeric |= (c == 'n');
			reverse |= (c == 'r');
			casefld |= (c == 'f');
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES,buffer)) >= 0) 
	{	KnR_qsort((void**) lineptr, 0, nlines-1,
		(int (*)(void*,void*))(numeric ? numcmp : lexcmp));
		writelines(lineptr, nlines);
		return 0;
	} 
	else 
	{	printf("error: input too big and scary to sort\n");
		return 1;
	}
}

int astrcmp (char* s1, char* s2)
{
	return strcmp(s1, s2);
}

int numcmp(char *s1, char *s2)
{	/* numcmp: compare s1 and s2 numerically */
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int lexcmp(char *cs,char *ct)
{ /* compare string cs to string ct, disregarding case; return <0 if
     cs<ct, 0 if cs==ct, or >0 if cs>ct. */
	char ccs=1, cct=1;
	for (;ccs == cct;cs++,ct++)
	{	ccs=*cs; cct=*ct;
		if (casefld)
		{	ccs=tolower(ccs);
			cct=tolower(cct);
		}
	}
	return ccs-cct;
}

#ifndef alloc
	#include "molon.lb.c"
#endif


int readlines(char *lineptr[], int maxlines,char *p)
{	/* readlines: read input lines */
	int len, nlines;
	char line[MAXLEN];
	nlines = 0;
	while ((len = ptr_KnR_getline(line, MAXLEN)) > 0)
	{	if (nlines >= maxlines || (p+=len+1) == NULL)
			return -1;
		else 
		{	if (line[len] == '\n')
				line[len] =  '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{ /* writelines: write output lines */
	int i;
	for (i = 0; i < nlines; i++)
	printf("%s\n", lineptr[i]);
}

void swap(void *v[], int i, int j)
{ /* swap: interchange v[i] and v[j] */
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void KnR_qsort(void *v[], int left, int right,
	int (*cmp)(void *, void *))
{ /* qsort: sort v[left]...v[right] into increasing order */
	int i, last;
	
	void swap(void *v[], int i, int j);

	if (left >= right) /* do nothing if array contains */
		return; 	  /* fewer than two elements      */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (((*cmp)(v[i], v[left]) < 0) ^ reverse)
			swap(v, ++last, i);
	swap(v, left, last);
	KnR_qsort(v,   left, last-1, cmp);
	KnR_qsort(v, last+1,  right, cmp);
}
