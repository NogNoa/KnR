typedef struct {
	unsigned int eight : 1;
	unsigned int rest : 3;
} bcd;

int binarise_single(bcd call)
{
	return (signed) (call.eight) ? (call.rest > 1 ? 10 : 8 + call.rest) : call.rest;
}

int binarise(bcd call[], int len)
{
	;//if (!call)
}

void reveal(bcd call)
{
	printf("%d",binarise_single(call));
}

bcd decimise(int)
{
	;
}
