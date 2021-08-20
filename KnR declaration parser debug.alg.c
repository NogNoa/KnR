input="( )"
getttoken()
	*p=token[o200]
	tokentype=c='('
typedcl()
	getttoken()
		tokentype=c= ")"
	typedcl()
		fprintf(stderr,"error: expected typename\n");
		ungettoken(')')
		dcl()
			getttoken()
				tokentype=c= ")"
			dirdcl()
				fprintf(stderr,"error: expected name or (dcl)\n");
				ungettoken(')')
				gettoken()
					tokentype=c=')'
	gettoken()
		tokentype=c='\n'
print(":")

input="("
getttoken()
	*p=token[o200]
	tokentype=c='('
typedcl()
	getttoken()
		tokentype=c= "\n"
	typedcl()
		fprintf(stderr,"error: expected typename\n");
		ungettoken('\n')
		dcl()
			getttoken()
				tokentype=c= '\n'
			dirdcl()
	fprintf(stderr,"error: missing ) at typedcl\n");
	ungettoken('\n');
print(":")

input="( ( ) )"
getttoken()
	*p=token[o200]
	tokentype=c='('
typedcl()
	getttoken()
		tokentype=c= "("
	typedcl()
		getttoken()
			tokentype=c= ")"
		typedcl()
			fprintf(stderr,"error: expected typename\n");
			ungettoken(')')
			dcl()
				getttoken()
					tokentype=c= ")"
				dirdcl()
					fprintf(stderr,"error: expected name or (dcl)\n");
					ungettoken(')')
					gettoken()
						tokentype=c=')'
		gettoken()
			tokentype=c=')'
	gettoken()
		tokentype=c="\n"
print(":")

input="char **argv\n"
getttoken()
	token=*p="char"
out=""
dirdcl(1)
	datatype="char"
	getttoken()
		tokentype=c=*
dcl(0)
