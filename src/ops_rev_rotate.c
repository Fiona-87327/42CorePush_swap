#include "push_swap.h"

static int rev_rotate_core(t_node **s)
{
    if (!s || !*s || !(*s)->next) return 0;
    t_node *prev = NULL;
    t_node *cur = *s;
    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    /* cur is last, prev is penultimate */
    if (prev)
        prev->next = NULL;
    cur->next = *s;
    *s = cur;
    return 1;
}

void rra(t_node **a)
{
    if (rev_rotate_core(a))
        putstr_fd("rra\n", 1);
}

void rrb(t_node **b)
{
    if (rev_rotate_core(b))
        putstr_fd("rrb\n", 1);
}

void rrr(t_node **a, t_node **b)
{
    int did = 0;
    did |= rev_rotate_core(a);
    did |= rev_rotate_core(b);
    if (did)
        putstr_fd("rrr\n", 1);
}