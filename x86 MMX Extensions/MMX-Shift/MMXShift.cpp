#include <iostream>
#include "MMX-values.h"
using namespace std;

enum MMXShiftOp : unsigned int
{
    psllw,      // Shift left logical word
    psrlw,      // Shift right logical word
    psraw,      // Shift right arithmetic word
    pslld,      // Shift left logical dword
    psrld,      // Shift right logical dword
    psrad,      // Shift right arithmetic dword
};

extern "C" bool MMXShift(MMXVal a, MMXShiftOp shift_op, int count, MMXVal* b);
void MmxShiftWords(void);
void MmxShiftDwords(void);

int main()
{
    MmxShiftWords();
    MmxShiftDwords();
    return EXIT_SUCCESS;
}

void MmxShiftWords(void)
{
    MMXVal a, b;
    int count;
    char buffer[256]; 

    a.u16[0] = 50;
    a.u16[1] = 12;
    a.u16[2] = 20;
    a.u16[3] = 70;

    count = 2;
    MMXShift(a, MMXShiftOp::psllw, count, &b);

    printf("\nResult for psllw - count = %d\n", count);
    printf("a: %s\n", a.ToString_u16(buffer, sizeof(buffer)));
    printf("b: %s\n", b.ToString_u16(buffer, sizeof(buffer)));

    MMXShift(a, MMXShiftOp::psrlw, count, &b);

    printf("\nResult for prllw - count = %d\n", count);
    printf("a: %s\n", a.ToString_u16(buffer, sizeof(buffer)));
    printf("b: %s\n", b.ToString_u16(buffer, sizeof(buffer)));

    MMXShift(a, MMXShiftOp::psraw, count, &b);

    printf("\nResult for psraw - count = %d\n", count);
    printf("a: %s\n", a.ToString_u16(buffer, sizeof(buffer)));
    printf("b: %s\n", b.ToString_u16(buffer, sizeof(buffer)));

}

void MmxShiftDwords(void)
{
    MMXVal a, b;
    int count;
    char buffer[256];

    a.u32[0] = 121;
    a.u32[1] = 24;
    count = 3;

    MMXShift(a, MMXShiftOp::pslld, count, &b);

    printf("\nResult for pslld - count = %d\n", count);
    printf("a: %s\n", a.ToString_u32(buffer, sizeof(buffer)));
    printf("b: %s\n", b.ToString_u32(buffer, sizeof(buffer)));

    MMXShift(a, MMXShiftOp::psrld, count, &b);

    printf("\nResult for psrld - count = %d\n", count);
    printf("a: %s\n", a.ToString_u32(buffer, sizeof(buffer)));
    printf("b: %s\n", b.ToString_u32(buffer, sizeof(buffer)));

    MMXShift(a, MMXShiftOp::psrad, count, &b);

    printf("\nResult for psrad - count = %d\n", count);
    printf("a: %s\n", a.ToString_u32(buffer, sizeof(buffer)));
    printf("b: %s\n", b.ToString_u32(buffer, sizeof(buffer)));
}