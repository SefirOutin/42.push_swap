/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:42:22 by soutin            #+#    #+#             */
/*   Updated: 2023/06/29 18:18:29 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pslist	*swap(t_pslist **head)
{
	t_pslist	*tmp;
	t_pslist	*buf;

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

t_pslist	*push(t_pslist **from, t_pslist **to)
{
	t_pslist	*tmp;

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

t_pslist	*rotate(t_pslist **head)
{
	t_pslist	*tmp;
	t_pslist	*last;

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

t_pslist	*reverse_rotate(t_pslist **head)
{
	t_pslist	*tmp;
	t_pslist	*last;

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
