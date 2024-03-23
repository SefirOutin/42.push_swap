/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:11:18 by soutin            #+#    #+#             */
/*   Updated: 2023/06/29 18:18:34 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pslist	*ra(t_pslist **a)
{
	ft_printf("ra\n");
	return (rotate(a));
}

t_pslist	*rb(t_pslist **b)
{
	ft_printf("rb\n");
	return (rotate(b));
}

t_pslist	*rr(t_pslist **a, t_pslist **b)
{
	ft_printf("rr\n");
	rotate(b);
	return (rotate(a));
}

t_pslist	*rra(t_pslist **a)
{
	ft_printf("rra\n");
	return (reverse_rotate(a));
}

t_pslist	*rrb(t_pslist **b)
{
	ft_printf("rrb\n");
	return (reverse_rotate(b));
}
