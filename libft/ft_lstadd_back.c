/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:31:30 by dcid-san          #+#    #+#             */
/*   Updated: 2024/10/02 02:06:22 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*wrap;

	if (lst != NULL && new != NULL )
	{
		if (*lst == NULL)
		{
			*lst = new;
			return ;
		}
		wrap = *lst;
		while (wrap -> next != NULL)
		{
			wrap = wrap -> next;
		}
		wrap -> next = new;
	}
}
