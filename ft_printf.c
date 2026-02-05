/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:47:39 by mueruslu          #+#    #+#             */
/*   Updated: 2026/02/02 15:47:39 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putunsigned(unsigned int n)
{
	if (n >= 10)
		ft_putunsigned(n / 10);
	ft_putchar((n % 10) + '0');
	return (0);
}

static int	ft_check_format(char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (specifier == 'x' || specifier == 'X')
		len += ft_puthex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'p')
		len += ft_putptr(va_arg(args, unsigned long long));
	else if (specifier == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(specifier);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;
	int		i;

	va_start(args, format);
	total_len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				total_len += ft_check_format(format[i], args);
		}
		else
			total_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}

