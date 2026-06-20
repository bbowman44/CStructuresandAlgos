#include "../lib/pool.h"
#include <stdio.h>
#include <stdint.h>

typedef struct {
    int32_t id;
    int32_t reading;
} sample_t;

static void print_free(const pool_t *pool)
{
    printf("  free_list -> ");
    for(const pool_block_t *b = pool->free_list; b != NULL; b = b->next)
    {
        printf("B%td -> ", b - pool->blocks);
    }
    printf("NULL\n");
}

int main(void)
{
    pool_t pool;
    pool_init(&pool);

    printf("After init, every block is free:\n");
    print_free(&pool);

    printf("\nAllocate three blocks and store data in them:\n");
    sample_t *a = pool_alloc(&pool);
    sample_t *b = pool_alloc(&pool);
    sample_t *c = pool_alloc(&pool);
    a->id = 1; a->reading = 100;
    b->id = 2; b->reading = 200;
    c->id = 3; c->reading = 300;
    printf("  a (id=%d, reading=%d)\n", a->id, a->reading);
    printf("  b (id=%d, reading=%d)\n", b->id, b->reading);
    printf("  c (id=%d, reading=%d)\n", c->id, c->reading);
    print_free(&pool);

    printf("\nFree b, then allocate again:\n");
    pool_free(&pool, b);
    print_free(&pool);
    sample_t *d = pool_alloc(&pool);
    printf("  did we get the same block b just freed? %s\n", (d == b) ? "yes" : "no");
    print_free(&pool);

    printf("\nDrain the pool until it runs out:\n");
    int count = 0;
    while(pool_alloc(&pool) != NULL)
    {
        count++;
    }
    printf("  handed out %d more blocks, then\n", count);
    printf("  alloc on an empty pool returns: %s\n", (pool_alloc(&pool) == NULL) ? "NULL" : "a block");

    return 0;
}