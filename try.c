#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    const char *string="drm";

    printf("%d\n",(int) (strchr(string,'a')-string));
    
    return 0;
}
