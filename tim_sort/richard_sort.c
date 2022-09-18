/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   richard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/18 03:45:16 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void init_sort_var(int *counter, t_stack **head_ref, t_stack **head, t_stack \
					**sorted_stack, t_stack **new_chunk)
{
	*head_ref = *head;
	*counter = 0;
	*sorted_stack == NULL;
	*new_chunk == NULL;
}

/* Create an algorithm inspired by tim sort algorithm */
t_stack *richard_sort(t_stack **head, int stack_size)
{
	int i;
	t_stack *head_ref;
	t_stack *new_chunk;
	t_stack *sorted_stack;

	init_sort_var(i, &head_ref, head, &sorted_stack, &new_chunk);
	while (i <= stack_size)
	{
		split_to_get_chunk(&new_chunk, &head_ref);
		insertion_sort(&new_chunk);
		ft_merge_two_stacks(&sorted_stack, &new_chunk);
		i += RUN;
	}
	init_sort_var(i, &head_ref, head, &sorted_stack, &new_chunk);
	i = RUN;
	if (stack_size <= RUN)
		return sorted_stack;
	while (i < RUN)
	{
		split_to_get_chunk(&new_chunk, &head_ref);
		ft_merge(new_chunk, head_ref);
		i += (RUN*2);
	}

}
