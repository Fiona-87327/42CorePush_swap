/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:26:44 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/04 21:36:41 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		value;

	if (!stack || !stack->top)
		return (0);
	tmp = stack->top;
	value = tmp->value;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return (value);
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
