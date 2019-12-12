#ifndef BILBO_CHAIN_H
#define BILBO_CHAIN_H

#include <stdint.h>

#include "block.h"

int validate_blockchain(block* chn[], int size);
int scrap_chain(block* chn[], int size);
int compare_blockchains(block* chn1[], int size1, block* chn2[], int size2);

#endif
