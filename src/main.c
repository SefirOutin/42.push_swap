/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:20:24 by soutin            #+#    #+#             */
/*   Updated: 2023/06/27 23:38:56 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
void	printlist(ps_list **head);

int	main(int c, char **v)
{
	ps_list	*a_pile;
	ps_list	*b_pile;
	
	a_pile = NULL;
	b_pile = NULL;
	if (c == 2)
		write(2, "Error\n", 6);
	if (c > 2)
	{
		if (check_and_fill(v, &a_pile) || is_sorted(&a_pile))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		normalize(&a_pile);
		if (ps_lstsize(&a_pile) == 3)
			mini_algo_x3(&a_pile);
		else
			radix(&a_pile, &b_pile);
		ft_printf("a : ");
		printlist(&a_pile);
		ft_printf("b : ");
		printlist(&b_pile);
	}
	
	return (0);
}

void	printlist(ps_list **head)
{
	ps_list *current;

	current = *head;
	while (current != NULL)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("\n");
}