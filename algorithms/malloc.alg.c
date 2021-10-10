/*
toy example only for malloc for now
assume morecore will give us as much header units as it is asked. 
*/

Header base, *freep = NULL;
&base in [1,17]

malloc(8)
	nunits := (8+sizof(Header)-1)/sizeof(Header) + 1\
	= (7+16)/16 +1 = 2
	prevp := freep = NULL
	base.s.ptr := freep := prevp := &base = 1; 
	base.s.size := 0
	p := prevp->s.ptr = &base
	p->s.size = 0 < nunits
	p = freep
	p := morcore(2) != NULL
	there is space [1,49]
	prevp := p = &base
	p := p->s.ptr = &base
	p->s.size = 32 >= 2
	p->s.size -= 2 (*16) = 0
	p += p->s.size = 31
	p->s.size := 2
	freep := prevp = &base
	return (void) 32

