/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:12:38 by soutin            #+#    #+#             */
/*   Updated: 2023/07/05 19:37:55 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix(t_pslist **a, t_pslist **b)
{
	int	shift;
	int	max_nb_bits;
	int	size;

	shift = 0;
	max_nb_bits = get_nb_bits(ps_lstsize(a) - 1);
	while (shift < max_nb_bits)
	{
		size = ps_lstsize(a);
		while (size)
		{
			if (!(((*a)->index >> shift) & 1) && !is_sorted(a))
				pb(a, b);
			else if (!is_sorted(a))
				ra(a);
			size--;
		}
		radib(a, b, ++shift);
	}
	while (ps_lstsize(b))
		pa(a, b);
}

void	radib(t_pslist **a, t_pslist **b, int shift)
{
	int	max_nb_bits;
	int	size;

	size = ps_lstsize(b);
	max_nb_bits = get_nb_bits(ps_lstsize(a) + ps_lstsize(b) - 2);
	while (size)
	{
		if (((*b)->index >> shift) & 1)
			pa(a, b);
		else if (shift < max_nb_bits)
			rb(b);
		size--;
	}
}

void	mini_algo_x3(t_pslist **a)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		if ((*a)->index > ps_lstlast(a)->index)
			ra(a);
		if ((*a)->index > (*a)->next->index
			&& (*a)->index > ps_lstlast(a)->index)
			ra(a);
		if ((*a)->next->index > ps_lstlast(a)->index)
			rra(a);
		i++;
	}
}

void	mini_algo(t_pslist **a, t_pslist **b)
{
	int	size;
	int	max;
	int	i;

	size = ps_lstsize(a);
	max = size - 3;
	i = 0;
	while (i < size)
	{
		if ((*a)->index < max)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	mini_algo_x3(a);
	while (ps_lstsize(b))
	{
		if ((*b)->index + 1 == (*a)->index)
			pa(a, b);
		else
			rb(b);
	}
}
