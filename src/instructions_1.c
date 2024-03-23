/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:14:57 by soutin            #+#    #+#             */
/*   Updated: 2023/06/29 18:18:26 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pslist	*sa(t_pslist **a)
{
	ft_printf("sa\n");
	return (swap(a));
}

t_pslist	*sb(t_pslist **b)
{
	ft_printf("sb\n");
	return (swap(b));
}

t_pslist	*pa(t_pslist **a, t_pslist **b)
{
	ft_printf("pa\n");
	return (push(b, a));
}

t_pslist	*pb(t_pslist **a, t_pslist **b)
{
	ft_printf("pb\n");
	return (push(a, b));
}
