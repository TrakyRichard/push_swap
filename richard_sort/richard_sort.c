/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   richard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/27 15:52:16 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_init_sort_var(int *counter, t_stack **head_ref, t_stack **head, t_stack **sorted_stack, t_stack_bdle **new_chunk)
{
	*head_ref = *head;
	*counter = 0;
	*sorted_stack = NULL;
	*new_chunk = NULL;
}

/* Create an algorithm inspired by tim sort algorithm */
t_stack_bdle ft_richard_sort(t_stack_bdle *stack)
{
	int i;
	t_stack_bdle new_chunk;
	t_stack_bdle sorted_stack;
	t_stack_bdle result;

	i = RUN;
	ft_init_stack_bdle(&new_chunk);
	ft_init_stack_bdle(&sorted_stack);
	ft_init_stack_bdle(&result);
	if (stack->size <= i)
	{
		ft_init_stack_bdle(&new_chunk);
		ft_split_to_get_chunk(stack, &new_chunk, RUN);
		ft_insertion_sort(&new_chunk.head);
		return new_chunk;
	}
	while (i <= stack->size)
	{
		ft_init_stack_bdle(&new_chunk);
		ft_split_to_get_chunk(stack, &new_chunk, RUN);
		ft_insertion_sort(&new_chunk.head);
		ft_bind_two_stacks(&sorted_stack, new_chunk.head);

		if (stack->size == 0)
			break;
		if (stack->size < RUN)
			i += stack->size;
		else
			i += RUN;
	}
	i = RUN;
	if (stack->size <= RUN)
		return sorted_stack;
	result = ft_iterativeMergeSort(&sorted_stack);
	return result;
}
