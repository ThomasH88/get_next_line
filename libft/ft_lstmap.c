/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:34:09 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/10 16:02:21 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*new;

	if (!lst)
		return (NULL);
	current = lst;
	new = NULL;
	while (current)
	{
		ft_lstadd_back(&new, f(current));
		current = current->next;
	}
	return (new);
}
