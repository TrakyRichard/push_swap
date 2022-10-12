/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/12 03:39:04 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that merge 2 sorted double linked
list based on sorting algorithm */
t_stack_bdle	ft_merge(t_stack_bdle *left, t_stack_bdle *right)
{
	t_stack_bdle	result;
	int				chunk;
	int				data;

	ft_init_stack_bdle(&result);
	data = 0;
	if (left->size == 0 && right->size == 0)
		return (result);
	if (left->size == 0 && right->size > 0)
	{
		ft_insert_all_node(&result, right);
		return (result);
	}
	if (right->size == 0 && left->size > 0)
	{
		ft_insert_all_node(&result, left);
		return (result);
	}
	while (left->head != NULL && right->head != NULL)
	{
		if (left->head->data <= right->head->data)
		{
			data = left->head->data;
			chunk = left->head->chunk;
			ft_push(&result, data, chunk);
			if (left->head->next != NULL)
				left->head = left->head->next;
			else
			{
				ft_insert_all_node(&result, right);
				return (result);
			}
		}
		else
		{
			data = right->head->data;
			chunk = right->head->chunk;
			ft_push(&result, data, chunk);
			if (right->head->next != NULL)
				right->head = right->head->next;
			else
			{
				ft_insert_all_node(&result, left);
				return (result);
			}
		}
	}
	return (result);
}

void	init_it_m_sort_var(t_m_sort *m_sort, t_stack_bdle *st, \
		int *size, int *p)
{
	*size = st->size;
	ft_init_stack_bdle(&m_sort->result);
	ft_init_stack_bdle(&m_sort->sorted_stack);
	*p = RUN;
	return ;
}

/* Create iterative merge sort */
t_stack_bdle	ft_iterative_merge_sort(t_stack_bdle *stack)
{
	t_m_sort		m_sort;
	int				p;
	int				i;
	int				size;

	init_it_m_sort_var(&m_sort, stack, &size, &p);
	while (p <= size)
	{
		i = 0;
		while (stack->size > 0)
		{
			ft_init_stack_bdle(&m_sort.left);
			ft_init_stack_bdle(&m_sort.right);
			ft_split_to_get_chunk(stack, &m_sort.left, p);
			ft_split_to_get_chunk(stack, &m_sort.right, p);
			m_sort.result = ft_merge(&m_sort.left, &m_sort.right);
			ft_bind_two_stacks(&m_sort.sorted_stack, m_sort.result.head);
		}
		*stack = ft_duplicate_stack(&m_sort.sorted_stack);
		ft_init_stack_bdle(&m_sort.sorted_stack);
		p *= 2;
	}
	return (m_sort.result);
}
