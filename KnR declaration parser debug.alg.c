input="(char *do)"
getttoken()
	*p=token[o200]
	tokentype=c='('
typedcl()
	getttoken()
		token="char"
		tokentype = NAME
	typedcl()
		datatype = "char"
	getttoken()
		tokentype=c='*'
	fprintf(stderr,"error: missing ) at typedcl\n");
dcl(0)
	getttoken()
		token=*p="do"
		tokentype=NAME
	dirdcl(0)
		name="do"
		getttoken()
			tokentype=c=')'
fprintf(stderr,"syntax error %d %c\n", tokentype, tokentype);
printf("do: char\n")
typedcl()
	fprintf(stderr,"error: expected typename\n");
dcl(0)
	getttoken()
	 tokentype=c=EOF
dirdcl()
	fprintf(stderr,"error: expected name or (dcl)\n");

input="char **argv\n"
getttoken()
	token=*p="char"
out=""
dirdcl(1)
	datatype="char"
	getttoken()
		tokentype=c=*
dcl(0)
