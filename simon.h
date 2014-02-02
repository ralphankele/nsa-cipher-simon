/**
 * Kommentar
 *
*/
#include <stdlib.h>

#ifndef __SIMON_H__
#define __SIMON_H__

//Definitions
#define WORD_SIZE 16
#define KEY_WORDS 4

#if (BLOCK_SIZE == 64)
    #define WORD_MASK (0xffffffffffffffffull)
#else
    #define WORD_MASK ((0x1ull << (BLOCK_SIZE&63)) - 1)
#endif

#if (WORD_SIZE == 16)
    #define ROUNDS (32)
    #define CONST_J (0)
#elif (WORD_SIZE == 24)
    #if (KEY_WORDS == 3)
        #define ROUNDS (36)
        #define CONST_J (0)
    #elif (KEY_WORDS == 4)
        #define ROUNDS (36)
        #define CONST_J (1)
    #endif
#elif (WORD_SIZE == 32)
    #if (KEY_WORDS == 3)
        #define ROUNDS (42)
        #define CONST_J (2)
    #elif (KEY_WORDS == 4)
        #define ROUNDS (44)
        #define CONST_J (3)
    #endif
#elif (WORD_SIZE == 48)
    #if (KEY_WORDS == 2)
        #define ROUNDS (52)
        #define CONST_J (2)
    #elif (KEY_WORDS == 3)
        #define ROUNDS (54)
        #define CONST_J (3)
    #endif
#elif (WORD_SIZE == 64)
    #if (KEY_WORDS == 2)
        #define ROUNDS (68)
        #define CONST_J (2)
    #elif (KEY_WORDS == 3)
        #define ROUNDS (69)
        #define CONST_J (3)
    #elif (KEY_WORDS == 4)
        #define ROUNDS (72)
        #define CONST_J (4)
    #endif
#endif

uint64_t z[5][62] = {
    {1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0},
    {1,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,1,0,1,0},
    {1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,0,0,1,1},
    {1,1,0,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,0,1,1,1,1},
    {1,1,0,1,0,0,0,1,1,1,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,1,1,1}
};
uint64_t key[ROUNDS] = { 0 };

//Functions
int keySchedule();
void encrypt(uint64_t left, uint64_t right);
void encryptRounds(uint64_t left, uint64_t right, int rounds);
void decrypt(uint64_t left, uint64_t right);
void decryptRounds(uint64_t left, uint64_t right, int rounds);

//Helper Functions
uint64_t S(uint64_t state, int distance);
uint64_t F(uint64_t state);

//Test-Functions
//TODO

#endif