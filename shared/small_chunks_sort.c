/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_chunks_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:20:52 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 08:20:52 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
/* Refacto finished rapidly */
void	hndle_mid_value_is_greatst(t_push_swap *ps)
{
	if (ps->stack_a.tail->data < ps->stack_a.head->data)
		ft_mvt_bottom_to_top(&ps->stack_a, "rra\n");
	else
	{
		ft_mvt_bottom_to_top(&ps->stack_a, "rra\n");
		ft_swap_with_next_node(&ps->stack_a, "sa\n");
	}
	return ;
}

void	handle_head_is_greatst(t_push_swap *ps)
{
	if (ps->stack_a.head->next->data < ps->stack_a.tail->data)
		ft_mvt_top_to_bottom(&ps->stack_a, "ra\n");
	else
	{
		ft_swap_with_next_node(&ps->stack_a, "sa\n");
		ft_mvt_bottom_to_top(&ps->stack_a, "rra\n");
	}
	return ;
}

void	ft_sort_three(t_push_swap *ps)
{
	if (ps->stack_a.tail->data > ps->stack_a.head->next->data &&
		ps->stack_a.tail->data > ps->stack_a.head->data)
	{
		if (ps->stack_a.head->next->data < ps->stack_a.head->data)
			ft_swap_with_next_node(&ps->stack_a, "sa\n");
	}
	else if (ps->stack_a.head->next->data > ps->stack_a.tail->data &&
			 ps->stack_a.head->next->data > ps->stack_a.head->data)
		hndle_mid_value_is_greatst(ps);
	else if (ps->stack_a.head->data > ps->stack_a.tail->prev->data && \
			ps->stack_a.head->data > ps->stack_a.tail->data)
		handle_head_is_greatst(ps);
	can_finished_process(ps);
	return ;
}

void	ft_sort_five(t_push_swap *ps)
{
	int	i;

	i = 0;
	ft_init_stack_bdle(&ps->chunk_to_sort);
	ft_init_stack_bdle(&ps->sorted_stack);
	get_chunk_to_sort_from_head(&ps->chunk_to_sort, 0, ps->stack_a);
	ps->sorted_stack = ft_r_sort(ps->chunk_to_sort);
	ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
	while (i < 2)
	{
		if (ps->stack_a.head->data < ps->middle->value)
		{
			ft_top_x_to_top_y(&ps->stack_a, &ps->stack_b, \
			"pb\n");
			i++;
		}
		else
			ft_mvt_top_to_bottom(&ps->stack_a, "ra\n");
	}
	ft_sort_three(ps);
	handle_stack_b_two_nbrs_case(ps);
	can_finished_process(ps);
	return ;
}

void	ft_sort_four(t_push_swap *ps)
{
	int	i;

	i = 0;
	ft_init_stack_bdle(&ps->chunk_to_sort);
	ft_init_stack_bdle(&ps->sorted_stack);
	get_chunk_to_sort_from_head(&ps->chunk_to_sort, 0, ps->stack_a);
	ps->sorted_stack = ft_r_sort(ps->chunk_to_sort);
	ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
	while (i < 1)
	{
		if (ps->stack_a.head->data < ps->middle->value)
		{
			ft_top_x_to_top_y(&ps->stack_a, &ps->stack_b, \
			"pb\n");
			i++;
		}
		else
			ft_mvt_top_to_bottom(&ps->stack_a, "ra\n");
	}
	ft_sort_three(ps);
	ft_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa\n");
	can_finished_process(ps);
	return ;
}
