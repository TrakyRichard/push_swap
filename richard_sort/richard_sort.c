/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   richard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/21 04:24:32 by rkanmado         ###   ########.fr       */
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

typedef struct s_ft_richard_sort
{
	int i;
	t_stack_bdle *stack_ref;
	t_stack_bdle stack_cpy;
	t_stack_bdle new_chunk;
	t_stack middle;
	t_stack_bdle sorted_stack;
	t_stack_bdle result;
} t_ft_richard_sort;

void ft_init_ft_richard_sort(t_ft_richard_sort *t_sort, t_stack_bdle ***stack)
{
	t_sort->i = RUN;
	t_sort->stack_cpy = ***stack;
	t_sort->stack_ref = &t_sort->stack_cpy;
	ft_init_stack(&t_sort->middle);
	ft_init_stack_bdle(&t_sort->new_chunk);
	ft_init_stack_bdle(&t_sort->sorted_stack);
	ft_init_stack_bdle(&t_sort->result);
	return ;
}

/* Create an algorithm inspired by tim sort algorithm */
t_stack_bdle ft_richard_sort(t_stack_bdle **stack)
{
	t_ft_richard_sort t_sort;

	ft_init_ft_richard_sort(&t_sort, &stack);
	while (t_sort.i <= (*stack)->size)
	{
		ft_init_stack_bdle(&t_sort.new_chunk);
		ft_split_to_get_chunk(&t_sort.stack_ref, &t_sort.new_chunk, RUN);
		ft_insertion_sort(&t_sort.new_chunk.head);
		ft_bind_two_stacks(&t_sort.sorted_stack, t_sort.new_chunk.head);
		if (t_sort.stack_ref->size == 0)
			break;
		if (t_sort.stack_ref->size < RUN)
			t_sort.i += t_sort.stack_ref->size;
		else
			t_sort.i += RUN;
	}
	t_sort.i = RUN;
	if ((*stack)->size <= RUN)
		return t_sort.sorted_stack;
	;
	t_sort.result = ft_iterative_merge_sort(&t_sort.sorted_stack);
	return t_sort.result;
}
