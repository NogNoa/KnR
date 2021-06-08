void escape(char s[], char t[])
{
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
{
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
