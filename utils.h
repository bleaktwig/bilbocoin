#ifndef BILBO_UTILS_H
#define BILBO_UTILS_H

#include <stdint.h>
#include <stdio.h>
#include <time.h>

int print_hash256(uint8_t hash[]);
int obtain_walltime(char* walltime, time_t rawtime);

#endif
