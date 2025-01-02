#include <iostream>

extern "C" int SignedMin(int a, int b, int c);
extern "C" int SignedMax(int a, int b, int c);
extern "C" int UnSignedMin(int a, int b, int c);
extern "C" int UnSignedMax(int a, int b, int c);


int main()
{
	int a, b, c;
	int sign_max, sign_min, unsign_max, unsign_min;

	a = 345;
	b = -783;
	c = 34;

	sign_max = SignedMax(a, b, c);
	sign_min = SignedMax(a, b, c);

	b = 234;

	unsign_max = UnSignedMax(a, b, c);
	unsign_min = UnSignedMin(a, b, c);

	printf("The Signed Maximum is:%d\n", sign_max);
	printf("The Signed Minimum is:%d\n", sign_min);

	printf("The UnSigned Maximum is:%d\n", unsign_max);
	printf("The UnSigned Minimum is:%d\n", unsign_min);

	return EXIT_SUCCESS;
}

