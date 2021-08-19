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
		tokentype=c='EOF'
	dirdcl(0)
		fprintf(stderr,"error: expected name or (dcl)\n");
printf("daytab:\n")

input="char **argv\n"
getttoken()
	token=*p="char"
out=""
dirdcl(1)
	datatype="char"
	getttoken()
		tokentype=c=*
dcl(0)
