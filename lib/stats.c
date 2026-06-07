#include "stats.h"

int32_t stats_sum(const int32_t *data, size_t n)
{
    int32_t sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum = data[i] + sum;
    }
    return sum;
}

bool stats_min_max(const int32_t *data, size_t n,int32_t *out_min, int32_t *out_max)
{
    if (n == 0)
    {
        return false;
    }

    *out_min = data[0];
    *out_max = data[0];

    for(size_t i = 0; i < n; i++)
    {
        if (data[i] < *out_min)
        {
            *out_min = data[i];
        }
        if (data[i] > *out_max)
        {
            *out_max = data[i];
        }
    }
    return true;
}