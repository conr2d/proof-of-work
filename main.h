#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <malloc.h>
#include "crypto-algorithms/sha256.h"

typedef struct _Block {
    WORD Version; /**< Block version number */
    BYTE hashPrevBlock[SHA256_BLOCK_SIZE]; /**< 256-bit hash of the previous block header */
    BYTE hashMerkleRoot[SHA256_BLOCK_SIZE]; /**< 256-bit hash based on all of the transactions in the block */
    WORD Time; /**< Current timestamp as seconds since 1970-01-01T00:00 UTC */
    WORD Bits; /**< Current target in compact format */
    WORD Nonce; /**< 32-bit number */
    BYTE hash[SHA256_BLOCK_SIZE]; /**< 256-bit block hash */
} Block;

/**
 * @brief Convert hex string to binary
 *
 * @param[out] destination memory address to be written
 * @param[in] source memory address to be read (ends with '\0')
 */
void hstob(void *destination, const void *source);

/**
 * @brief Convert binary to hex string
 *
 * @param[out] destination memory address to be written
 * @param[in] source memory address to be read
 * @param[in] len size of memory to be copied
 *
 * @return string encoded in hex
 */
void btohs(void *destination, const void *source, int len);

/**
 * @brief Convert input binary to hash value with SHA-256 algorithm
 *
 * @param[out] destination memory address to be written
 * @param[in] source memory address to be read
 * @param[in] len size of memory to be copied
 */
void sha256_hash(BYTE *destination, const BYTE *source, int len);

/**
 * @brief Print block information
 *
 * @param[in] block Given block
 */
void print_block(const Block *block);

/**
 * @brief Compare two 256-bit binary values
 *
 * @param[in] x1 256-bit binary
 * @param[in] x2 256-bit binary
 *
 * @return (x1 < x2) return -1, (x1 > x2) return 1, (x1 == x2) return 0
 */
int hex256cmp(BYTE *x1, BYTE *x2);

#endif
