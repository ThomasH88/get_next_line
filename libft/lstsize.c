/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:52:46 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/15 16:57:56 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lstsize(t_list **head)
{
	t_list	*current;
	int		count;

	count = 0;
	if (!head || !*head)
		return (0);
	current = *head;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
