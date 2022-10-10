/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:22:13 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 07:22:13 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Handle the case of 2 numbers into the stack */
void	handle_stack_a_case_of_less_nbrs(t_push_swap *ps)
{
	if (ps->chunk_to_sort.size == 1 && ft_is_rev_sorted(&ps->stack_a.head) \
		&& is_the_grtst_from_head(&ps->stack_b.head, ps->stack_a.head->data))
		ps->stack_a.head->chunk = 0;
	else if (ps->chunk_to_sort.size == 2 \
		&& is_the_grtst_from_head(&ps->stack_b.head, ps->stack_a.head->data) \
		&& is_the_grtst_from_head(&ps->stack_b.head, \
			ps->stack_a.head->prev->data))
	{
		if (ps->stack_a.head->data > ps->stack_a.head->prev->data)
		{
			ps->stack_a.head->chunk = 0;
			ft_swap_with_next_node(&ps->stack_a, "sa", &ps->nbre_of_swap);
			ps->stack_a.head->chunk = 0;
		}
		else
		{
			ps->stack_a.head->chunk = 0;
			ps->stack_a.head->prev->chunk = 0;
		}
	}
	ps->middle->size = 1;
	can_finished_process(ps);
	return ;
}

void	retrieve_chunk_to_sort_of_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
	ft_init_stack_bdle(&ps->chunk_to_sort);
	ft_init_stack_bdle(&ps->sorted_stack);
	if (ft_is_rev_sorted(&ps->stack_a.head) == 0)
	{
		if (ps->stack_a.head->chunk == 0 && ps->stack_a.tail->chunk != 0)
		{
			get_elements_reversed_of_stack_a_to_top(ps, \
				ps->stack_a.tail->chunk);
			get_chunk_to_sort_from_tail(&ps->chunk_to_sort, \
				ps->stack_a.head->chunk, ps->stack_a);
		}
		else
			get_chunk_to_sort_from_tail(&ps->chunk_to_sort, \
				ps->stack_a.head->chunk, ps->stack_a);
	}
	return ;
}

void	preliminary_of_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
	if (ft_is_rev_sorted(&ps->stack_a.head) == 0)
	{
		retrieve_chunk_to_sort_of_a(ps, flg_a, flg_b);
		while ((ps->chunk_to_sort.size == 2 || ps->chunk_to_sort.size == 1))
		{
			handle_stack_a_case_of_less_nbrs(ps);
			retrieve_chunk_to_sort_of_a(ps, flg_a, flg_b);
		}
		ps->sorted_stack = ft_r_sort(ps->chunk_to_sort);
		ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
	}
	return ;
}
