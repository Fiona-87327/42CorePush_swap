#include "push_swap.h"

static int swap_core(t_node **s)
{
    if (!s || !*s || !(*s)->next) return 0;
    t_node *a = *s;
    t_node *b = a->next;
    a->next = b->next;
    b->next = a;
    *s = b;
    return 1;
}

void sa(t_node **a)
{
    if (swap_core(a))
        putstr_fd("sa\n", 1);
}

void sb(t_node **b)
{
    if (swap_core(b))
        putstr_fd("sb\n", 1);
}

void ss(t_node **a, t_node **b)
{
    int did = 0;
    did |= swap_core(a);
    did |= swap_core(b);
    if (did)
        putstr_fd("ss\n", 1);
}