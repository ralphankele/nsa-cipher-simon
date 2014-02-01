/**
 * Kommentar
 *
*/

#include "simon.h"

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
