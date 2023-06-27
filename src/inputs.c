/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:17:26 by soutin            #+#    #+#             */
/*   Updated: 2023/06/27 22:50:42 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	check_duplicate(ps_list **head)
{
	ps_list	*current;
	ps_list	*tmp;

	current = *head;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_and_fill(char **v, ps_list **head)
{
	int	i;
	int	flag;
	ps_list	*current;

	flag = 0;
	i = 1;
	while (v[i])
	{
		if (*head == NULL)
			*head = ps_atoi(v[i], &flag);
		else
		{
			current = *head;
			while (current->next)
				current = current->next;
			current->next = ps_atoi(v[i], &flag);
		}
		if (flag)
			return (1);
		i++;
	}
	if (check_duplicate(head) || i < 2)
		return (1);
	return (0);
}

int	is_sorted(ps_list **head)
{
	ps_list	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

ps_list	*ps_atoi(const char *nptr, int *flag)
{
	long long	number;
	int			sign;
	int			nbs;

	nbs = 0;
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
