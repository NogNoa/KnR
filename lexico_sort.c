// Ritchie, D. and Kernighan, W. (1988) p97
// Ritchie, D. and Kernighan, W. (1988) p106

#include "KnR_getline.h"
#include <ctype.h>
#define MAXLINES 5120 /* max #lines to be sorted */
#define MAXLEN 1024 /* max length of any input line */

char *lineptr[MAXLINES][MAXLEN/2]; /* pointers to text lines divided to fields*/

static struct state{
_Bool numeric; /* 1 if numeric sort */
_Bool reverse; /* 1 if reverse sort */
_Bool casefld; /* 1 if case insensitive sort */
_Bool dircord; /* 1 if directory order sort */
} linstt ={0,0,0,0};

int readlines(char *lineptr[][], int nlines, int nfield, char *snglptr);
void writelines(char *lineptr[], int nlines);
void KnR_qsort(void *lineptr[], int left, int right,
	int (*comp)(void *, void *, void *), struct state []);
int numcmp(char *s1, char *s2, void *);
int astrcmp (char *s1, char *s2);
int lexcmp(char *cs,char *ct, struct state stt[]);


int main(int argc, char *argv[])
{	/* sort input lines */
	int nlines; /* number of input lines re'd */
	char buffer[MAXLEN];

	stdin = fopen("a.txt", "r");

	int nfield=1;
	char dlimit = '\t';
	if (argv[1][0] == '-' && argv[1][1] == 's')
	{	nfield = argc-2;
		dlimit = argv[1][2];
	}
	struct state stti[nfield];

	for (argv+=argc-1, int nf=nfield;--nf >= 0 && *argv[0] == '-';--argv)
	{	char c;
	
		struct state *stt=&stti[nf];
		*stt=(struct state) {0,0,0,0};
		while ((c = *++(argv[0])))
		{	stt->numeric |= (c == 'n');
			stt->reverse |= (c == 'r');
			stt->casefld |= (c == 'f');
			stt->dircord |= (c == 'd');
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES, nfield, buffer)) >= 0) 
	{	KnR_qsort((void**) lineptr, 0, nlines-1,
		(int (*)(void*,void*, void*))(stti[0].numeric ? numcmp : lexcmp), stti);
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

int numcmp(char *s1, char *s2, void* p)
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

int lexcmp(char *cs,char *ct, struct state *stt)
{ /* compare string cs to string ct, disregarding case; return <0 if
     cs<ct, 0 if cs==ct, or >0 if cs>ct. */
	char ccs=1, cct=1;
	for (;ccs == cct && cct;cs++,ct++)
	{	ccs=*cs; cct=*ct;
		if (stt->casefld)
		{	ccs=tolower(ccs);
			cct=tolower(cct);
		}
		if (stt->dircord)
		{	ccs = (isspace(ccs) || isalnum(ccs)) ? ccs : '!';
			cct = (isspace(cct) || isalnum(cct)) ? cct : '!';
		}
	}
	return ccs-cct;
}

#ifndef alloc
	#include "molon.lb.c"
#endif


int readlines(char *lineptr[][], int maxlines, int nfield, char *p)
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
	int (*cmp)(void *, void *, void *),struct state stti[])
{ /* qsort: sort v[left]...v[right] into increasing order */
	int i, last;
	struct state *stt=stti;
	
	void swap(void *v[], int i, int j);

	if (left >= right) /* do nothing if array contains */
		return; 	  /* fewer than two elements      */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (((*cmp)(v[i], v[left], stt) < 0) ^ linstt.reverse)
			swap(v, ++last, i);
	swap(v, left, last);
	KnR_qsort(v,   left, last-1, cmp, stti);
	KnR_qsort(v, last+1,  right, cmp, stti);
}


/*
todo: take argument for delimiter
make state for each field
seperate each line to fields
sort by fields
take different arguments for each field
*/

