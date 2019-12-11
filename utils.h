#ifndef BILBO_UTILS_H
#define BILBO_UTILS_H

#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "block.h"

int print_hash256(uint8_t hash[]);
int print_genblockinfo(block* blk);
int print_blockinfo(block* blk, block* prev_blk);
int print_blockchaininfo(block* blkchn[], int size);
int obtain_walltime(char* walltime, time_t rawtime);

#endif
