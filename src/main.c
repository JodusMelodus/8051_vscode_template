#include <mcs51/8051.h>
#include <inttypes.h>
#include "REG51ATLPRB2.h"

void main(void)
{
    static uint16_t loop;

    P0M0 = 0x00;
    P0M1 = 0xFF;
    P0 = 0x00;

    while (1)
    {
        for (loop = 0; loop < UINT16_MAX; loop++)
            ;
        P0 ^= 0x80;
    }
}
