#include <iostream>

extern "C" void CalculateSum(int a, int b, int c, int *s1, int *s2, int *s3);

int main()
{
	int a = 1, b = 2, c = 3;
	int s1, s2, s3;
	CalculateSum(a, b, c, &s1, &s2, &s3);
	printf("A:%d\tB:%d\tC:%d\n", a, b, c);
	printf("s1:%d\ts2:%d\ts3:%d\n", s1, s2, s3);
	return EXIT_SUCCESS;
}


