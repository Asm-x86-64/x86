#include <iostream>
#include "MMX-values.h"


extern "C" void MMXMultiply(MMXVal a, MMXVal b, MMXVal* prod_low, MMXVal* prod_high);


int main()
{
	MMXVal a, b;
	MMXVal prod_low, prod_high;
	char buffer[256];

	a.u16[0] = 15000;
	a.u16[1] = 12000;
	a.u16[2] = 5000;
	a.u16[3] = 32768;

	b.u16[0] = 40000;
	b.u16[1] = 30000;
	b.u16[2] = 25000;
	b.u16[3] = 10000;


	MMXMultiply(a, b, &prod_low, &prod_high);

	printf("\nReuslt of MMXMulSignedWord\n");
	printf("a:%s\n", a.ToString_u16(buffer, sizeof(buffer)));
	printf("b:%s\n", b.ToString_u16(buffer, sizeof(buffer)));



	printf("Product_low:%s\n", prod_low.ToString_u32(buffer, sizeof(buffer)));
	printf("Product_high:%s\n", prod_high.ToString_u32(buffer, sizeof(buffer)));


	return EXIT_SUCCESS;
}


