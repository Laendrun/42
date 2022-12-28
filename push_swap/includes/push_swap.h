/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:24:25 by saeby             #+#    #+#             */
/*   Updated: 2022/12/28 13:15:50 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include "push_swap_struct.h"
# include "libft.h"

// main.c
t_lists	*sort(t_lists *stacks);
t_lists	*parse_args(t_lists *stacks, int ac, char *av[]);

// ps_list_1.c
t_dlist	*ps_lstnew(int content);
void	ps_lstadd_back(t_dlist **lst, t_dlist *new);
void	ps_lstadd_front(t_dlist **lst, t_dlist *new);
int		ps_lstsize(t_dlist *lst);
t_dlist	*ps_lstlast(t_dlist *lst);

// ps_list_2.c
t_dlist	*ps_lstswap(t_dlist *lst);
t_lists	*ps_lstpushb(t_lists *stacks);
t_lists	*ps_lstpusha(t_lists *stacks);
t_dlist	*ps_lstrotate(t_dlist *lst);
t_dlist	*ps_lstrrotate(t_dlist *lst);

// ps_list_3.c
t_dlist	*ps_lstfirst(t_dlist *lst);
void	ps_lstclear(t_dlist *lst);

// ps_swap.c
t_lists	*ps_sa(t_lists *stacks);
t_lists	*ps_sb(t_lists *stacks);
t_lists	*ps_ss(t_lists *stacks);

// ps_push.c
t_lists	*ps_pa(t_lists *stacks);
t_lists	*ps_pb(t_lists *stacks);

// ps_rotate.c
t_lists	*ps_ra(t_lists *stacks);
t_lists	*ps_rb(t_lists *stacks);
t_lists	*ps_rr(t_lists *stacks);

// ps_rev_rotate.c
t_lists	*ps_rra(t_lists *stacks);
t_lists	*ps_rrb(t_lists *stacks);
t_lists	*ps_rrr(t_lists *stacks);

// debug.c
void	ps_lstprint(t_dlist *lst);

// utils.c
void	ps_error(t_lists *stacks);
int		ps_duplicate(t_dlist *a, int num);
long	ps_get_max(t_dlist *a);
long	ps_get_min(t_dlist *a);
int		ps_str_is_posneg(char *s);

// utils2.c
t_dlist	*ps_ptr_to_min(t_dlist *a);
t_dlist	*ps_ptr_to_max(t_dlist *a);

// check.c
int		is_sorted(t_lists *stacks);

// normalize.c
t_lists	*ps_normalize(t_lists *stacks);

// small_sort.c
t_lists	*ps_small_sort(t_lists *stacks);
t_lists	*ps_sort_three(t_lists *stacks);
t_lists	*ps_sort_four(t_lists *stacks);
t_lists	*ps_sort_five(t_lists *stacks);

// big_sort.c
t_lists	*ps_big_sort(t_lists *stacks);

// sort_utils.c
t_lists	*ps_push_smallest_up_a(t_lists *stacks);
t_lists	*ps_push_smallest_up_b(t_lists *stacks);
t_lists	*ps_push_biggest_up_b(t_lists *stacks);
int		ps_get_index(t_dlist *s, int num);
int		ps_get_value_index(t_dlist *s, int index);

#endif