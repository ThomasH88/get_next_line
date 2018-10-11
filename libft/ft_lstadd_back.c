/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:41:59 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/10 16:02:20 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *elem)
{
	t_list	*current;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = elem;
		return ;
	}
	current = *lst;
	while (current && current->next)
		current = current->next;
	if (elem)
		current->next = elem;
}
