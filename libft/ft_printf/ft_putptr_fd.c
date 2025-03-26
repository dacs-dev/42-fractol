/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:50:13 by dcid-san          #+#    #+#             */
/*   Updated: 2024/10/28 16:08:29 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long	dir;
	int				size;
	char			buffer[18];
	char			*hex_values;
	int				i;

	hex_values = "0123456789abcdef";
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	size = 2 + (int)(sizeof(ptr) * 2);
	i = size - 1;
	dir = (long) ptr;
	while (i >= 2 && dir != 0)
	{
		buffer[i] = hex_values[dir % 16];
		dir /= 16;
		i--;
	}
	buffer[i - 1] = '0';
	buffer[i] = 'x';
	i--;
	write(fd, buffer + i, size - i);
	return (size - i);
}
