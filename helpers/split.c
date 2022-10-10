/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:44:40 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 04:43:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that split element at 2 parts pretty much identical */
t_middle *ft_midpoint(t_stack_bdle stack, t_middle *actual_middle)
{
	int mid;
	t_node *current;
	t_middle *middle;

	middle = actual_middle;
	current = stack.tail;
	if (stack.size % 2 == 0)
		mid = stack.size / 2;
	else
		mid = (stack.size / 2) + 1;
	middle->size = mid;
	while (mid != 0 && current != NULL && current->next != NULL)
	{
		middle->value = current->data;
		current = current->next;
		mid--;
	}
	return (middle);
}

/* Get midpoint of a t_stack_bundle */

/* Split the stack to retrieve the first N elements */
void ft_split_n_element(t_stack_bdle *stack, t_stack_bdle *new_chunk, int n)
{
	int i;
	int chunk_nbrs;
	t_stack_bdle *current;
	current = stack;
	i = 0;
	while (i < n && current->size > 0)
	{
		chunk_nbrs = current->tail->chunk;
		int data = ft_shift(current);
		ft_push(new_chunk, data, chunk_nbrs);
		i++;
	}
	return;
}

/* Split to get new chunk */
void ft_split_to_get_chunk(t_stack_bdle *stack_ref_bdle, t_stack_bdle *new_chunk, int n)
{
	if (stack_ref_bdle->size > 0)
		ft_split_n_element(stack_ref_bdle, new_chunk, n);
	return;
}
