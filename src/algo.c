/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:12:38 by soutin            #+#    #+#             */
/*   Updated: 2023/06/27 23:38:41 by soutin           ###   ########.fr       */
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

int	b_sorted(ps_list **b)
{
	ps_list	*tmp;

	tmp = *b;
	while (tmp->next)
	{
		if (tmp->index < tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	radix(ps_list **a, ps_list **b)
{
	int	i;
	int	max_bt;
	int	size;
	ps_list	*tmp;

	i = 0;
	max_bt = get_nb_bits(ps_lstsize(a) - 1);
	while (i < max_bt)
	{
		size = ps_lstsize(a);
		while (size)
		{
			tmp = *a;
			if (!((tmp->index >> i) & 1))
				pb(a, b);
			else
				ra(a);
			size--;
		}
		i++;
		radib(a, b, ps_lstsize(b), i, max_bt);
		if ((is_sorted(a) && !b) || (is_sorted(a) && b_sorted(b)))
			break;
	}
	while (ps_lstsize(b))
		pa(a, b);
}

int	find_next(ps_list **a, int shift)
{
	int	i;
	ps_list	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (!((tmp->index >> shift) & 1))
			return (i);
		tmp = tmp->next;
	}
	return (-1);
}

void	radib(ps_list **a, ps_list **b, int len, int shift, int	max_bt)
{
	ps_list	*tmp;
	int	to_move;

	to_move = find_next(a, shift);
	tmp = *b;
	while (len)
	{
		if ((tmp->index >> shift) & 1)
			tmp = pa(a, b);
		else if (shift < max_bt && to_move)
		{
			tmp = rr(a, b);
			to_move--;
		}
		else if (shift < max_bt)
			tmp = rb(b);
		len--;
	}
}

void	mini_algo_x3(ps_list **a)
{
	ps_list	*tmp;

	tmp = *a;
	while (!is_sorted(a))
	{
		if (tmp->index > tmp->next->index)
			tmp = sa(a);
		else if (tmp->index > ps_lstlast(a)->index)
			tmp = rra(a);
		else if (tmp->next->index < ps_lstlast(a)->index)
			tmp = ra(a);
	}	
}


// void	mini_algo(ps_list **a, ps_list **b)
// {
// 	ps_list	*tmp;
// 	int	size;

// 	tmp = *a;
// 	size = ps_lstsize(a) - 1;
// 	while (!check_if_sorted(a))
// 	{
// 		while (tmp->index != size && ps_lstsize(a) != 1)
// 		{
			
// 		}
// 	}
	
// }