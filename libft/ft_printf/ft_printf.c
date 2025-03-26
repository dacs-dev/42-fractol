/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:50:58 by dcid-san          #+#    #+#             */
/*   Updated: 2024/10/28 16:10:55 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

static int	print_args(va_list *args, char const c)
{
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (c == 'c')
	{
		ft_putchar_fd((char) va_arg(*args, int), 1);
		return (1);
	}
	else if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putptr_fd(va_arg(*args, void *), 1));
	else if (c == 'i' || c == 'd')
		return (ft_put_int_fd(va_arg(*args, int), 1));
	else if (c == 'u')
		return (ft_put_unsigned_fd(va_arg(*args, unsigned int), 1));
	else if (c == 'x')
		return (ft_put_hexa(va_arg(*args, unsigned int), c));
	else if (c == 'X')
		return (ft_put_hexa(va_arg(*args, unsigned int), c));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		size;

	va_start(args, str);
	size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			size += print_args(&args, *str);
		}
		else
			size += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (size);
}
