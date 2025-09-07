/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:41:31 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/28 13:20:13 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexl(unsigned long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthexl(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
