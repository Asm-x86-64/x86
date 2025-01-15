#include <iostream>
#include "XMM-values.h"

extern "C" void SSEPackedInt16_Add(const XMMVal* a, const XMMVal* b, XMMVal c[2]);
extern "C" void SSEPackedInt32_Sub(const XMMVal* a, const XMMVal* b, XMMVal* c);
extern "C" void SSEPackedInt32_Mul(const XMMVal* a, const XMMVal* b, XMMVal c[2]);

void SSEPackedInt16_Add_Test(void);
void SSEPackedInt32_Sub_Test(void);
void SSEPackedInt32_Mul_Test(void);

int main()
{
	SSEPackedInt16_Add_Test();
	SSEPackedInt32_Sub_Test();
	SSEPackedInt32_Mul_Test();

	return EXIT_SUCCESS;
}


void SSEPackedInt16_Add_Test(void)
{
	_declspec(align(16)) XMMVal a;
	_declspec(align(16)) XMMVal b;
	_declspec(align(16)) XMMVal c[2];
	char buffer[256];

	a.i16[0] = 10;   b.i16[0] = 90;
	a.i16[1] = 210;	 b.i16[1] = 78;
	a.i16[2] = -890; b.i16[2] = 90;
	a.i16[3] = 234;	 b.i16[3] = 76;
	a.i16[4] = 46;   b.i16[4] = 4;
	a.i16[5] = 67;	 b.i16[5] = -89;
	a.i16[6] = 0;    b.i16[6] = 1;
	a.i16[7] = 254;	 b.i16[7] = 18;

	SSEPackedInt16_Add(&a, &b, c);


	printf("\nResult (Wrap Around) for SSEPackedInt16_Add\n");
	printf("A: %s\n", a.ToString_i16(buffer, sizeof(buffer)));
	printf("B: %s\n", b.ToString_i16(buffer, sizeof(buffer)));
	printf("C: %s\n", c[0].ToString_i16(buffer, sizeof(buffer)));

	printf("\n");

	printf("\nResult (Saturated) for SSEPackedInt16_Add\n");
	printf("A: %s\n", a.ToString_i16(buffer, sizeof(buffer)));
	printf("B: %s\n", b.ToString_i16(buffer, sizeof(buffer)));
	printf("C: %s\n", c[1].ToString_i16(buffer, sizeof(buffer)));
}

void SSEPackedInt32_Sub_Test(void)
{
	_declspec(align(16)) XMMVal a;
	_declspec(align(16)) XMMVal b;
	_declspec(align(8)) XMMVal  c;
	char buffer[256];

	a.i32[0] =  -21;   b.i32[0] = 1;
	a.i32[1] = 2901;  b.i32[1] = -56;
	a.i32[2] = -890;  b.i32[2] = 90;
	a.i32[3] = 234;	  b.i32[3] = 76;


	SSEPackedInt32_Sub(&a, &b, &c);


	printf("\nResult  for SSEPackedInt32_Sub\n");
	printf("A: %s\n", a.ToString_i32(buffer, sizeof(buffer)));
	printf("B: %s\n", b.ToString_i32(buffer, sizeof(buffer)));
	printf("C: %s\n", c.ToString_i32(buffer, sizeof(buffer)));


}

void SSEPackedInt32_Mul_Test(void)
{
	_declspec(align(16)) XMMVal a;
	_declspec(align(16)) XMMVal b;
	_declspec(align(16)) XMMVal c[2];
	char buffer[256];

	a.i32[0] = 10;    b.i32[0] = 2;
	a.i32[1] = 20;    b.i32[1] = 13;
	a.i32[2] = 2;     b.i32[2] = 90;
	a.i32[3] = 1000;  b.i32[3] = -20;


	SSEPackedInt32_Mul(&a, &b, c);


	printf("\nResult  for SSEPackedInt32_Mul\n");
	printf("A: %s\n", a.ToString_i32(buffer, sizeof(buffer)));
	printf("B: %s\n", b.ToString_i32(buffer, sizeof(buffer)));
	printf("C: %s\n", c[0].ToString_i32(buffer, sizeof(buffer)));

	printf("\n");

	printf("\nResult  for SSEPackedInt32_Mul\n");
	printf("A: %s\n", a.ToString_i32(buffer, sizeof(buffer)));
	printf("B: %s\n", b.ToString_i32(buffer, sizeof(buffer)));
	printf("C: %s\n", c[1].ToString_i64(buffer, sizeof(buffer)));


}

