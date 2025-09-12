#include "push_swap.h"

static bool append_number(t_node **a, const char *tok)
{
    int v;
    if (!safe_atoi(tok, &v))
        return false;
    push_back(a, new_node(v));
    return true;
}

static bool has_duplicates(t_node *a)
{
    for (t_node *i = a; i; i = i->next)
        for (t_node *j = i->next; j; j = j->next)
            if (i->value == j->value)
                return true;
    return false;
}

int parse_args(int argc, char **argv, t_node **a)
{
    for (int i = 1; i < argc; ++i)
    {
        char **tokens = ws_split(argv[i]);
        if (!tokens)
            return false;
        if (!tokens[0])
        {
            /* argument contained only whitespace -> invalid argument */
            free_split(tokens);
            return false;
        }
        for (int k = 0; tokens[k]; ++k)
        {
            if (!append_number(a, tokens[k]))
            {
                free_split(tokens);
                return false;
            }
        }
        free_split(tokens);
    }
    if (has_duplicates(*a))
        return false;
    return true;
}