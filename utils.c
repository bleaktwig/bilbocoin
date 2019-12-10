#include "block.h"

int print_hash256(uint8_t hash[]) {
    for (int i = 0; i < 32; ++i) {
        if (i%4 == 0 && i != 0) printf(" ");
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
int obtain_walltime(char* walltime, time_t rawtime) {
    strftime(walltime, 20, "%Y-%m-%d %H:%M:%S", localtime(&rawtime));
    return 0;
}
