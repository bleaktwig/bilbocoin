#include "block.h"

block* create_genesis_block(char in_data[]) {
    block* blk = (block*) malloc(sizeof(block));
    init_genesis_block(blk, in_data);

    return blk;
}
block* create_block(char in_data[], block* prev_blk) {
    block* blk = (block*) malloc(sizeof(block));
    init_block(blk, prev_blk, in_data);

    return blk;
}
int compute_genesis_hash(uint8_t hash[], int idx, time_t time, char data[]) {
    char str[1024];

    { // Generate hashed string
        char str_idx[256]; // TODO: I probably need less bytes than this tbh
        char str_time[256]; // TODO: I probably need less bytes than this tbh

        sprintf(str_idx, "%d", idx);
        sprintf(str_time, "%ld", time);

        strcpy(str, str_idx); // TODO: Replace for strlcpy for security reasons.
        strcat(str, str_time); // TODO: Replace for strlcpy for security reasons.
        strcat(str, data); // TODO: Replace for strlcpy for security reasons.
    }

    calc_sha_256(hash, str, sizeof(str));

    return 0;
}
int compute_hash(uint8_t hash[], int idx, time_t time, char data[], uint8_t prev_hash[]) {
    char str[1024];

    { // Generate hashed string
        char str_idx[256]; // TODO: I probaby need less bytes than this tbh
        char str_time[256]; // TODO: I probaby need less bytes than this tbh
        char str_prev_hash[64];

        sprintf(str_idx, "%d", idx);
        sprintf(str_time, "%ld", time);
        for (int i = 0; i < 32; ++i) sprintf(&(str_prev_hash[2*i]), "%02x", prev_hash[i]);

        strcpy(str, str_idx); // TODO: Replace for strlcpy for security reasons.
        strcat(str, str_time); // TODO: Replace for strlcpy for security reasons.
        strcat(str, data); // TODO: Replace for strlcpy for security reasons.
        strcat(str, str_prev_hash); // TODO: Replace for strlcpy for security reasons.
    }

    calc_sha_256(hash, str, sizeof(str));

    return(0);
}
int init_genesis_block(block* blk, char* in_data) {
    blk->index = 0;
    blk->time = time(0);
    strcpy(blk->data, in_data);

    // NOTE: This is technically unsafe, but generating this specific hash is extremely unlikely
    const uint8_t hashsrc[32] = {0x61, 0x6c, 0x6c, 0x20, 0x79, 0x6f, 0x75, 0x72,
                                 0x20, 0x62, 0x61, 0x73, 0x65, 0x20, 0x61, 0x72,
                                 0x65, 0x20, 0x62, 0x65, 0x6c, 0x6f, 0x6e, 0x67,
                                 0x20, 0x74, 0x6f, 0x20, 0x75, 0x73, 0x21, 0x21};

    memcpy(blk->prev_hash, hashsrc, 32);

    // uint8_t hash_buff[32];
    compute_genesis_hash(blk->hash, blk->index, blk->time, blk->data);
    // memcpy(blk->hash, hash_buff, 32);

    return 0;
}
int init_block(block* blk, block* prev_blk, char* in_data) {
    blk->index = prev_blk->index+1;
    blk->time = time(0);
    strcpy(blk->data, in_data);

    memcpy(blk->prev_hash, prev_blk->hash, 32);

    uint8_t hash_buff[32];
    compute_hash(hash_buff, blk->index, blk->time, blk->data, blk->prev_hash);
    memcpy(blk->hash, hash_buff, 32);

    return 0;
}
