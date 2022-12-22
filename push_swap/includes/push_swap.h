/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:24:25 by saeby             #+#    #+#             */
/*   Updated: 2022/12/22 19:45:40 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include "push_swap_struct.h"
# include "libft.h"

// ps_list_1.c
t_dlist	*ps_lstnew(int content);
void	ps_lstadd_back(t_dlist **lst, t_dlist *new);
void	ps_lstadd_front(t_dlist **lst, t_dlist *new);
int		ps_lstsize(t_dlist *lst);
t_dlist	*ps_lstlast(t_dlist *lst);

// ps_list_2.c
t_dlist	*ps_lstfirst(t_dlist *lst);
t_dlist	*ps_lstswap(t_dlist *lst);
t_lists	*ps_lstpushb(t_lists *stacks);
t_lists	*ps_lstpusha(t_lists *stacks);
t_dlist	*ps_lstrotate(t_dlist *lst);
t_dlist	*ps_lstrrotate(t_dlist *lst);

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
void	ps_error(void);
int		ps_duplicate(t_dlist *a, int num);

#endif