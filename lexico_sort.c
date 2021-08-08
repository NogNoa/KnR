// Ritchie, D. and Kernighan, W. (1988) p97

#include <string.h>
#include "KnR_getline.h"
#define MAXLINES 5120 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *snglptr);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
#define MAXLEN 1024 /* max length of any input line */

int main()
{	/* sort input lines */
	int nlines; /* number of input lines re'd */
	char buffer[MAXLEN];
	if ((nlines = readlines(lineptr, MAXLINES,buffer)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big and scary to sort\n");
		return 1;
	}
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
	{	if (nlines >= maxlines || (p+=len) == NULL)
			return -1;
		else {
			if (line[len-1] == '\n')
				line[len-1] =  '\0'; /* delete newline */
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

void swap(char *v[], int i, int j)
{ /* swap: interchange v[i] and v[j] */
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(char *v[], int left, int right)
{ /* qsort: sort v[left]...v[right] into increasing order */
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) /* do nothing if array contains */
		return; /* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}