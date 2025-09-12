#include "push_swap.h"

static int rotate_core(t_node **s)
{
    if (!s || !*s || !(*s)->next) return 0;
    t_node *first = pop_front(s);
    push_back(s, first);
    return 1;
}

void ra(t_node **a)
{
    if (rotate_core(a))
        putstr_fd("ra\n", 1);
}

void rb(t_node **b)
{
    if (rotate_core(b))
        putstr_fd("rb\n", 1);
}

void rr(t_node **a, t_node **b)
{
    int did = 0;
    did |= rotate_core(a);
    did |= rotate_core(b);
    if (did)
        putstr_fd("rr\n", 1);
}