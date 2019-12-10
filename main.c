#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "block.h"
#include "utils.h"

// TODO: Many safety considerations are being ignored for the sake of expediency. These should ...
//       be addressed after a minimal working model is provided.

int MAX_SIZE = 1;

int main(int argc, char* argv[]) {

    block* blk_list[MAX_SIZE];

    blk_list[0] = create_genesis_block("genesis block");
    for (int i = 1; i < MAX_SIZE; ++i) {
        blk_list[i] = create_block("sample text", blk_list[i-1]);
    }

    printf("List of blocks:\n");
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("block %d:\n", blk_list[i]->index);

        char walltime[20];
        obtain_walltime(walltime, blk_list[i]->time);
        printf("  time: %s\n", walltime);

        printf("  data: %s\n", blk_list[i]->data);

        printf("  prev: ");
        print_hash256(blk_list[i]->prev_hash);
        printf("  hash: ");
        print_hash256(blk_list[i]->hash);
        printf("\n");
    }

    for (int i = 0; i < MAX_SIZE; ++i) {
        free(blk_list[i]);
    }

    return 0;
}
