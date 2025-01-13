#include "Miscellaneous.h"



/*

	All union members are 64-bit long
	Allocated memory will be 64-bit at a time one data member can be stored.
*/
union MMXVal {

	//Signed Members
	Int8   i8[8];	// MMX register can hold 8 8-bit  values
	Int16 i16[4];	// MMX register can hold 4 16-bit values
	Int32 i32[2];	// MMX register can hold 2 32-bit values
	Int64 i64;		// MMX register can hold 1 64-bit value

	//Usigned Members
	Uint8   u8[8];
	Uint16 u16[4];
	Uint32 u32[2];
	Uint64 u64;


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

};
