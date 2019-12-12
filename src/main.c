#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/block.h"
#include "../include/chain.h"
#include "../include/utils.h"

// TODO: Many safety considerations are being ignored for the sake of expediency. These should ...
//       be addressed after a minimal working model is provided.

int MAX_SIZE = 2;

int main(int argc, char* argv[]) {

    // Create block list
    block* blk_list[MAX_SIZE];

    blk_list[0] = create_genesis_block("genesis block");
    for (int i = 1; i < MAX_SIZE; ++i) {
        blk_list[i] = create_block("sample text", blk_list[i-1]);
    }

    block* blk_list2[MAX_SIZE+1];

    blk_list2[0] = create_genesis_block("genesis block 2");
    for (int i = 1; i < MAX_SIZE+1; ++i) {
        blk_list2[i] = create_block("sample text 2", blk_list2[i-1]);
    }

    print_blockchaininfo(blk_list, MAX_SIZE);
    print_blockchaininfo(blk_list2, MAX_SIZE+1);
    if (validate_blockchain(blk_list, MAX_SIZE)) printf("\nu dun goofed boi\n\n");
    if (validate_blockchain(blk_list2, MAX_SIZE+1)) printf("\nu dun goofed boi 2\n\n");

    int valid_chain = compare_blockchains(blk_list, MAX_SIZE, blk_list2, MAX_SIZE+1);
    printf("\nValid chain is chain #%d\n\n", valid_chain);

    scrap_chain(blk_list, MAX_SIZE);
    scrap_chain(blk_list2, MAX_SIZE+1);


    return 0;
}
