#include "../lib/stats.h"
#include <stdio.h>

int main(void)
{
    int32_t data[] = {30, 20, 21, 8, 7, 14};
    size_t n = sizeof(data)/sizeof(data[0]);
    int32_t sum;
    bool min_max_state;
    int32_t out_min;
    int32_t out_max;

    sum = stats_sum(data, n);
    min_max_state = stats_min_max(data, n, &out_min, &out_max);

    printf("Sum of given array: %i\n", sum);
    if(!min_max_state) //if false then it will need to say that the size is not right
    {
        printf("Size of the array is 0, please reconfigure\n");
    }
    printf("Minimum number in the array is %i and the maximum is %i\n", out_min, out_max);
}