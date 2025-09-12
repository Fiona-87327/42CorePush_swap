#include "push_swap.h"

static void sort_three(t_node **a)
{
    int x = (*a)->value;
    int y = (*a)->next->value;
    int z = (*a)->next->next->value;

    if (x < y && y < z) return;
    if (x < y && y > z && x < z) { sa(a); ra(a); }
    else if (x > y && y < z && x < z) sa(a);
    else if (x < y && y > z && x > z) rra(a);
    else if (x > y && y < z && x > z) ra(a);
    else if (x > y && y > z) { sa(a); rra(a); }
}

static void sort_four(t_node **a, t_node **b)
{
    int min_pos = min_index_pos(*a);
    /* rotate min to top */
    if (min_pos == 1) ra(a);
    else if (min_pos == 2) { ra(a); ra(a); }
    else if (min_pos == 3) rra(a);
    /* push min to b */
    pb(a, b);
    /* sort remaining 3 */
    sort_three(a);
    /* push min back */
    pa(a, b);
}

static void sort_five(t_node **a, t_node **b)
{
    int min_pos = min_index_pos(*a);
    /* rotate min to top */
    if (min_pos == 1) ra(a);
    else if (min_pos == 2) { ra(a); ra(a); }
    else if (min_pos == 3) { rra(a); rra(a); }
    else if (min_pos == 4) rra(a);
    /* push min to b */
    pb(a, b);
    /* sort remaining 4 */
    sort_four(a, b);
    /* push min back */
    pa(a, b);
}

void sort_small(t_node **a, t_node **b)
{
    int n = stack_size(*a);
    if (n == 2 && (*a)->value > (*a)->next->value)
        sa(a);
    else if (n == 3)
        sort_three(a);
    else if (n == 4)
        sort_four(a, b);
    else if (n == 5)
        sort_five(a, b);
}