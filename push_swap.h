/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:24:25 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/07 14:41:20 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
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

#endif
