/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:20:24 by soutin            #+#    #+#             */
/*   Updated: 2023/07/09 16:17:28 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	which_one(t_pslist **a, t_pslist **b)
{
	int	size;

	size = ps_lstsize(a);
	if (size == 3 || size == 2)
		mini_algo_x3(a);
	else if (size < 11)
		mini_algo(a, b);
	else
		radix(a, b);
}

int	main(int c, char **v)
{
	t_pslist	*a_pile;
	t_pslist	*b_pile;

	a_pile = NULL;
	b_pile = NULL;
	if (c > 1)
	{
		if (check_and_fill(v, &a_pile))
			return (write(2, "Error\n", 6), 0);
		if (ps_lstsize(&a_pile) < 2 || is_sorted(&a_pile))
			return (ps_lstclear(&a_pile), 0);
		normalize(&a_pile);
		which_one(&a_pile, &b_pile);
	}
	ps_lstclear(&a_pile);
	return (0);
}

// void	printlist(t_pslist **head)
// {
// 	t_pslist	*current;

// 	current = *head;
// 	while (current != NULL)
// 	{
// 		ft_printf("%d ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("\n");
// }
