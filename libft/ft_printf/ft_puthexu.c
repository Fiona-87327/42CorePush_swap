/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:57:43 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/28 13:20:17 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexu(unsigned long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthexu(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
