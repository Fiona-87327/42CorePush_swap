/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:08:53 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/28 14:59:08 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
	{
		if (write(1, &s[len], 1) == 0)
			return (0);
		len++;
	}
	return (len);
}
