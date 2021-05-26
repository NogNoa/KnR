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

char * strcat(char s[], char t[])
{ /* strcat: concatenate t to end of s; s must be big enough */
	int i, j;

	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
	return s;
}

// original

char * squeeze_multi(char s1[], char s2[])
{ /* squeeze multi: delete any charecters from s2 in s1 */
	int i, j;
	_Bool cp;

	for (i = j = 0; s1[i] != '\0'; i++)
	{
		cp = 1;
		for (int k = 0;s2[k] != '\0';j++)
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
