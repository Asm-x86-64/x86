#include <iostream>

extern "C" void AVX_fp_Arithmetic(double a, double b, double results[8]);

int main()
{

	const char* inames[8] = { "vaddsd","vsubsd","vmulsd","vdivsd","vminsd","vmaxsd","vsqrtsd a","vandpd b" };

	double a = 13.90;
	double b = -78.67;
	double results[8];

	AVX_fp_Arithmetic(a, b, results);

	printf("\nResult from Computation\n");
	printf("A:			%6.lf\n", a);
	printf("B:			%6.lf\n", b);

	for (int i = 0; i < 8; i++)
	{
		printf("%14s		:		%12.6lf\n", inames[i], results[i]);
	}
	return EXIT_SUCCESS;
}