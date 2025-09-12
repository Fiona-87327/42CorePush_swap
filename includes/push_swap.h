#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/*
** Data structures
*/
typedef struct s_node
{
    int             value;  /* original integer value */
    int             index;  /* compressed rank (0..n-1) */
    struct s_node  *next;
} t_node;

/*
** Parsing
*/
int   parse_args(int argc, char **argv, t_node **a);

/*
** Utils
*/
void  putstr_fd(const char *s, int fd);
void  *xmalloc(size_t size);
int   safe_atoi(const char *s, int *out);
void  free_stack(t_node **s);
void  fatal_error(void);

/*
** Split (whitespace-based)
*/
char **ws_split(const char *s);
void  free_split(char **v);

/*
** Stack utilities
*/
int    stack_size(t_node *s);
bool   is_sorted(t_node *s); /* ascending top->bottom */
t_node *new_node(int value);
void   push_front(t_node **s, t_node *n);
void   push_back(t_node **s, t_node *n);
t_node *pop_front(t_node **s);
t_node *last_node(t_node *s);
int    min_index_pos(t_node *s); /* position (0-based) of smallest index */
int    min_index_value(t_node *s);

/*
** Operations (print exactly one instruction when effective)
*/
void sa(t_node **a);
void sb(t_node **b);
void ss(t_node **a, t_node **b);

void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);

void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);

void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);

/*
** Indexing (coordinate compression)
*/
void assign_indices(t_node *a);

/*
** Sorting
*/
void sort_small(t_node **a, t_node **b);
void sort_big(t_node **a, t_node **b);

#endif /* PUSH_SWAP_H */