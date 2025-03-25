/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:32:30 by dcid-san          #+#    #+#             */
/*   Updated: 2024/09/27 18:24:39 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst -> next != NULL)
		{
			f(lst -> content);
			lst = lst -> next;
		}
		f(lst -> content);
	}
}
