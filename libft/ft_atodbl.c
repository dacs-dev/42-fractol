/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:15:22 by dcid-san          #+#    #+#             */
/*   Updated: 2024/09/25 20:03:57 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double ft_atodbl(const char *str)
{
	long   int_part;
	double decimal_part;
	int    is_neg;

	is_neg = 1;
	int_part = 0;
	while (*str == ' ' || *str == '\f' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		int_part += (*str - 48);
		if (str[1] != '\0' && str[1] >= '0' && str[1] <= '9')
			int_part *= 10;
		str++;
	}
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		int_part += (*str - 48);
		if (str[1] != '\0' && str[1] >= '0' && str[1] <= '9')
			int_part *= 10;
		str++;
	}
	return (int_part * is_neg);
}
