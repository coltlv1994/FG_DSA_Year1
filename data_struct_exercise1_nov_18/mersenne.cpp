#include "mersenne.h"

void Mersenne::Unroll(uint16_t iter, uint16_t expr)
{
    uint32_t y = M32(mersenne_twister[iter]) | L31(mersenne_twister[iter + 1]);
    mersenne_twister[iter] = mersenne_twister[expr] ^ (y >> 1) ^ ((y & 0x00000001) & MAGIC);
}

void Mersenne::Seed(uint32_t seed)
{
    mersenne_twister[0] = seed;
    index = SIZE;

    for ( uint32_t i=1; i<SIZE; ++i )
    {
        mersenne_twister[i] =  0x6c078965*(mersenne_twister[i-1] ^ mersenne_twister[i-1]>>30) + i;
    }
}

uint32_t Mersenne::Rand_u32(void)
{
    if ( index == SIZE )
    {
        Generate_numbers();
        index = 0;
    }

  return mersenne_twister_temptered[index++];
}

void Mersenne::Generate_numbers(void)
{
    size_t i = 0;
    uint32_t y;

    while ( i < DIFF )
    {
        Unroll(i, i+PERIOD);
        i++;
    }

    while ( i < SIZE -1 )
    {
        Unroll(i, i-DIFF);
        i++;
    }

    y = M32(mersenne_twister[SIZE-1]) | L31(mersenne_twister[0]);
    mersenne_twister[SIZE-1] = mersenne_twister[PERIOD-1] ^ (y >> 1) ^ (((int32_t(y) << 31) >> 31) & MAGIC);

    for (size_t i = 0; i < SIZE; ++i)
    {
        y = mersenne_twister[i];
        y ^= y >> 11;
        y ^= y << 7  & 0x9d2c5680;
        y ^= y << 15 & 0xefc60000;
        y ^= y >> 18;
        mersenne_twister_temptered[i] = y;
    }

    index = 0;
}

uint32_t M32(uint32_t num)
{
    return 0x80000000 & num;
}

uint32_t L31(uint32_t num)
{
    return 0x7FFFFFFF & num;
}