#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);
void expand(char s1[],char s2[]);
float getFloat(char sign, unsigned char exp, unsigned mantissa);

int main(int argc, char *argv[])
{
    char call[50] = "-A a-c a-c-e !--~ !---A d-a a-a -! ~- - z-";
    char back[0x400];
    
    printf("Original string:\n%s\n", call);

    expand(call, back);
    printf("Expanded string:\n%s\n", back);
    printf("Signed char[%d to %d]\n", ~((short)-11), (short)~0>>3);
    printf("Float[%g to %g]\n", getFloat(1, 0, 1), getFloat(0, ~0-1, ~0));
    printf("Unsigned int[0 to %u or %x]\n",~0U,~0U);
    putchar((char)-1);putchar((char)~0);

    
    return 0;
}

float getFloat(char sign, unsigned char exp, unsigned mantissa)
{
    unsigned f = (unsigned)(sign != 0) << 31 | (unsigned)exp << 23 | mantissa & 0x7FFFFF;
    return *((float *)&f);
}