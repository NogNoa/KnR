#include <stdio.h>

int main(){

	float a;
	
	printf("%f\n", 4.f/3.f);	//1.333333
	printf("%f\n", 4.f/3);		//1.333333
	printf("%f\n", 4/3.f);		//1.333333
	printf("%f\n", 4/3);		//1.333333
	a = 4/3;
	printf("%f\n", a);			//1.000000
	
	return a;
}

