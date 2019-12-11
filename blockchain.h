#ifndef BILBO_BLOCKCHAIN_H
#define BILBO_BLOCKCHAIN_H

#include <stdint.h>

#include "block.h"

int validate_blockchain(block* blkchn[], int size);

#endif
