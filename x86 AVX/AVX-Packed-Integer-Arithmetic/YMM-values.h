#include "Miscellaneous.h"



/*
	This union only represent the packed nature of AVX registers,but they are also scalar in nature.
	All union members are 256-bit long
	Allocated memory will be 256-bit at a time one data member can be stored.

*/
union YMMVal {
	// Integer Data types

	//Signed Members
	Int8   i8[32];	// YMM register can hold 32 8-bit  values
	Int16 i16[16];	// YMM register can hold 16 16-bit values
	Int32 i32[8];	// YMM register can hold  8 32-bit values
	Int64 i64[4];	// YMM register can hold  4 64-bit value

	//Usigned Members
	Uint8   u8[32];
	Uint16 u16[16];
	Uint32 u32[8];
	Uint64 u64[4];

	// Floating Point Data
	float r32[8];
	double r64[4];


	// Function Prototypes
	char* ToString_i8(char* s, size_t len,bool upper_half);
	char* ToString_i16(char* s, size_t len, bool upper_half);
	char* ToString_i32(char* s, size_t len, bool upper_half);
	char* ToString_i64(char* s, size_t len, bool upper_half);

	char* ToString_u8(char* s, size_t len, bool upper_half);
	char* ToString_u16(char* s, size_t len, bool upper_half);
	char* ToString_u32(char* s, size_t len, bool upper_half);
	char* ToString_u64(char* s, size_t len, bool upper_half);

	char* ToString_x8(char* s, size_t len, bool upper_half);
	char* ToString_x16(char* s, size_t len, bool upper_half);
	char* ToString_x32(char* s, size_t len, bool upper_half);
	char* ToString_x64(char* s, size_t len, bool upper_half);

	char* ToString_r32(char* s, size_t len, bool upper_half);
	char* ToString_r64(char* s, size_t len, bool upper_half);

};
