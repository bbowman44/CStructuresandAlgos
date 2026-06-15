#ifndef POOL_H
#define POOL_H

#include <stddef.h>
#include <stdbool.h>

#define POOL_BLOCK_SIZE  32u  //usable bytes per block
#define POOL_BLOCK_COUNT 8u   //number of blocks

typedef union pool_block
{
    union pool_block *next;
    unsigned char     data[POOL_BLOCK_SIZE];
} pool_block_t;

typedef struct
{
    pool_block_t  blocks[POOL_BLOCK_COUNT];
    pool_block_t *free_list;
} pool_t;

void  pool_init(pool_t *pool);
void *pool_alloc(pool_t *pool);
void  pool_free(pool_t *pool, void *ptr);

#endif