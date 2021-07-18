#include <string.h>

// Ritchie, D. and Kernighan, W. (1988) p54

int KnR_binsearch(int x, int v[], int n)
{ /* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}

// Ritchie, D. and Kernighan, W. (1988) p57

void reverse(char s[])
{ /* reverse: reverse string s in place */
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


//Original

void escape(char s[], char t[])
{ //replace any special character with it's escape equivalent
	char c;
	int j = 0;
	for (int i=0;(c = t[i]) != 0;++i){
		switch(c){
		case '\n':
			s[j++] = '\\'; s[j++] = 'n';break;
		case '\t':
			s[j++] = '\\'; s[j++] = 't';break;
		case '\b':
			s[j++] = '\\'; s[j++] = 'b';break;
		case '\v':
			s[j++] = '\\'; s[j++] = 'v';break;
		case '\f':
			s[j++] = '\\'; s[j++] = 'f';break;
		case '\r':
			s[j++] = '\\'; s[j++] = 'r';break;
		case '%':
			s[j++] = '%' ; s[j++] = '%';break;
		case '\'':
		case '\"':
		case '\\':
			s[j++] = '\\'; s[j++] = c;break;
		default:
			s[j++] = c;break;
		}
	}
	s[j] = 0;
}

void descape(char s[], char t[])
{ //replace any escape character with it's special character equivalent
	char c;
	int j = 0;
	for (int i=0;(c = t[i]) != 0;++i){
		switch(c){
		case '\\':
			switch (t[++i]){
			case 'n':
				s[j++] = '\n';break;
			case 't':
				s[j++] = '\t';break;
			case 'b':
				s[j++] = '\b';break;
			case 'v':
				s[j++] = '\v';break;
			case 'f':
				s[j++] = '\f';break;
			case 'r':
				s[j++] = '\r';break;
			case '\'':
			case '\"':
			case '\\':
				s[j++] = t[i];break;
			default:
				s[j++] = '\\';s[j++] = t[i];break;
			}
			break;
		default:
			s[j++] = c;break;
		}
	}
	s[j] = 0;
}

void expand(char s1[],char s2[])
{	// parse shorthand of the type a-z
	int j=0;
	char init, finit;
	s1[-1]='\r'; //we need a -1st case
	
	for (int i=-1;s1[i] != 0;++i)
	{	if (s1[i+1] == '-')
		{	init = s1[i];
			finit = s1[i+2];
			if (init<'!') // first non-blank printable
			{	init = '!'; 
				s2[j++] = s1[i];
			}
			if (finit<'!')
				finit = 0x7e; 
				//Last printable. In modernity it's supposed to always be '~'
				//But this program is should also work correctly with 
				//1965 ascii that ends z{¬}| rather than z{|}~
			if (init>finit)
				for(char k=init;k>=finit;--k)
					s2[j++] = k;
			else 
				for(char k=init;k<=finit;++k)
					s2[j++] = k;
			if (finit == s1[i+2] && s1[i+3] != '-')
				i++;
			i++;
		}
		else
			s2[j++] = s1[i];
	}
	s2[j]=0;

}

/*	v SOF-
	v -EOF 
	v -- 	behaviour: the second - is used as literal and doesn't cause expansion
	v !---A behaviour: acts as !-- and than --A
	v " -A" == " !"#$%&'()*+,-...A"
	v "z- " == "z{|}~ "
	v a-b-c 
	v c-a 	behaviour: expands to nothing.
*/

int binsearch(int x, int v[], int n)
{ /* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else
			low = mid + 1;
	}
	if (low == high)
		return low; //match
	else 
		return -1; // no match
}
/*
assume   high = (low+high)/2 + 1; x = v[(low+high)/2] 
happen	{high/2 = low/2 + 1
	   	 high = low + 2}
than    {(low < high)
	       mid = high - 1
	       x >= v[mid]
	       low = mid + 1 = high
	     (low >= high)
	     ...}
than 	 (x == v[mid]) iff (low == high)
*/

void real_recrs_reverse(int i, char s[])
{ /* reverse: reverse string s in place using recursion */
	static int len, middle;
	int temp, alt;
	if (s[i] != '\0')
		real_recrs_reverse(i+1, s);
	else
	{	len=i;
		middle=len / 2;
	}
	if (i<middle)
	{	alt = len - i -1;
		temp=s[i];
		s[i]=s[alt];
		s[alt]=temp;
	}
}

inline void recrs_reverse(char s[])
{
	real_recrs_reverse(0,s);
}
