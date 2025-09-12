#include "push_swap.h"

static int max_bits(int n)
{
    int bits = 0;
    while ((1 << bits) < n)
        bits++;
    return bits;
}

static void radix_sort_bit(t_node **a, t_node **b, int bit)
{
    int size = stack_size(*a);
    for (int i = 0; i < size; i++)
    {
        if ((((*a)->index >> bit) & 1) == 0)
            pb(a, b);
        else
            ra(a);
    }
    /* push everything back from b to a */
    while (*b)
        pa(a, b);
}

void sort_big(t_node **a, t_node **b)
{
    int n = stack_size(*a);
    int bits = max_bits(n);
    
    for (int bit = 0; bit < bits; bit++)
        radix_sort_bit(a, b, bit);
}