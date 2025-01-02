#include <iostream>

extern "C" char         GLCHAR = 10;
extern "C" short        GLSHORT = 20;
extern "C" int          GLINT = 30;
extern "C" long long    GLONG = 0x000000000FFFFFFFFLL;

extern "C" void IntegerAddition(char a, short b, int c, long long d);

int main()
{
	IntegerAddition(10, 20, 30, 4567890);
	printf("GLCHAR=%d\n", GLCHAR);
	printf("GLSHORT=%hi\n", GLSHORT);
	printf("GLINT=%d\n", GLINT);
	printf("GLONG=%lld\n", GLONG);

}