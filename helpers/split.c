/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:44:40 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/20 21:12:57 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that split element at 2 parts pretty much identical */
t_stack *ft_split_in_halve(t_stack *head)
{
	t_stack *slow;
	t_stack *fast;
	t_stack *tmp;

	slow = head;
	fast = head;
	while (fast != NULL && slow != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	tmp = slow->next;
	slow->next = NULL;
	return tmp;
}

/* Split the stack to retrieve the first N elements */
void ft_split_n_element(t_stack_bdle **stack, t_stack_bdle **new_chunk, int n)
{
	int i;
	t_stack_bdle *current;
	t_stack_bdle *chunk;
	current = *stack;
	chunk = *new_chunk;
	i = 0;
	while (i < n && current->size > 0)
	{
		int data = ft_shift(&current);
		ft_push(&chunk, data);
		i++;
	}
	return ;
}

/* Split to get new chunk */
void ft_split_to_get_chunk(t_stack_bdle **stack_ref_bdle, t_stack_bdle *new_chunk, int n)
{
	t_stack_bdle *stack;
	stack = *stack_ref_bdle;

	if (stack->size > 0)
		ft_split_n_element(&stack, &new_chunk, n);
	return ;
}
