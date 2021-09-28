typedef struct {
	unsigned int eight : 1;
	unsigned int rest : 3;
} bcd;

int binarise_single(bcd call)
{
	return (signed) (call.eight) ? (call.rest > 1 ? 10 : 8 + call.rest) : call.rest;
}

//bcd arrs are little endian, as all things should be.

int binarise_wraped(bcd call[], int len, int iter)
{
	if (iter>=len)
		return 0;
	else
	{	return 10*binarise_wraped(call+1,len,iter+1) + binarise_single(*call);
	}
}

int binarise(bcd call[], int len)
{
	binarise_wraped(call, len, 0);
}

void reveal(bcd call[])
{
	printf("%d",binarise(call,sizeof call / sizeof(bcd)));
}

bcd decimise_single(int call)
{
	return (bcd) {.eight = (call > 7), .rest = call % 8};
}

bcd* decimise(int call, bcd back[])
{
	if (!call)
		*back = (bcd) {0,0};
	else
	{	*back = decimise_single(call % 10); 
		decimise(call / 10, back+1);
	}	

	return back;
}
