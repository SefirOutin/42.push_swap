/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:16:48 by soutin            #+#    #+#             */
/*   Updated: 2023/07/05 19:24:59 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_nb_bits(int max)
{
	int	i;

	i = 0;
	while (max >= 2)
	{
		max /= 2;
		i++;
	}
	i++;
	return (i);
}

int	is_sorted(t_pslist **head)
{
	t_pslist	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	normalize(t_pslist **head)
{
	t_pslist	*tmp;
	t_pslist	*buf;

	tmp = *head;
	if (!*head)
		return ;
	while (tmp)
	{
		tmp->index = 0;
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
