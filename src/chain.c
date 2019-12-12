#include "../include/chain.h"

int validate_blockchain(block* chn[], int size) {
    if (size == 0)
        return 1; // blockchain is empty.
    if (validate_genesis_block(chn[0]))
        return 2; // genesis block is invalid.
    for (int i = 1; i < size; ++i) if (validate_block(chn[i], chn[i-1]))
        return 3; // block i is invalid.

    return 0; // blockchain is valid.
}
int scrap_chain(block* chn[], int size) {
    for (int i = 0; i < size; ++i) scrap_block(chn[i]);

    return 0;
}
int compare_blockchains(block* chn1[], int size1, block* chn2[], int size2) {
    if (validate_blockchain(chn1, size1)) {
        if (validate_blockchain(chn2, size2))
            return 3; // both blockchains are invalid.
        return 2; // blockchain1 is invalid, select blockchain2.
    }
    if (validate_blockchain(chn2, size2))
        return 1; // blockchain2 is invalid, select blockchain1.

    if (size1 > size2) return 1; // blockchain1 is longer, select it.
    if (size2 > size1) return 2; // blockchain2 is longer, select it.
    else return 0; // both blockchains are valid and of the same size.
}
