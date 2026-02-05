/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:24:00 by mueruslu          #+#    #+#             */
/*   Updated: 2026/02/02 17:24:00 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, char format);
int	ft_putptr(unsigned long long ptr);
int	ft_printf(const char *format, ...);