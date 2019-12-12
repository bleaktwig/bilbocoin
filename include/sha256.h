#ifndef BILBO_SHA256_H
#define BILBO_SHA256_H

#include <stdint.h>
#include <string.h>

void calc_sha_256(uint8_t hash[32], const void *input, size_t len);

#endif
