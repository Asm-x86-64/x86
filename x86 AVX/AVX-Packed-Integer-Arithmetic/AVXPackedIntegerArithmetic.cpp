#include <iostream>
#include "YMM-values.h"

extern "C" void AVXPackedInt_16(YMMVal* a, YMMVal* b, YMMVal c[6]);
extern "C" void AVXPackedInt_32(YMMVal* a, YMMVal* b, YMMVal c[5]);

void AVXPackedInt_16_Test(void);
void AVXPackedInt_32_Test(void);


int main()
{
	 AVXPackedInt_16_Test();
	 AVXPackedInt_32_Test();

	 return EXIT_SUCCESS;

}


void AVXPackedInt_16_Test(void)
{
	// 32 byte alignment
	__declspec(align(32)) YMMVal a;
	__declspec(align(32)) YMMVal b;
	__declspec(align(32)) YMMVal c[6];

	a.i16[0] = 30;		b.i16[0] = 3000;
	a.i16[1] = 56;		b.i16[1] = 7809;
	a.i16[2] = 785;		b.i16[2] = 10;
	a.i16[3] = 90828;   b.i16[3] = 5;
	a.i16[4] = -908;	b.i16[4] = 100;
	a.i16[5] = 234;		b.i16[5] = 87;
	a.i16[6] = -785;	b.i16[6] = 900;
	a.i16[7] = 1111;	b.i16[7] = 2222;
	a.i16[8] = 567;		b.i16[8] = -667677;
	a.i16[9] = -1183;	b.i16[9] = 7809;
	a.i16[10] = 1234;	b.i16[10] = 10;
	a.i16[11] = -90182;	b.i16[11] = 5;
	a.i16[12] = -12991;	b.i16[12] = 100;
	a.i16[13] = 4;		b.i16[13] = 87;
	a.i16[14] = -75;	b.i16[14] = 0;
	a.i16[15] = 3333;	b.i16[15] = 2222;

	AVXPackedInt_16(&a, &b, c);
	printf("\nResult for Int 16\n");
	printf("A	B	vpaddw		vpaddsw		vpsubw		vpsubsw		vpminsw		vpmaxsw\n");
	printf("******************************************************************************\n");

	for (int i = 0; i < 16; i++)
	{
		const char* fmt_param = "%17d";
		printf(fmt_param, a.i16[i]);
		printf(fmt_param, b.i16[i]);

		printf(fmt_param, c[0].i16[i]);
		printf(fmt_param, c[1].i16[i]);
		printf(fmt_param, c[2].i16[i]);
		printf(fmt_param, c[3].i16[i]);
		printf(fmt_param, c[4].i16[i]);
		printf(fmt_param, c[5].i16[i]);

		printf("\n");

	}

}

void AVXPackedInt_32_Test(void)
{
	// 32 byte alignment
	__declspec(align(32)) YMMVal a;
	__declspec(align(32)) YMMVal b;
	__declspec(align(32)) YMMVal c[5];

	a.i32[0] = 223020;		b.i32[0] = 3000;
	a.i32[1] = 323;			b.i32[1] = 30;
	a.i32[2] = 1;			b.i32[2] = 1;
	a.i32[3] = 4452;		b.i32[3] = 5;
	a.i32[4] = -91208;		b.i32[4] = 100;
	a.i32[5] = -9088;		b.i32[5] = 87;
	a.i32[6] = 233;			b.i32[6] = 900;
	a.i32[7] = 4552;		b.i32[7] = 2222;

	AVXPackedInt_32(&a, &b, c);
	printf("\nResult for Int 32\n");
	printf("A	B	vhpaddd		vphsubd		vpmulld		vpsllvd		vpsravd\n");
	printf("******************************************************************************\n");

	for (int i = 0; i < 8; i++)
	{
		const char* fmt_param = "%16d";

		printf(fmt_param, a.i32[i]);
		printf(fmt_param, b.i32[i]);

		printf(fmt_param, c[0].i32[i]);
		printf(fmt_param, c[1].i32[i]);
		printf(fmt_param, c[2].i32[i]);
		printf(fmt_param, c[3].i32[i]);
		printf(fmt_param, c[4].i32[i]);
		printf("\n");
	}
}