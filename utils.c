/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:26:44 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/11 21:54:28 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->next < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}
