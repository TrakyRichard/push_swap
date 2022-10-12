/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/12 06:21:18 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

/* function that take the element on top of st_bdl_b and put it on st_bdl_a */
void	ft_top_x_to_top_y(t_stack_bdle *st_bdl_x, \
		t_stack_bdle *st_bdl_y, char *inst, int *swap_nbrs)
{
	int	data;
	int	chunk;

	chunk = st_bdl_x->head->chunk;
	data = st_bdl_x->head->data;
	if (st_bdl_x->size == 0)
		return ;
	ft_unshift(st_bdl_y, data, chunk);
	ft_shift(st_bdl_x);
	if (inst != NULL)
		ft_putstr_fd(inst, 1);
	*swap_nbrs += 1;
	return ;
}

/* function that take the element on top of st_bdl_a and swap
it with the next_node node of st_bdl_a */
void	ft_swap_with_next_node(t_stack_bdle *st_bdl, \
		char *inst, int *swap_nbrs)
{
	int			tmp1;
	int			chunk1;
	int			tmp2;
	int			chunk2;
	t_node		*new_node;

	if (st_bdl->size < 2)
		return ;
	tmp1 = st_bdl->head->data;
	chunk1 = st_bdl->head->chunk;
	tmp2 = st_bdl->head->next->data;
	chunk2 = st_bdl->head->next->chunk;
	ft_shift(st_bdl);
	ft_shift(st_bdl);
	ft_unshift(st_bdl, tmp1, chunk1);
	ft_unshift(st_bdl, tmp2, chunk2);
	if (inst != NULL)
		ft_putstr_fd(inst, 1);
	*swap_nbrs += 1;
	return ;
}

/* Function that swap two stack at the same time */
/* void	ft_ss(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, \
		int *swap_nbrs)
{
	ft_swap_with_next_node(st_bdl_a, NULL, swap_nbrs);
	ft_swap_with_next_node(st_bdl_b, NULL, swap_nbrs);
	ft_putstr_fd("ss ", 1);
	*swap_nbrs += 1;
	return ;
} */

/* function that take the element on top of the stack
and put it at the bottom of stack */
void	ft_mvt_top_to_bottom(t_stack_bdle *st_bdl, \
		char *inst, int *swap_nbrs)
{
	int	tmp;
	int	chunk;

	if (st_bdl->size < 2)
		return ;
	tmp = st_bdl->head->data;
	chunk = st_bdl->head->chunk;
	ft_shift(st_bdl);
	ft_push(st_bdl, tmp, chunk);
	if (inst != NULL)
		ft_putstr_fd(inst, 1);
	*swap_nbrs += 1;
	return ;
}

/* Function that reverse two swap at the same time */
/* void	ft_rr(t_stack_bdle *st_bdl_a, \
	t_stack_bdle *st_bdl_b, int *swap_nbrs)
{
	ft_mvt_top_to_bottom(st_bdl_a, NULL, swap_nbrs);
	ft_mvt_top_to_bottom(st_bdl_b, NULL, swap_nbrs);
	ft_putstr_fd("rr ", 1);
	*swap_nbrs += 1;
	return ;
} */

/* function that take the element at the bottom
of the swap and put at the bottom */
void	ft_mvt_bottom_to_top(t_stack_bdle *st_bdl_a, \
		char *inst, int *swap_nbrs)
{
	int	tmp;
	int	chunk;

	if (st_bdl_a->size < 2)
		return ;
	tmp = st_bdl_a->tail->data;
	chunk = st_bdl_a->tail->chunk;
	ft_pop(st_bdl_a);
	ft_unshift(st_bdl_a, tmp, chunk);
	if (inst != NULL)
		ft_putstr_fd(inst, 1);
	*swap_nbrs += 1;
	return ;
}

/* Function that make two rotation at the same time */
/* void	ft_rrr(t_stack_bdle *st_bdl_a, \
		t_stack_bdle *st_bdl_b, int *swap_nbrs)
{
	ft_mvt_bottom_to_top(st_bdl_a, NULL, swap_nbrs);
	ft_mvt_bottom_to_top(st_bdl_b, NULL, swap_nbrs);
	ft_putstr_fd("rrr ", 1);
	*swap_nbrs += 1;
	return ;
}
 */
