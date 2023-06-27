/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:50:22 by soutin            #+#    #+#             */
/*   Updated: 2023/06/27 22:23:57 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	ps_lstsize(ps_list **head)
{
	int	i;
	ps_list	*tmp;

	tmp = *head;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

ps_list	*ps_lstlast(ps_list **lst)
{
	ps_list	*tmp;

	tmp = *lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

ps_list	*ps_lstnew(int content)
{
	ps_list	*c;

	c = malloc(sizeof(*c));
	if (!c)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}

void	normalize(ps_list **head)
{
	ps_list	*tmp;
	ps_list	*buf;

	tmp = *head;
	if (!*head)
		return ;
	while (tmp)
	{
		buf = *head;
		while (buf)
		{
			if (tmp->content > buf->content)
				tmp->index++;
			buf = buf->next;
		}
		tmp = tmp->next;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}