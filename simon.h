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
#define CONST_C 

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
uint64_t k[ROUNDS] = { 0 };

//Functions
int keySchedule();
int encrypt(uint64_t plaintext, uint64_t ciphertext, uint64_t key);
int encryptRounds(uint64_t plaintext, uint64_t ciphertext, uint64_t key, int rounds);
int decrypt(uint64_t plaintext, uint64_t ciphertext, uint64_t key);
int decryptRounds(uint64_t plaintext, uint64_t ciphertext, uint64_t key, int rounds);

//Helper Functions

uint64_t S();
unit64_t F();

//Test-Functions
//TODO

#endif