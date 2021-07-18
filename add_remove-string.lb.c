// Ritchie, D. and Kernighan, W. (1988) p45

char * squeeze(char s[], int c)
{ /* squeeze: delete all c from s */
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
	return s;
}

char * KnR_strcat(char s[], char t[])
{ /* strcat: concatenate t to end of s; s must be big enough */
	int i, j;

	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
	return s;
}

// Ritchie, D. and Kernighan, W. (1988) p64

int strindex_1st(char s[], char t[])
{	/* strindex: return index of t in s, -1 if none */
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

// original

char * set(char s[]);

char * squeeze_multi(char s1[], char s2[])
{ /* squeeze multi: delete any characters from s2 in s1 */
	int i, j;
	_Bool cp;

	set(s2);
	for (i = j = 0; s1[i] != '\0'; i++)
	{
		cp = 1;
		for (int k = 0;s2[k] != '\0';k++)
		{
			if (s1[i] == s2[k])
			{
				cp = 0;
				break;
			}
		}
		if (cp)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
	return s1;
}

int any(char s1[], char s2[])
{ /* any: return the first time a character from s2 appears in s1 */
	
	set(s2);
	for (int i = 0;s1[1] != '\0';i++)
	{
		for (int k = 0;s2[k] != '\0';k++)
			if (s1[i] == s2[k])
				return i;
	}
	return -1; 
}

/* todo: for some reason in any() s1 includes both s2 and one space character (regardless of how many were entered at console),
such that instead of -1 on fail, the function returns the index of the start of s2
*/

char * set(char s[])
{ /* set: delete any repetition in s */
	int i, j;
	_Bool cp;

	for (i = j = 0; s[i] != '\0'; i++)
	{
		cp = 1;
		for (int k = 0;k<j;k++)
		{
			if (s[i] == s[k])
			{
				cp = 0;
				break;
			}
		}
		if (cp)
			s[j++] = s[i];
	}
	s[j] = '\0';
	return s;
}

int charindex_last(char s[],char t)
{ //returns the position of the rightmost occurrence of t in s
	int back=-1;
	char c;

	for (int i=0;(c=s[i]) != 0;++i)
	{	if (c==t)
			back=i;
	}
	return back;

}

int charindex_1st(char s[],char t)
{ //returns the position of the rightmost occurrence of t in s
	char c;
	int i=0;

	for (;(c=s[i]) != 0;++i)
	{	if (c==t)
			return i;
	}
	return -1;

}

int strindex_last(char s[], char t[])
{	/* strindex: return index of last t in s, -1 if none */
	int i, j, k,back=-1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			back=i;
	}
	return back;
}

_Bool compare(char s[], char sh[])
{ /* check if two strings are identical */
	int i,j;

	for(i=0;s[i] == ' '|| s[i] == '\t';i++)
		{}
	for(j=0;sh[j] == ' '|| sh[j] == '\t';j++)
		{}
	for (; s[i] == sh[j]; i++,j++)
		{}
	if (sh[j] == '\0')
		return 1;
	else
		return 0;
}

#define swap(t,x,y) \
	t temp=x;		 \
	x = y; 			  \
	y= temp;
#undef swap
