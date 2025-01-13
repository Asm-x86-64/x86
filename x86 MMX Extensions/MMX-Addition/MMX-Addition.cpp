#include <iostream>
#include "MMX-values.h"

using namespace std;

enum MMXAddOp : unsigned int
{
	paddb,				//packed byte addition with wraparond
	paddsb,				//packed byte addition with signed saturation
	paddusb,			//packed byte addition with unsigned saturation
	paddw,				//packed word addition with wraparound
	paddsw,				//packed word addition with signed saturation
	paddusw,			//packed word addition with unsigned saturation
	paddd,				//packed doubleword addition with wraparound

};

extern "C" MMXVal MmxAdd(MMXVal a, MMXVal b, MMXAddOp operation);

void MMXAddBytes(void);
void MMXAddWords(void);
void MMXAddDwords(void);


int main()
{
	MMXAddBytes();
	MMXAddWords();
	MMXAddDwords();

	return EXIT_SUCCESS;

}

void MMXAddBytes(void)
{
	MMXVal a, b, c;
	char buffer[256];

	// Packed Byte Addition - Signed Integers
	a.i8[0] = 50;
	a.i8[1] = 80;
	a.i8[2] = -27;
	a.i8[3] = -70;
	a.i8[4] = -42;
	a.i8[5] = 60;
	a.i8[6] = 64;
	a.i8[7] = 100;

	b.i8[0] = 30;
	b.i8[1] = 64;
	b.i8[2] = -32;
	b.i8[3] = -80;
	b.i8[4] = 90;
	b.i8[5] = -85;
	b.i8[6] = 90;
	b.i8[7] = -30;

	printf("\n\n Packed Byte Addition - Signed integers\n");
	printf("a: %s\n", a.ToString_i8(buffer, sizeof(buffer)));
	printf("b: %s\n", b.ToString_i8(buffer, sizeof(buffer)));

	c = MmxAdd(a, b, MMXAddOp::paddsb);
	printf("\n paddsb results\n");
	printf("c: %s\n", c.ToString_i8(buffer, sizeof(buffer)));

	// Wrap Around Version
	c = MmxAdd(a, b, MMXAddOp::paddb);
	printf("\n paddb results\n");
	printf("c: %s\n", c.ToString_i8(buffer, sizeof(buffer)));

	// Packed Byte Addition - UnSigned Integers
	a.u8[0] = 50;
	a.u8[1] = 80;
	a.u8[2] = 132;
	a.u8[3] = 200;
	a.u8[4] = 42;
	a.u8[5] = 60;
	a.u8[6] = 140;
	a.u8[7] = 10;

	b.u8[0] = 30;
	b.u8[1] = 64;
	b.u8[2] = 130;
	b.u8[3] = 180;
	b.u8[4] = 90;
	b.u8[5] = 85;
	b.u8[6] = 160;
	b.u8[7] = 14;

	printf("\n\n Packed Byte Addition - UnSigned integers\n");
	printf("a: %s\n", a.ToString_u8(buffer, sizeof(buffer)));
	printf("b: %s\n", b.ToString_u8(buffer, sizeof(buffer)));

	c = MmxAdd(a, b, MMXAddOp::paddusb);
	printf("\n paddusb results\n");
	printf("c: %s\n", c.ToString_u8(buffer, sizeof(buffer)));

	//Wrap Around Version
	c = MmxAdd(a, b, MMXAddOp::paddb);
	printf("\n paddb results\n");
	printf("c: %s\n", c.ToString_u8(buffer, sizeof(buffer)));
}

void MMXAddWords(void)
{
	MMXVal a, b, c;
	char buffer[256];

	//Packed Word Addition - Signed Integers
	a.i16[0] = 500;
	a.i16[1] = 30000;
	a.i16[1] = -270;
	a.i16[1] = -7000;

	b.i16[0] = 830;
	b.i16[1] = 5000;
	b.i16[2] = -320;
	b.i16[3] = -32000;


	printf("\n\n Packed Word Addition - Signed integers\n");
	printf("a: %s\n", a.ToString_i16(buffer, sizeof(buffer)));
	printf("b: %s\n", b.ToString_i16(buffer, sizeof(buffer)));

	c = MmxAdd(a, b, MMXAddOp::paddsw);
	printf("\n paddsw results\n");
	printf("c: %s\n", c.ToString_i16(buffer, sizeof(buffer)));

	// Wrap Around Version
	c = MmxAdd(a, b, MMXAddOp::paddw);
	printf("\n paddw results\n");
	printf("c: %s\n", c.ToString_i16(buffer, sizeof(buffer)));


	//Packed Word Addition - UnSigned Integers
	a.u16[0] = 500;
	a.u16[1] = 48000;
	a.u16[1] = 132;
	a.u16[1] = 10000;

	b.u16[0] = 30;
	b.u16[1] = 20000;
	b.u16[2] = 130;
	b.u16[3] = 60000;


	printf("\n\n Packed Word Addition - UnSigned integers\n");
	printf("a: %s\n", a.ToString_i16(buffer, sizeof(buffer)));
	printf("b: %s\n", b.ToString_i16(buffer, sizeof(buffer)));

	c = MmxAdd(a, b, MMXAddOp::paddusw);
	printf("\n paddusw results\n");
	printf("c: %s\n", c.ToString_i16(buffer, sizeof(buffer)));

	// Wrap Around Version
	c = MmxAdd(a, b, MMXAddOp::paddw);
	printf("\n paddw results\n");
	printf("c: %s\n", c.ToString_i16(buffer, sizeof(buffer)));

}

void MMXAddDwords(void)
{
	MMXVal a, b, c;
	char buffer[256];

	//Packed Dword Signed Addition WrapAround 
	a.i32[0] = 305000;
	a.i32[1] = -300001;

	b.i32[0] = 482902;
	b.i32[1] = -5000;

	printf("\n\n Packed Dword Addition - Signed integers\n");
	printf("a: %s\n", a.ToString_i32(buffer, sizeof(buffer)));
	printf("b: %s\n", b.ToString_i32(buffer, sizeof(buffer)));

	c = MmxAdd(a, b, MMXAddOp::paddd);
	printf("\n paddd results\n");
	printf("c: %s\n", c.ToString_i32(buffer, sizeof(buffer)));

	//Packed Dword UnSigned Addition WrapAround
	a.u32[0] = 305000;
	a.u32[1] = 300001;

	b.u32[0] = 482902;
	b.u32[1] = 5000;

	printf("\n\n Packed Dword Addition - UnSigned integers\n");
	printf("a: %s\n", a.ToString_u32(buffer, sizeof(buffer)));
	printf("b: %s\n", b.ToString_u32(buffer, sizeof(buffer)));

	c = MmxAdd(a, b, MMXAddOp::paddd);
	printf("\n paddd results\n");
	printf("c: %s\n", c.ToString_u32(buffer, sizeof(buffer)));


}