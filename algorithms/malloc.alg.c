/*
toy example only for malloc for now
morecore will give us 5 header units the first time and nothing afterwards
will ask for 2 HU three times.
*/

Header base, *freep = NULL;
&base in [1,17]

malloc(32)
	nunits := (32+sizof(Header)-1)/sizeof(Header) + 1\
	= (31+16)/16 +1 = 3
	prevp := freep = NULL
	base.s.ptr := freep := prevp := &base = 1; 
	base.s.size := 0
	p := prevp->s.ptr = &base
	p->s.size = 0 < nunits
	p = freep
	p = morcore(3)=

