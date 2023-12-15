#include <stdio.h>
int main()
{
    long x = 0x12345678; // 78563412 in memory
    void *p = &x;

    printf("%p\n",p);
    // first byte
    printf("char  = %x\n",*(char*) p);
    // first two bytes
    printf("short = %x\n",*(short*)p);
    // all four bytes
    printf("long  = %x\n",*(long*) p);
    return 0;
}

