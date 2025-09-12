#include "push_swap.h"

static int push_core(t_node **dst, t_node **src)
{
    t_node *n = pop_front(src);
    if (!n) return 0;
    push_front(dst, n);
    return 1;
}

void pa(t_node **a, t_node **b)
{
    if (push_core(a, b))
        putstr_fd("pa\n", 1);
}

void pb(t_node **a, t_node **b)
{
    if (push_core(b, a))
        putstr_fd("pb\n", 1);
}