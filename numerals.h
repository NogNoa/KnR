typedef struct {
	unsigned int eight : 1;
	unsigned int rest : 3;
} bcd;

int binarise_single(bcd call)
{
	return (signed) (call.eight) ? (call.rest > 1 ? 10 : 8 + call.rest) : call.rest;
}

//bcd arrs are little endian, as all things should be.

int binarise(bcd call[])
{
	if (!call)
		return 0;
	else
		return binarise_single(*call) + 10*binarise(call+1);
}

void reveal(bcd call[])
{
	printf("%d",binarise(call));
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
