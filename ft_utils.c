/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:22:34 by mueruslu          #+#    #+#             */
/*   Updated: 2026/02/02 17:23:40 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

static int	ft_puthex_long(unsigned long long nb)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (nb >= 16)
		len += ft_puthex_long(nb / 16);
	len += write(1, &base[nb % 16], 1);
	return (len);
}

int	ft_puthex(unsigned int n, char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthex(n / 16, format);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex_long(ptr);
	return (len);
}
