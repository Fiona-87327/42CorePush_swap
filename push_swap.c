/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:50:08 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/07 15:50:36 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	i_is_number(const char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!('0' <= *s && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

static int	str_to_int_checked(const char *s, int *out)
{
	long	val;
	int		sign;

	val = 0;
	sign = 1;
	if (!s)
		return (0);
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s == '0')
		s++;
	if (!*s)
	{
		*out = 0;
		return (1);
	}
	while (*s)
	{
		if (!('0' <= *s && *s <= '9'))
			return (0);
		val = val * 10 + (*s - '0');
		if (sign == 1 && val > INT_MAX)
			return (0);
		if (sign == -1 && - val < INT_MIN)
			return (0);
		s++;
	}
	*out = (int)(val * sign);
	return (1);
}

static int	has_dup(t_stack *stack, int value)
{
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while ((*stack)->top)
	{
		tmp = (*stack)->top;
		(*stack)->top = tmp->next;
		free(tmp);
	}
	free(*stack);
	*stack = NULL;
}

int	stack_len(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

int	stack_sorted(t_stack *stack)
{
	t_node	*cur;

	if (!stack || !stack->top)
		return (1);
	cur = stack->top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	init_stack_a(t_stack **a, char **values)
{
	int	i;
	int	n;
	int	val;

	if (!a || !values)
		return ;
	*a = malloc(sizeof(t_stack));
	if (!*a)
		return ;
	(*a)->size = 0;
	(*a)->top = NULL;
	n = 0;
	while (values[n])
		n++;
	i = n - 1;
	while (i >= 0)
	{
		if (!i_is_number(values[i]) || !str_to_int_checked(values[i], &val)
			|| has_dup(*a, val))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(a);
			exit(1);
		}
		push(*a, val);
		i--;
	}
}
