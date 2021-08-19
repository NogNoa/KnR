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
		cont = 0;
	fprintf(stderr,"error: missing ) at typedcl\n");
dcl(0)
	gettoken()
		tokentype=c='*'
	gettoken()
		token=*p="do"
		tokentype=NAME
	dirdcl()
		name="do"
		gettoken()
			tokentype=c=')'
	out = " pointer to"
fprintf(stderr,"syntax error %d %c\n", tokentype, tokentype);
printf("do: pointer to char\n")
out=""
getttoken()
	tokentype=c=EOF
typedcl()
	fprintf(stderr,"error: expected typename\n");
dcl(0)
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
