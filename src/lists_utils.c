/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:50:22 by soutin            #+#    #+#             */
/*   Updated: 2023/06/29 18:19:22 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ps_lstsize(t_pslist **head)
{
	int			i;
	t_pslist	*tmp;

	tmp = *head;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_pslist	*ps_lstlast(t_pslist **lst)
{
	t_pslist	*tmp;

	tmp = *lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_pslist	*ps_lstnew(int content)
{
	t_pslist	*c;

	c = malloc(sizeof(*c));
	if (!c)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}

void	ps_lstclear(t_pslist **lst)
{
	t_pslist	*t;
	t_pslist	*buf;

	if (!lst)
		return ;
	t = *lst;
	while (t)
	{
		buf = t->next;
		free(t);
		t = buf;
	}
	*lst = NULL;
}
