#include "ring_buffer.h"

uint16_t rb_count(const ring_buffer_t *rb)
{
    return rb->head - rb->tail;
}

bool rb_is_empty(const ring_buffer_t *rb)
{
    if(rb->head == rb->tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool rb_is_full(const ring_buffer_t *rb)
{
    if (rb_count(rb) == RB_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool rb_push(ring_buffer_t *rb, uint8_t value)
{
    if(rb_is_full(rb))
    {
       return false;
    }
    rb->buffer[rb->head & RB_MASK] = value;
    rb->head++;
    return true;
}

bool rb_pop(ring_buffer_t *rb, uint8_t *out)
{
    if(rb_is_empty(rb))
    {
        return false;
    }

    *out = rb->buffer[rb->tail & RB_MASK];
    rb->tail++;
    return true;
}