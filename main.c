#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "block.h"
#include "utils.h"

// TODO: Many safety considerations are being ignored for the sake of expediency. These should ...
//       be addressed after a minimal working model is provided.

int MAX_SIZE = 6;

int main(int argc, char* argv[]) {

    block* blk_list[MAX_SIZE];

    blk_list[0] = create_genesis_block("genesis block");
    for (int i = 1; i < MAX_SIZE; ++i) {
        blk_list[i] = create_block("sample text", blk_list[i-1]);
    }

    for (int i = 0; i < MAX_SIZE; ++i) {
        if (i == 0) print_genblockinfo(blk_list[i]);
        else        print_blockinfo(blk_list[i], blk_list[i-1]);
    }

    for (int i = 0; i < MAX_SIZE; ++i) {
        free(blk_list[i]);
    }

    return 0;
}
