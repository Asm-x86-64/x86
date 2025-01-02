#include <iostream>

extern "C" int intMulDiv(int a, int b, int* prod, int* quo, int* rem);

int main()
{
	int a = 21, b = 9;
	int pro = 0, quo = 0, rem = 0;
	int rv;
	rv = intMulDiv(a, b, &pro, &quo, &rem);
	if (rv) {
		printf("A:%d\tB:%d\n", a, b);
		printf("pro:%d\tquo:%d\trem:%d\n", pro, quo, rem);
		return EXIT_SUCCESS;
	}
	else {
		printf("Division by zero\n");
		return EXIT_FAILURE;
	}
}


