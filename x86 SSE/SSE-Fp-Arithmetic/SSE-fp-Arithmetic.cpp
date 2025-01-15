#include <iostream>


extern "C" void SSEArithmeticOperationsFloat(float a, float b, float c[8]);
extern "C" void SSEArithmeticOperationsDouble(double a, double b, double c[8]);

void SSESinglePrecisionTest(void);
void SSEDoublePrecisionTest(void);

int main()
{
	SSESinglePrecisionTest();
	SSEDoublePrecisionTest();
}

void SSESinglePrecisionTest(void)
{
	float a = 2.5f;
	float b = -7.56;
	float c[8];

	SSEArithmeticOperationsFloat(a, b, c);
	printf("\n------------Results of single precision---------------\n");
	printf("a:					%.6f\n", a);
	printf("b:					%.6f\n", b);
	printf("Add:				%.6f\n", c[0]);
	printf("Sub:				%.6f\n", c[1]);
	printf("Mul:				%.6f\n", c[2]);
	printf("Div:				%.6f\n", c[3]);
	printf("Min:				%.6f\n", c[4]);
	printf("Max:				%.6f\n", c[5]);
	printf("Abs:				%.6f\n", c[6]);
	printf("Sqrt:				%.6f\n", c[7]);

}

void SSEDoublePrecisionTest(void)
{
	double a = 3.14159265359;
	double b = 2.71828182846;
	double c[8];

	SSEArithmeticOperationsDouble(a, b, c);
	printf("\n------------Results of double precision---------------\n");
	printf("a:					%.14lf\n", a);
	printf("b:					%.14lf\n", b);
	printf("Add:				%.14lf\n", c[0]);
	printf("Sub:				%.14lf\n", c[1]);
	printf("Mul:				%.14lf\n", c[2]);
	printf("Div:				%.14lf\n", c[3]);
	printf("Min:				%.14lf\n", c[4]);
	printf("Max:				%.14lf\n", c[5]);
	printf("Abs:				%.14lf\n", c[6]);
	printf("Sqrt:				%.14lf\n", c[7]);

}

