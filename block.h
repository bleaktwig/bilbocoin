#ifndef BILBO_BLOCK_H
#define BILBO_BLOCK_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "sha-256.h"

typedef struct {
    int index;
    time_t time;
    char data[256];
    uint8_t prev_hash[32];
    uint8_t hash[32];
} block;

block* create_genesis_block(char in_data[]);
block* create_block(char in_data[], block* prev_blk);
int compute_genesis_hash(uint8_t hash[], int idx, time_t time, char data[]);
int compute_hash(uint8_t hash[], int idx, time_t time, char data[], uint8_t prev_hash[]);
int init_genesis_block(block* blk, char* in_data);
int init_block(block* blk, block* prev_blk, char* in_data);

#endif