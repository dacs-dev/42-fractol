/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:22:53 by dcid-san          #+#    #+#             */
/*   Updated: 2024/10/28 16:23:33 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int	ft_put_int_fd(int n, int fd)
{
	long int	ncpy;
	char		wrap;
	int			size;

	size = 0;
	ncpy = n;
	if (ncpy < 0)
	{
		size += write(fd, "-", 1);
		ncpy *= -1;
	}
	if (ncpy >= 10)
		size += ft_put_int_fd(ncpy / 10, fd);
	wrap = (ncpy % 10) + '0';
	size += write(fd, &wrap, 1);
	return (size);
}

int	ft_put_unsigned_fd(unsigned int n, int fd)
{
	unsigned long	ncpy;
	char			wrap;
	int				size;

	size = 0;
	ncpy = n;
	if (ncpy >= 10)
		size += ft_put_int_fd(ncpy / 10, fd);
	wrap = (ncpy % 10) + '0';
	size += write(fd, &wrap, 1);
	return (size);
}

int	ft_put_double_fd(double n, int fd)
{
	int	int_part;
	int	size;

	int_part = (int) n;
	size = ft_put_int_fd(int_part, fd);
	n = n - int_part;
	ft_putchar_fd('.', fd);
	size += 1 + ft_put_int_fd(n * 100.0, fd);
	return (size);
}

int	ft_put_float_fd(float n, int fd)
{
	int	int_part;
	int	size;

	int_part = (int) n;
	size = ft_put_int_fd(int_part, fd);
	n = n - int_part;
	ft_putchar_fd('.', fd);
	size += 1 + ft_put_int_fd(n * 100.0, fd);
	return (size);
}
