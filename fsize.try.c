#include <dirent.h>
//#include <stdio.h>

int main(void)
{
	struct dirent a={1,2,3,4,"fsize"};
	DIR *b=opendir(".");
	//printf("%ld %s\n",a.ino,a.name);
}
