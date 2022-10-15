/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_helper_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 06:37:49 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/15 06:48:25 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	can_handle_b_small_cases(t_push_swap *ps)
{
	if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
	{
		hndle_stk_b_case_of_less_nbrs(ps);
		return (1);
	}
	else if (ps->chunk_to_sort.size == 2 && is_the_grtst_from_head \
			(&ps->stack_b.head->prev->prev, ps->stack_b.head->data) \
			&& is_the_grtst_from_head(&ps->stack_b.head->prev->prev, \
			ps->stack_b.head->prev->data))
	{
		hndle_stk_b_case_of_less_nbrs(ps);
		return (1);
	}
	else if (ps->chunk_to_sort.size == 1 && is_the_grtst_from_head \
			(&ps->stack_b.head->prev, ps->stack_b.head->data))
	{
		hndle_stk_b_case_of_less_nbrs(ps);
		return (1);
	}
	return (0);
}

void	init_preliminary_of_b(t_push_swap *ps)
{
	can_finished_process(ps);
	retrieve_chunk_to_sort_of_b(ps);
	return ;
}
