/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:46:32 by dcid-san          #+#    #+#             */
/*   Updated: 2024/10/17 20:20:50 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

/*
int ft_put_str(char c)
{
	if (c == NULL)
}*/

int	ft_print_str(char *str)
{
	int	size;

	size = 0;
	if (str == NULL)
		str = "(null)";
	while (str[size])
	{
		write(1, &str[size], 1);
		size++;
	}
	return (size);
}
