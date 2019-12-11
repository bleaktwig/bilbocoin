#include "blockchain.h"

int validate_blockchain(block* blkchn[], int size) {
    if (size == 0)
        return 1; // blockchain is empty.
    if (validate_genesis_block(blkchn[0]))
        return 2; // genesis block is invalid.
    for (int i = 1; i < size; ++i) if (validate_block(blkchn[i], blkchn[i-1]))
        return 3; // block i is invalid.

    return 0; // block is valid.
}
