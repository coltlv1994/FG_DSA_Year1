/* 
 * The Mersenne Twister pseudo-random number generator (PRNG)
 *
 * This is an implementation of fast PRNG called MT19937, meaning it has a
 * period of 2^19937-1, which is a Mersenne prime.
 *
 * This PRNG is fast and suitable for non-cryptographic code.  For instance, it
 * would be perfect for Monte Carlo simulations, etc.
 *
 * For all the details on this algorithm, see the original paper:
 * http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/ARTICLES/mt.pdf
 *
 * Written by Christian Stigen Larsen
 * Distributed under the modified BSD license.
 * 2015-02-17, 2017-12-06
 * 
 * This program has undergone some modification.
 */

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