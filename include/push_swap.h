/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:11:46 by soutin            #+#    #+#             */
/*   Updated: 2023/07/03 17:59:14 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct p_list
{
	int				content;
	int				index;
	struct p_list	*next;
}					t_pslist;

/*Handling input*/

int					check_and_fill(char **v, t_pslist **head);
int					check_duplicate(t_pslist **head);
int					is_sorted(t_pslist **head);
t_pslist			*ps_atoi(const char *nptr, int *flag);
void				wich_one(t_pslist **a, t_pslist **b);

/*Handling linked lists*/

t_pslist			*ps_lstnew(int content);
int					ps_lstsize(t_pslist **head);
t_pslist			*ps_lstlast(t_pslist **lst);
void				ps_lstclear(t_pslist **lst);
void				printlist(t_pslist **head);
int					b_sorted(t_pslist **b);

/*Mandatory operations*/

t_pslist			*swap(t_pslist **a_pile);
t_pslist			*push(t_pslist **a_pile, t_pslist **b_pile);
t_pslist			*rotate(t_pslist **head);
t_pslist			*reverse_rotate(t_pslist **head);

t_pslist			*sa(t_pslist **a);
t_pslist			*sb(t_pslist **b);
t_pslist			*pa(t_pslist **a, t_pslist **b);
t_pslist			*pb(t_pslist **a, t_pslist **b);
t_pslist			*ra(t_pslist **a);
t_pslist			*rb(t_pslist **b);
t_pslist			*rr(t_pslist **a, t_pslist **b);
t_pslist			*rra(t_pslist **a);
t_pslist			*rrb(t_pslist **b);

/*Algorithms*/

void				radix(t_pslist **a, t_pslist **b);
void				radib(t_pslist **a, t_pslist **b, int shift);
void				mini_algo_x3(t_pslist **a);
void				mini_algo(t_pslist **a, t_pslist **b);
int					get_nb_bits(int max);
void				normalize(t_pslist **head);

#endif