/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:54:25 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/15 14:10:12 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstadd_front(t_list **head, char *data)
{
	t_list	*tmp;
	t_list	*new;

	if (!head)
		return ;
	new = lstnew(data);
	if (!*head)
		*head = new;
	else
	{
		tmp = new;
		tmp->next = *head;
		new = *head;
		*head = tmp;
	}
}
