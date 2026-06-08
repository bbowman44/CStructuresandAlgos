#include "../lib/ring_buffer.h"
#include <stdio.h>

int main(void)
{
    ring_buffer_t rb = {0};   //zero-initialization: head = tail = 0, so it starts empty
    uint8_t v;

    rb_push(&rb, 10);
    rb_push(&rb, 20);
    rb_push(&rb, 30);
    printf("FIFO order (expect 10 20 30): ");
    while (rb_pop(&rb, &v)) {
        printf("%u ", (unsigned)v);
    }
    printf("\n");

    for (unsigned i = 0; i < RB_SIZE; i++) {
        rb_push(&rb, (uint8_t)i);
    }
    printf("count after filling: %u (expect %u)\n",
           (unsigned)rb_count(&rb), RB_SIZE);
    printf("is_full: %s (expect yes)\n", rb_is_full(&rb) ? "yes" : "no");
    printf("push when full returns: %s (expect false)\n",
           rb_push(&rb, 99) ? "true" : "false");

    while (rb_pop(&rb, &v)) {
    }
    printf("is_empty: %s (expect yes)\n", rb_is_empty(&rb) ? "yes" : "no");
    printf("pop when empty returns: %s (expect false)\n",
           rb_pop(&rb, &v) ? "true" : "false");

    unsigned errors = 0;
    for (unsigned i = 0; i < 5000; i++) {
        uint8_t pushed = (uint8_t)i;
        uint8_t popped;
        if (!rb_push(&rb, pushed)) { errors++; continue; }
        if (!rb_pop(&rb, &popped)) { errors++; continue; }
        if (popped != pushed)      { errors++; }
    }
    printf("wraparound test: %s (%u errors)\n",
           errors == 0 ? "PASS" : "FAIL", errors);

    return 0;
}