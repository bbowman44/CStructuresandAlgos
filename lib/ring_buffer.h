#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define RB_SIZE 64u            //capacity. MUST be a power of two
#define RB_MASK (RB_SIZE - 1u)

typedef struct ring_buffer_t {
    uint8_t  buffer[RB_SIZE];
    uint16_t head;   //next write position (free-running, masked on use)
    uint16_t tail;   //next read position  (free-running, masked on use)
} ring_buffer_t;

uint16_t rb_count(const ring_buffer_t *rb);//bytes currently stored (HEAD - TAIL FOR UNSIGNED SUBTRACTION)
bool     rb_is_empty(const ring_buffer_t *rb);
bool     rb_is_full(const ring_buffer_t *rb);
bool     rb_push(ring_buffer_t *rb, uint8_t value);//false if full (RB_SIZE IS EQUAL TO COUNT)
bool     rb_pop(ring_buffer_t *rb, uint8_t *out);//false if empty (HEAD == TAIL)

#endif