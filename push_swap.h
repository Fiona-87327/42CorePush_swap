/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:24:25 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/07 15:43:13 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
}					t_stack;

/* stack operations */
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				swap(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

/* public helpers / sort API */
void		sa(t_stack **a, bool print);
void		sort_three(t_stack **a);
void		sort_stacks(t_stack **a, t_stack **b);
void		init_stack_a(t_stack **a, char **values);
void		free_stack(t_stack **stack);
int		stack_len(t_stack *stack);
int		stack_sorted(t_stack *stack);
#endif
