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

int encrypt(uint64_t plaintext, uint64_t ciphertext, uint64_t key){
    return encryptRounds(plaintext, ciphertext, key, ROUNDS);
}

int encryptRounds(uint64_t plaintext, uint64_t ciphertext, uint64_t key, int rounds){
    return 0;
}

int decrypt(uint64_t plaintext, uint64_t ciphertext, uint64_t key){
    return decryptRounds(plaintext, ciphertext, key, ROUNDS);
}

int decryptRounds(uint64_t plaintext, uint64_t ciphertext, uint64_t key, int rounds){
    return 0;
}
