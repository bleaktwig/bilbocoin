#include "utils.h"

int print_hash256(uint8_t hash[]) {
    for (int i = 0; i < 32; ++i) {
        if (i%4 == 0 && i != 0) printf(" ");
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
int print_genblockinfo(block* blk) {
    print_blockinfo(blk, blk);

    return 0;
}
int print_blockinfo(block* blk, block* prev_blk) {
    printf("block %d ", blk->index);

    if (blk->index == 0) {
        if (!validate_genesis_block(blk)) printf("(validated):\n");
        else printf("(invalid):\n");
    }
    else {
        if (!validate_block(blk, prev_blk)) printf("(validated):\n");
        else printf("(invalid):\n");
    }

    char walltime[20];
    obtain_walltime(walltime, blk->time);
    printf("  time: %s\n", walltime);
    printf("  data: %s\n", blk->data);
    printf("  prev: ");
    print_hash256(blk->prev_hash);
    printf("  hash: ");
    print_hash256(blk->hash);
    printf("\n");

    return 0;
}
int obtain_walltime(char* walltime, time_t rawtime) {
    strftime(walltime, 20, "%Y-%m-%d %H:%M:%S", localtime(&rawtime));
    return 0;
}
