#include "push_swap.h"

static void choose_and_sort(t_node **a, t_node **b)
{
    int n = stack_size(*a);
    if (n <= 1 || is_sorted(*a))
        return;
    if (n <= 5)
        sort_small(a, b);
    else
        sort_big(a, b);
}

int main(int argc, char **argv)
{
    t_node *a = NULL;
    t_node *b = NULL;

    if (argc == 1)
        return 0; /* no output */
    if (!parse_args(argc, argv, &a))
    {
        putstr_fd("Error\n", 2);
        free_stack(&a);
        return 1;
    }
    /* compress values to indices for algorithms */
    assign_indices(a);

    choose_and_sort(&a, &b);

    free_stack(&a);
    free_stack(&b);
    return 0;
}