/**
 * Kommentar
 *
*/

#include "simon.h"

uint64_t S(uint64_t state, int distance){
    if(distance > WORD_SIZE || distance < - WORD_SIZE)
        return -1;

    return (distance > 0) ? 
    ((state << distance) | (state >> (WORD_SIZE-distance))) & WORD_MASK : 
    ((state >> (-distance)) | (state << (WORD_SIZE+distance))) & WORD_MASK;
}

uint64_t F(unit64_t state){
    return (S(state, 1) & S(state, 8)) ^ S(state, 2);
}

int keySchedule(){
    return 0;
}

void encrypt(uint64_t left, uint64_t right){
    encryptRounds(left, right, ROUNDS);
}

void encryptRounds(uint64_t left, uint64_t right, int rounds){
    uint64_t tmp;
    for(int i = 0; i < rounds; ++i){
        tmp = left;
        left = right ^ F(left) ^ key[i];
        right = tmp;
    }
}

void decrypt(uint64_t left, uint64_t right){
    decryptRounds(left, right, ROUNDS);
}

void decryptRounds(uint64_t left, uint64_t right, int rounds){
    uint64_t tmp;
    for(int i = 0; i < rounds; ++i){
        tmp = right;
        right = left ^ F(right) ^ key[ROUNDS-i-1];
        left = tmp;
    }
}

