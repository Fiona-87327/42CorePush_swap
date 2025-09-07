/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:59:13 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/28 11:36:22 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	int				count;
	unsigned long	address;

	address = (unsigned long)ptr;
	count = 0;
	if (ptr == NULL)
	{
		count += (write(1, "(nil)", 5));
		return (count);
	}
	count += (write(1, "0x", 2));
	count += ft_puthexl(address);
	return (count);
}
