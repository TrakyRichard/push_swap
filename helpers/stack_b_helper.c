/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:26:27 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 07:26:27 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	retrieve_chunk_to_sort_of_b(t_push_swap *ps)
{
	can_finished_process(ps);
	get_chunk_to_sort_from_head(&ps->chunk_to_sort, ps->stack_b.tail->chunk, \
		ps->stack_b);
	if (ps->chunk_to_sort.size > 2 \
		&& ps->stack_b.tail->data < ps->stack_b.head->data)
	{
		get_elts_reversed_of_stack_b_to_top(ps, ps->stack_b.head->chunk);
		get_chunk_to_sort_from_head(&ps->chunk_to_sort, \
		ps->stack_b.tail->chunk, ps->stack_b);
	}
	return ;
}

void	push_sorted_chunk_in_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
	if (ft_is_rev_sorted(&ps->stack_a.tail) && \
		ps->stack_b.tail->data >= ps->stack_b.head->data)
	{
		if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
			hndle_stk_b_case_of_less_nbrs(ps);
		else if (ps->chunk_to_sort.size == 2 && is_the_grtst_from_tail \
				(&ps->stack_b.tail->prev->prev, ps->stack_b.tail->data) \
				&& is_the_grtst_from_tail(&ps->stack_b.tail->prev->prev, \
				ps->stack_b.tail->prev->data))
			hndle_stk_b_case_of_less_nbrs(ps);
		else if (ps->chunk_to_sort.size == 1 && is_the_grtst_from_tail \
				(&ps->stack_b.tail->prev, ps->stack_b.tail->data))
			hndle_stk_b_case_of_less_nbrs(ps);
		else
		{
			ps->stack_b.tail->chunk = ps->stack_b.head->chunk;
			ft_mvt_top_to_bottom(&ps->stack_b, "rb\n", &ps->nbre_of_swap);
		}
	}
	else
	{
		get_elts_reversed_of_stack_b_to_top(ps, ps->stack_b.head->chunk);
		get_chunk_to_sort_from_head(&ps->chunk_to_sort, \
		ps->stack_b.tail->chunk, ps->stack_b);
	}
	return ;
}

void	preliminary_of_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
	int	can_turn;

	can_turn = 0;
	can_finished_process(ps);
	retrieve_chunk_to_sort_of_b(ps);
	while (ps->chunk_to_sort.size == 2 || ps->chunk_to_sort.size == 1)
	{
		if (ft_is_rev_sorted(&ps->stack_a.tail) && \
			ps->stack_b.tail->data >= ps->stack_b.head->data)
		{
			if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
				hndle_stk_b_case_of_less_nbrs(ps);
			else if (ps->chunk_to_sort.size == 2 && is_the_grtst_from_tail \
					(&ps->stack_b.tail->prev->prev, ps->stack_b.tail->data) \
					&& is_the_grtst_from_tail(&ps->stack_b.tail->prev->prev, \
					ps->stack_b.tail->prev->data))
				hndle_stk_b_case_of_less_nbrs(ps);
			else if (ps->chunk_to_sort.size == 1 && is_the_grtst_from_tail \
					(&ps->stack_b.tail->prev, ps->stack_b.tail->data))
				hndle_stk_b_case_of_less_nbrs(ps);
			else
			{
				ps->stack_b.tail->chunk = ps->stack_b.head->chunk;
				ft_mvt_top_to_bottom(&ps->stack_b, "rb\n", &ps->nbre_of_swap);
				break ;
			}
		}
		else
		{
			get_elts_reversed_of_stack_b_to_top(ps, ps->stack_b.head->chunk);
			get_chunk_to_sort_from_head(&ps->chunk_to_sort, \
			ps->stack_b.tail->chunk, ps->stack_b);
			break ;
		}
		if (ps->stack_b.size > 0)
			retrieve_chunk_to_sort_of_b(ps);
		else
			break ;
	}
	ps->sorted_stack = ft_r_sort(ps->chunk_to_sort);
	ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
	return ;
}

void	handle_stack_b_two_nbrs_case(t_push_swap *ps)
{
	if (ps->stack_b.tail->data >= ps->stack_b.tail->prev->data)
	{
		ps->stack_b.tail->chunk = 0;
		ft_top_x_to_top_y(&ps->stack_b, &ps->stack_a, \
		"pb\n", &ps->nbre_of_swap);
		ps->stack_b.tail->chunk = 0;
		ft_top_x_to_top_y(&ps->stack_b, &ps->stack_a, \
		"pb\n", &ps->nbre_of_swap);
	}
	else
	{
		ft_swap_with_next_node(&ps->stack_b, "sb\n", &ps->nbre_of_swap);
		ps->stack_b.tail->chunk = 0;
		ft_top_x_to_top_y(&ps->stack_b, &ps->stack_a, \
		"pb\n", &ps->nbre_of_swap);
		ps->stack_b.tail->chunk = 0;
		ft_top_x_to_top_y(&ps->stack_b, &ps->stack_a, \
		"pb\n", &ps->nbre_of_swap);
	}
	return ;
}

/* Handle the case of 2 numbers into the stack */
void	hndle_stk_b_case_of_less_nbrs(t_push_swap *ps)
{
	if (ps->chunk_to_sort.size == 1)
	{
		if (ft_is_rev_sorted(&ps->stack_a.tail))
			ps->stack_b.tail->chunk = 0;
		ft_top_x_to_top_y(&ps->stack_b, &ps->stack_a, \
		"pb\n", &ps->nbre_of_swap);
	}
	else if (ps->chunk_to_sort.size == 2)
		handle_stack_b_two_nbrs_case(ps);
	ps->chunk_to_sort.size = 0;
	can_finished_process(ps);
	return ;
}
