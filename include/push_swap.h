/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:11:46 by soutin            #+#    #+#             */
/*   Updated: 2023/06/27 23:38:49 by soutin           ###   ########.fr       */
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
	struct s_infos	*infos;
}					ps_list;

typedef struct s_infos
{
	int				size_a;
	int				size_b;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_infos;

/*Handling input*/

int					check_and_fill(char **v, ps_list **head);
int					check_duplicate(ps_list **head);
int					is_sorted(ps_list **head);
ps_list				*ps_atoi(const char *nptr, int *flag);
void				printlist(ps_list **head);
void				radib(ps_list **a, ps_list **b, int len, int shift,
						int max_bt);
/*Handling linked lists*/
void				radix(ps_list **a, ps_list **b);

ps_list				*ps_lstnew(int content);
int					ps_lstsize(ps_list **head);
void				normalize(ps_list **head);
ps_list				*ps_lstlast(ps_list **lst);
int	find_next(ps_list **a, int shift);

/*Mandatory operations*/
void				mini_algo_x3(ps_list **a);

ps_list				*swap(ps_list **a_pile);
ps_list				*push(ps_list **a_pile, ps_list **b_pile);
ps_list				*rotate(ps_list **head);
ps_list				*reverse_rotate(ps_list **head);
int					get_nb_bits(int max);
void				divide_list(ps_list **a, ps_list **b);

ps_list				*sa(ps_list **a);
ps_list				*sb(ps_list **b);
ps_list				*pa(ps_list **a, ps_list **b);
ps_list				*pb(ps_list **a, ps_list **b);
ps_list				*ra(ps_list **a);
ps_list				*rb(ps_list **b);
ps_list				*rr(ps_list **a, ps_list **b);
ps_list				*rra(ps_list **a);
ps_list				*rrb(ps_list **b);

#endif