/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/14 23:35:55 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Function that will insert element at the begining of stack */
void	ft_unshift(t_stack_bdle *stack_bdle, int data, int chunk)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		ft_error(NULL);
	new_node->data = data;
	new_node->chunk = chunk;
	new_node->next = stack_bdle->tail;
	new_node->prev = NULL;
	if (stack_bdle->head == NULL)
	{
		stack_bdle->head = new_node;
		stack_bdle->tail = new_node;
	}
	else
	{
		stack_bdle->tail->prev = new_node;
		stack_bdle->tail = new_node;
	}
	stack_bdle->size++;
	return ;
}

/* Add a new node into existing double link list */
void	ft_push(t_stack_bdle *stack, int data, int chunk)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		ft_error(NULL);
	new_node->data = data;
	new_node->chunk = chunk;
	if (stack->head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = stack->head;
		stack->head->next = new_node;
		stack->head = new_node;
	}
	stack->size++;
	return ;
}

/* pop last element of a stack into doubly linked list */
int	ft_pop(t_stack_bdle *stack)
{
	int		data;
	t_node	*tmp;

	if (stack->head == NULL)
		ft_error(NULL);
	data = stack->head->data;
	tmp = stack->head;
	if (stack->head->prev != NULL)
		stack->head = stack->head->prev;
	if (stack->head == NULL)
		stack->tail = NULL;
	else if (stack->head->next != NULL)
			stack->head->next = NULL;
	stack->size--;
	if (stack->size == 1)
		stack->tail = stack->head;
	if (stack->size == 0)
	{
		stack->tail = NULL;
		stack->head = NULL;
	}
	free(tmp);
	return (data);
}

/* shift removes the first item into the stack  */
int	ft_shift(t_stack_bdle *stack)
{
	int		data;
	t_node	*tmp;

	if (stack->tail == NULL)
		ft_error(NULL);
	data = stack->tail->data;
	tmp = stack->tail;
	stack->tail = stack->tail->next;
	if (stack->tail != NULL)
		stack->tail->prev = NULL;
	stack->size--;
	free(tmp);
	return (data);
}
