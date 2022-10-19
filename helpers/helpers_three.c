/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:57:58 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 06:57:58 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* add all data into the stack with the same chunk number */
void	get_chunk_to_sort_from_tail(t_stack_bdle *chunk_to_sort, \
			int chunk, t_stack_bdle stack)
{
	int				data;
	t_stack_bdle	tmp;

	tmp = ft_duplicate_stack(&stack);
	ft_init_stack_bdle(chunk_to_sort);
	data = 0;
	while (tmp.size > 0 && tmp.tail->chunk == chunk)
	{
		data = ft_shift(&tmp);
		ft_push(chunk_to_sort, data, chunk);
	}
	return ;
}

/* Retrieve data into stack b with the same chunk */
void	get_chunk_to_sort_from_head(t_stack_bdle *chunk_to_sort, \
			int chunk, t_stack_bdle stack)
{
	int				data;
	t_stack_bdle	tmp;

	ft_init_stack_bdle(&tmp);
	tmp = ft_duplicate_stack(&stack);
	ft_init_stack_bdle(chunk_to_sort);
	data = 0;
	while (tmp.size > 0 && tmp.head->chunk == chunk)
	{
		data = ft_pop(&tmp);
		ft_unshift(chunk_to_sort, data, chunk);
	}
	return ;
}

void	set_chunk_nbrs(t_stack_bdle *stack, int chunk_nbrs)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp != NULL && tmp->next != NULL)
	{
		tmp->chunk = chunk_nbrs;
		tmp = tmp->next;
	}
	tmp->chunk = chunk_nbrs;
	return ;
}

void	shifted_to_left(t_stack_bdle *left, t_stack_bdle *result)
{
	int				chunk;
	int				data;

	data = left->head->data;
	chunk = left->head->chunk;
	ft_unshift(result, data, chunk);
	ft_pop(left);
	return ;
}

void	shifted_to_right(t_stack_bdle *right, t_stack_bdle *result)
{
	int				chunk;
	int				data;

	data = right->head->data;
	chunk = right->head->chunk;
	ft_unshift(result, data, chunk);
	ft_pop(right);
	return ;
}
