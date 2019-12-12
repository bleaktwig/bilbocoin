#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/block.h"
#include "../include/chain.h"
#include "../include/utils.h"

// TODO: Many safety considerations are being ignored for the sake of expediency. These should ...
//       be addressed after a minimal working model is provided.

int MAX_SIZE = 6;

int main(int argc, char* argv[]) {

    // Create block list
    block* blk_list[MAX_SIZE];

    blk_list[0] = create_genesis_block("genesis block");
    for (int i = 1; i < MAX_SIZE; ++i) {
        blk_list[i] = create_block("sample text", blk_list[i-1]);
    }

    print_blockchaininfo(blk_list, MAX_SIZE);
    if (validate_blockchain(blk_list, MAX_SIZE)) printf("\nu dun goofed boi\n\n");

    for (int i = 0; i < MAX_SIZE; ++i) {
        scrap_block(blk_list[i]);
    }

    return 0;
}
