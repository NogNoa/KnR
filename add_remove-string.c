// Ritchie, D. and Kernighan, W. (1988) p45

void squeeze(char s[], int c)
{ /* squeeze: delete all c from s */
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void strcat(char s[], char t[])
{ /* strcat: concatenate t to end of s; s must be big enough */
	int i, j;

	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}

