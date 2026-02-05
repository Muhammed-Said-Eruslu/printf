/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:24:36 by mueruslu          #+#    #+#             */
/*   Updated: 2026/02/02 17:24:36 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "limits.h"
int main()
{
    ft_printf("Hello, world!\n");
    ft_printf("%c\n", 'A');
    ft_printf("%s", "Sample string\n");
    ft_printf("%d\n", 123);
    ft_printf("%i\n", 456);
    ft_printf("%x\n", 255);
    ft_printf("%X\n", 255);
    ft_printf("%p\n", (void *)789);
    ft_printf("%u\n", UINT_MAX);
    ft_printf("%%");
}
