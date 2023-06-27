/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:42:22 by soutin            #+#    #+#             */
/*   Updated: 2023/06/27 22:19:27 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

ps_list	*swap(ps_list **head)
{
	ps_list	*tmp;
	ps_list	*buf;

	if (ps_lstsize(head) > 1)
	{
		buf = *head;
		tmp = buf->next;
		buf->next = tmp->next;
		tmp->next = *head;
		*head = tmp;
		return (*head);
	}
	return (NULL);
}

ps_list	*push(ps_list **from, ps_list **to)
{
	ps_list	*tmp;
	
	if (!*from)
		return (NULL);
	tmp = *from;
	*from = tmp->next;
	if (to)
		tmp->next = *to;
	else
		tmp->next = NULL;
	*to = tmp;
	return (*from);
}

ps_list	*rotate(ps_list	**head)
{
	ps_list	*tmp;
	ps_list	*last;

	if (!*head)
		return (NULL);
	tmp = *head;
	last = *head;
	*head = tmp->next;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	return (*head);
}

ps_list	*reverse_rotate(ps_list **head)
{
	ps_list	*tmp;
	ps_list	*last;

	if (!*head)
		return (NULL);
	tmp = *head;
	last = *head;
	while (last->next->next)
		last = last->next;
	last->next->next = tmp;
	*head = last->next;
	last->next = NULL;
	return (*head);
}