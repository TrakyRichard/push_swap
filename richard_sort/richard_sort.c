/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   richard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/20 21:55:24 by richard          ###   ########.fr       */
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
t_stack_bdle ft_richard_sort(t_stack_bdle **stack)
{
	int i;
	t_stack_bdle *stack_ref;
	t_stack_bdle stack_cpy;
	t_stack_bdle new_chunk;
	t_stack_bdle sorted_stack;
	t_stack_bdle result;

	i = RUN;
	stack_cpy = **stack;
	stack_ref = &stack_cpy;
	ft_init_stack_bdle(&new_chunk);
	ft_init_stack_bdle(&sorted_stack);
	ft_init_stack_bdle(&result);
	while (i <= (*stack)->size)
	{
		ft_init_stack_bdle(&new_chunk);
		ft_split_to_get_chunk(&stack_ref, &new_chunk, RUN);
		ft_insertion_sort(&new_chunk.head);
		ft_bind_two_stacks(&sorted_stack, new_chunk.head);
		if (stack_ref->size == 0)
			break;
		if (stack_ref->size < RUN)
			i += stack_ref->size;
		else
			i += RUN;
	}
	i = RUN;
	if ((*stack)->size <= RUN)
		return sorted_stack;
	;
	result = ft_iterativeMergeSort(&sorted_stack);
	return result;
}
