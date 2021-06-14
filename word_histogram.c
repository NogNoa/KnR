#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MXWRD 0x20
static inline _Bool unblank(char c)
{
	return c != ' ' && c != '\n' && c != '\t';
}


int measure(int hest[]);
void expose(int hest[], int mxlen);
void mkrow(char row[], int len);

int main()
{
	int mxlen, hest[(MXWRD)];

	mxlen = measure(hest);
    
	expose(hest, mxlen);

	return 0;
}

int measure(int hest[])
{
	int i;
	char c,prev='\n';
	int len = 0;
    int mxlen = 0;

	for (i = 0; i<(MXWRD); ++i)
		hest[i] = 0;

	while ((c = getchar()) != EOF) {
		if (unblank(c)){
			++len;
		}
		else if (unblank(prev)){
			++hest[len];
			if (len > mxlen)
                mxlen = len;
			len = 0;
		}
		prev=c;
	}
    return mxlen;
}

void expose(int hest[], int mxlen)
{
	int i;
	//char plus;
	char row[0x300];

	for (i=1; i<=(mxlen); ++i){
		mkrow(row, hest[i]);
		printf("%2d  %s\n",i, row);
	}
}

void mkrow(char row[], int len)
{
	int j;
	for (j=0; j<len; ++j)
		row[j] ='|';
	row[j] = '\0';
}
