/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:36:53 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/28 18:43:12 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_fun(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthexl(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_puthexu(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += format_fun(format[i + 1], args);
			i += 2;
		}
		else
			count += ft_putchar(format[i++]);
	}
	va_end(args);
	return (count);
}

/*
int	main(void)
{
	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "jiyan");
	ft_printf("Number: %d\n", 42);
	ft_printf("Percent: %%\n");
	ft_printf(" NULL %s\n NULL ", NULL);
	ft_printf("Number: %u\n", -1);
	ft_printf("Number: %x\n", 255);
	ft_printf("Number: %X\n", 18);
	ft_printf("Pointer: %p %p\n", 0, 0);
	ft_printf("Pointer: %p\n", NULL);
	return (0);
}
*/
