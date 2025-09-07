/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:32:47 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/27 18:53:05 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
