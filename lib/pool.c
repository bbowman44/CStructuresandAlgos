#include "pool.h"

void pool_init(pool_t *pool)
{
    for(size_t i = 0; i < POOL_BLOCK_COUNT - 1; i++)
    {
        pool->blocks[i].next = &pool->blocks[i + 1];
    }
    pool->blocks[POOL_BLOCK_COUNT - 1].next = NULL;
    pool->free_list = &pool->blocks[0];
}

void *pool_alloc(pool_t *pool)
{
    if(pool->free_list == NULL)
    {
        return NULL;
    }

    pool_block_t *block = pool->free_list;
    pool->free_list = block->next;
    return block;
}

void pool_free(pool_t *pool, void *ptr)
{
    pool_block_t *block = ptr;
    block->next = pool->free_list;
    pool->free_list = block;
}