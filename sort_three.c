/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:56:22 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/11 22:00:01 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack_node **a)
{
    t_stack_node    *bigst_node;

    bigst_node = fin_max(*a);
    if (bigst_node == *a)
        ra(a, false);
    else if((*a)->next == bigst_node)
        rra(a, false);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false);
}