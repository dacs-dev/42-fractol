/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:53:22 by dcid-san          #+#    #+#             */
/*   Updated: 2025/04/04 17:35:15 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisdbl(char *str)
{
	int	dot;

	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	dot = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
			return (0);
		if (*str == '-' || *str == '+')
			return (0);
		if (*str == '.' && dot == 1)
			return (0);
		if (*str == '.')
			dot = 1;
		else if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
