/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:09:58 by dcid-san          #+#    #+#             */
/*   Updated: 2024/10/28 16:30:10 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_put_nbr_base(unsigned int nb, unsigned int bsize,
							const char *base)
{
	int	size;

	size = 0;
	if (nb >= bsize)
	{
		size += ft_put_nbr_base(nb / bsize, bsize, base);
	}
	size += write(1, &base[nb % bsize], 1);
	return (size);
}

int	ft_put_hexa(unsigned int nb, char c)
{
	if (c == 'x')
		return (ft_put_nbr_base(nb, 16, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_put_nbr_base(nb, 16, "0123456789ABCDEF"));
	return (0);
}
