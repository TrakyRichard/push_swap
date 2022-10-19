/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   richard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/19 04:13:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_r_sort(t_r_sort *r_sort)
{
	r_sort->i = RUN;
	ft_init_stack_bdle(&r_sort->new_chunk);
	ft_init_stack_bdle(&r_sort->sorted_stack);
	ft_init_stack_bdle(&r_sort->result);
	return ;
}

void	set_new_value_of_counter(t_stack_bdle *stack, int *i)
{
	if (stack->size == 0)
		return ;
	else if (stack->size < RUN)
		*i += stack->size;
	else
		*i += RUN;
	return ;
}

/* Create an algorithm inspired by tim sort algorithm */
t_stack_bdle	ft_r_sort(t_stack_bdle stack)
{
	t_r_sort	r_sort;

	init_r_sort(&r_sort);
	stack = ft_duplicate_stack(&stack);
	if (stack.size <= 1 || stack.size == 0)
		return (stack);
	if (stack.size <= r_sort.i)
	{
		ft_init_stack_bdle(&r_sort.new_chunk);
		ft_split_to_get_chunk(&stack, &r_sort.new_chunk, RUN);
		ft_insertion_sort(&r_sort.new_chunk.head);
		return (r_sort.new_chunk);
	}
	while (stack.size > 0)
	{
		ft_init_stack_bdle(&r_sort.new_chunk);
		ft_split_to_get_chunk(&stack, &r_sort.new_chunk, RUN);
		ft_insertion_sort(&r_sort.new_chunk.head);
		ft_bind_two_stacks(&r_sort.sorted_stack, r_sort.new_chunk.head);
		set_new_value_of_counter(&stack, &r_sort.i);
	}
	if (r_sort.i <= RUN)
		return (r_sort.sorted_stack);
	r_sort.result = ft_iterative_merge_sort(&r_sort.sorted_stack);
	return (r_sort.result);
}
