/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:17:26 by soutin            #+#    #+#             */
/*   Updated: 2023/07/05 19:28:05 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicate(t_pslist **head)
{
	t_pslist	*tmp;
	t_pslist	*buf;

	tmp = *head;
	while (tmp)
	{
		buf = tmp->next;
		while (buf)
		{
			if (tmp->content == buf->content)
				return (1);
			buf = buf->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	fill(char *v, t_pslist **head)
{
	int			flag;
	t_pslist	*last;

	if (*head == NULL)
		*head = ps_atoi(v, &flag);
	else
	{
		last = ps_lstlast(head);
		last->next = ps_atoi(v, &flag);
		if (!last->next)
			return (-1);
	}
	if (flag)
		return (1);
	return (0);
}

int	check_and_fill(char **v, t_pslist **head)
{
	int	i;
	int	error;

	i = 1;
	while (v[i])
	{
		error = fill(v[i], head);
		if (error == 1)
			return (ps_lstclear(head), 1);
		else if (error == -1)
			return (ps_lstclear(head), 0);
		i++;
	}
	if (check_duplicate(head))
		return (ps_lstclear(head), 1);
	return (0);
}

t_pslist	*ps_atoi(const char *nptr, int *flag)
{
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	*flag = 1;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			sign *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number = number * 10 + (*nptr - 48);
		nptr++;
		*flag = 0;
	}
	number *= sign;
	if (*nptr || number > INT_MAX || number < INT_MIN)
		*flag = 1;
	return (ps_lstnew(number));
}
