/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:12:05 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/28 15:45:17 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putunsigned(unsigned int n);
int	ft_puthexl(unsigned long n);
int	ft_puthexu(unsigned long n);
int	ft_putpointer(void *ptr);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);

#endif
