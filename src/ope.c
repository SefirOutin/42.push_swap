/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:14:57 by soutin            #+#    #+#             */
/*   Updated: 2023/06/27 23:06:33 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

ps_list	*sa(ps_list **a)
{
	ft_printf("sa\n");
	return (swap(a));
}

ps_list	*sb(ps_list **b)
{
	ft_printf("sb\n");
	return (swap(b));
}

ps_list	*pa(ps_list **a, ps_list **b)
{
	ft_printf("pa\n");
	return (push(b, a));
}

ps_list	*pb(ps_list **a, ps_list **b)
{
	ft_printf("pb\n");
	return (push(a, b));
}

ps_list	*ra(ps_list **a)
{
	ft_printf("ra\n");
	return (rotate(a));
}

ps_list *rb(ps_list **b)
{
	ft_printf("rb\n");
	return (rotate(b));
}

ps_list	*rr(ps_list **a, ps_list **b)
{
	ft_printf("rr\n");
	rotate(b);
	return (rotate(a));
}

ps_list	*rra(ps_list **a)
{
	ft_printf("rra\n");
	return (reverse_rotate(a));
}

ps_list	*rrb(ps_list **b)
{
	ft_printf("rrb\n");
	return (reverse_rotate(b));
}

