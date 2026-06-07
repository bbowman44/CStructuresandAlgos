#ifndef STATS_H // Include guard
#define STATS_H // Stats library header file

#include <stddef.h>   //size_t
#include <stdint.h>   //int32_t
#include <stdbool.h>  //bool

//Sum of the n elements of data.
int32_t stats_sum(const int32_t *data, size_t n);

//Writes the smallest and largest of the n elements through the out-pointers.
//Returns false (and writes nothing) if n == 0.
bool stats_min_max(const int32_t *data, size_t n,
                   int32_t *out_min, int32_t *out_max);

#endif //STATS_H