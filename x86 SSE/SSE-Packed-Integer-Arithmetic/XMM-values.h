#include "Miscellaneous.h"



/*
	This union only represent the packed nature of SSE registers,but they are also scalar in nature.
	All union members are 128-bit long
	Allocated memory will be 128-bit at a time one data member can be stored.

*/
union XMMVal {
	// Integer Data types

	//Signed Members
	Int8   i8[16];	// XMM register can hold 16 8-bit  values
	Int16 i16[8];	// XMM register can hold  8 16-bit values
	Int32 i32[4];	// XMM register can hold  4 32-bit values
	Int64 i64[2];	// XMM register can hold  2 64-bit value

	//Usigned Members
	Uint8   u8[16];
	Uint16 u16[8];
	Uint32 u32[4];
	Uint64 u64[2];

	// Floating Point Data
	float r32[4];
	double r64[2];


	// Function Prototypes
	char* ToString_i8(char* s, size_t len);
	char* ToString_i16(char* s, size_t len);
	char* ToString_i32(char* s, size_t len);
	char* ToString_i64(char* s, size_t len);

	char* ToString_u8(char* s, size_t len);
	char* ToString_u16(char* s, size_t len);
	char* ToString_u32(char* s, size_t len);
	char* ToString_u64(char* s, size_t len);

	char* ToString_x8(char* s, size_t len);
	char* ToString_x16(char* s, size_t len);
	char* ToString_x32(char* s, size_t len);
	char* ToString_x64(char* s, size_t len);

	char* ToString_r32(char* s, size_t len);
	char* ToString_r64(char* s, size_t len);

};
