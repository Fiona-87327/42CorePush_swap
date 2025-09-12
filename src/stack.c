#include "push_swap.h"

t_node *new_node(int value)
{
    t_node *n = (t_node *)xmalloc(sizeof(t_node));
    n->value = value;
    n->index = -1;
    n->next = NULL;
    return n;
}

void push_front(t_node **s, t_node *n)
{
    if (!n) return;
    n->next = *s;
    *s = n;
}

void push_back(t_node **s, t_node *n)
{
    if (!n) return;
    if (!*s) { *s = n; return; }
    t_node *last = *s;
    while (last->next) last = last->next;
    last->next = n;
}

t_node *pop_front(t_node **s)
{
    if (!s || !*s) return NULL;
    t_node *n = *s;
    *s = n->next;
    n->next = NULL;
    return n;
}

t_node *last_node(t_node *s)
{
    if (!s) return NULL;
    while (s->next) s = s->next;
    return s;
}

int stack_size(t_node *s)
{
    int n = 0;
    while (s) { n++; s = s->next; }
    return n;
}

bool is_sorted(t_node *s)
{
    while (s && s->next)
    {
        if (s->value > s->next->value)
            return false;
        s = s->next;
    }
    return true;
}

int min_index_value(t_node *s)
{
    int min = INT_MAX;
    while (s)
    {
        if (s->index < min)
            min = s->index;
        s = s->next;
    }
    return min;
}

int min_index_pos(t_node *s)
{
    int min = INT_MAX;
    int pos = 0;
    int best = 0;
    while (s)
    {
        if (s->index < min)
        {
            min = s->index;
            best = pos;
        }
        pos++;
        s = s->next;
    }
    return best;
}