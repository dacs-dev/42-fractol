/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:20 by dcid-san          #+#    #+#             */
/*   Updated: 2024/10/16 19:39:10 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_putfloat_fd(float n, int fd)
{
	int		int_part;

	int_part = (int) n;
	ft_putnbr_fd(int_part, fd);
	n = n - int_part;
	ft_putchar_fd('.', fd);
	ft_putnbr_fd(n * 100.0, fd);
}
