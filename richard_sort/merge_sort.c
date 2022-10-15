/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/15 06:26:07 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that merge 2 sorted double linked
list based on sorting algorithm */

t_stack_bdle	ft_merge_process(t_stack_bdle *left, t_stack_bdle *right)
{
	t_stack_bdle	result;

	ft_init_stack_bdle(&result);
	while (left->tail != NULL && right->tail != NULL)
	{
		if (left->tail->data <= right->tail->data)
		{
			shifted_to_left(left, &result);
			if (left->tail->next == NULL)
			{
				ft_insert_all_node(&result, right);
				return (result);
			}
		}
		else
		{
			shifted_to_right(right, &result);
			if (right->tail->next == NULL)
			{
				ft_insert_all_node(&result, left);
				return (result);
			}
		}
	}
	return (result);
}

t_stack_bdle	ft_merge(t_stack_bdle *left, t_stack_bdle *right)
{
	t_stack_bdle	result;

	ft_init_stack_bdle(&result);
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
	return (ft_merge_process(left, right));
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
			ft_bind_two_stacks(&m_sort.sorted_stack, m_sort.result.tail);
		}
		*stack = ft_duplicate_stack(&m_sort.sorted_stack);
		ft_init_stack_bdle(&m_sort.sorted_stack);
		p *= 2;
	}
	return (m_sort.result);
}
