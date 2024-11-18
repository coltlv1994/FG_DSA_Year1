#ifndef _MERSENNE_H_
#define _MERSENNE_H_

#include <stdint.h>

class Mersenne
{
    static const size_t SIZE   = 624;
    static const size_t PERIOD = 397;
    static const size_t DIFF   = SIZE - PERIOD;

    static const uint32_t MAGIC = 0x9908b0df;

    uint32_t mersenne_twister[SIZE];
    uint32_t mersenne_twister_temptered[SIZE];
    size_t index = SIZE;

    public:
        void Unroll(uint16_t iter, uint16_t expr);
        void Seed(uint32_t seed);
        uint32_t Rand_u32(void);
        void Generate_numbers(void);
};

uint32_t M32(uint32_t num);

uint32_t L31(uint32_t num);

#endif