// Ritchie, D. and Kernighan, W. (1988) p41

int atoi(char s[])
{ /* atoi: convert s to integer */
int i, n;
n = 0;
for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
	n = 10 * n + (s[i] - '0');
return n;
}

// original

int htoi(char s[])
{ /* convert hexadecimal string to integer */
	int n=0;
	char d;
	for (int i=0; s[i] != '\0';++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			d = (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			d = (s[i] - 'A' + 0xA);
		else if (s[i] >= 'a' && s[i] <= 'f')
			d = (s[i] - 'a' + 0xa);
		else
			break;
		n = 16 * n + d;
	}
	return n;
}
