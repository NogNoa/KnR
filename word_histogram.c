#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MXWRD 30

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
	int i,c;
	int len = 0;
    int mxlen = 0;
	int state = OUT;

	for (i = 0; i<(MXWRD); ++i)
		hest[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t'){
			state = IN;
			++len;
		}
		else if (state == IN){
			++hest[len];
			if (len > mxlen)
                mxlen = len;
			state = OUT;
			len = 0;
		}
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
