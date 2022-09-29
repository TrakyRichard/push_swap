/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:44:40 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/27 15:47:06 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that split element at 2 parts pretty much identical */
int ft_midpoint(t_stack_bdle stack)
{
	int mid;
	int data;
	t_stack *current;

	current = stack.head;

	data = 0;
	if (stack.size % 2 == 0)
		mid = stack.size / 2;
	else
		mid = (stack.size / 2) + 1;
	while (mid != 0 && current != NULL && current->next != NULL)
	{
		data = current->data;
		current = current->next;
		mid--;
	}
		return (data);
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
		chunk_nbrs = current->head->chunk;
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
