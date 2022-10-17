/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sorting_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/17 04:42:54 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
/* Refacto finished */
void	ft_stack_a_sorting_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
	int	chunk_track;

	chunk_track = ps->stack_a.head->chunk + 1;
	while (*flg_a && *flg_b == 0 && ft_is_sorted(&ps->stack_a.head) == 0)
	{
		preliminary_of_stack_a(ps);
		is_chunk_a_already_sorted(ps);
		check_flag_status(ps, flg_a, flg_b);
		chunk_track++;
		while (ps->middle->size > 1 && *flg_a)
		{
			ft_push_to_stack_b(ps, flg_a, chunk_track);
			ft_reverse_stack_a(ps);
		}
		if (ps->stack_a.tail->chunk != 0)
			get_elements_reversed_of_stack_a_to_top(ps, \
				ps->stack_b.tail->chunk);
		check_flag_status(ps, flg_a, flg_b);
	}
	return ;
}

void	ft_push_to_stack_b(t_push_swap *ps, int *flg_a, \
			int chunk_track)
{
	while (ps->stack_a.head->data < ps->middle->value && *flg_a && \
			ps->stack_a.head->chunk == ps->chunk_to_sort.head->chunk)
	{
		ps->stack_a.head->chunk = chunk_track;
		ft_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pa\n");
		ps->middle->size--;
	}
	return ;
}

void	is_chunk_a_already_sorted(t_push_swap *ps)
{
	if (ps->chunk_to_sort.size > 0)
	{
		while (ft_is_sorted(&ps->chunk_to_sort.head))
		{
			while (ps->chunk_to_sort.size > 0)
			{
				ps->stack_a.head->chunk = 0;
				ft_pop(&ps->chunk_to_sort);
			}
			preliminary_of_stack_a(ps);
		}
	}
	return ;
}

/* Get reversed elements back to top of stack a */
void	get_elements_reversed_of_stack_a_to_top(t_push_swap *ps, int chunk_nbrs)
{
	t_stack_bdle	*stack_a;

	stack_a = &ps->stack_a;
	while (stack_a->tail->chunk == chunk_nbrs)
		ft_mvt_bottom_to_top(stack_a, "rra\n");
	return ;
}

void	ft_reverse_stack_a(t_push_swap *ps)
{
	int	tail;

	tail = ps->stack_a.tail->data;
	while (ps->stack_a.head->data >= ps->middle->value && \
		ft_is_sorted(&ps->stack_a.head) == 0 && \
		ps->chunk_to_sort.head->chunk == ps->stack_a.head->chunk)
	{
		ft_mvt_top_to_bottom(&ps->stack_a, "ra\n");
		if (tail == ps->stack_a.head->data)
			break ;
	}
	return ;
}
