/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/19 09:23:14 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Function that will insert element at the end of stack */
void	ft_unshift(t_stack_bdle *stack, int data, int chunk)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		ft_error(NULL);
	new_node->data = data;
	new_node->chunk = chunk;
	if (stack->tail == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		stack->tail = new_node;
		stack->head = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = stack->tail;
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
	stack->size++;
	return ;
}

/* Add a new node at the top into existing double link list */
void	ft_push(t_stack_bdle *stack, int data, int chunk)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		ft_error(NULL);
	new_node->data = data;
	new_node->chunk = chunk;
	new_node->next = stack->head;
	new_node->prev = NULL;
	if (stack->tail == NULL)
	{
		stack->tail = new_node;
		stack->head = new_node;
	}
	else
	{
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
	return ;
}

/* pop top element of a stack into doubly linked list */
int	ft_pop(t_stack_bdle *stack)
{
	int		data;
	t_node	*tmp;

	if (stack->head == NULL)
		ft_error(NULL);
	data = stack->head->data;
	tmp = stack->head;
	if (stack->head->next == NULL)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	if (stack->head != NULL)
		stack->head->prev = NULL;
	stack->size--;
	free(tmp);
	return (data);
}

/* shift removes the last item into the stack  */
int	ft_shift(t_stack_bdle *stack)
{
	int		data;
	t_node	*tmp;

	if (stack->tail == NULL)
		ft_error(NULL);
	data = stack->tail->data;
	tmp = stack->tail;
	if (stack->tail->prev != NULL)
		stack->tail = stack->tail->prev;
	if (stack->tail == NULL)
		stack->head = NULL;
	else if (stack->tail->next != NULL)
		stack->tail->next = NULL;
	stack->size--;
	if (stack->size == 1)
		stack->head = stack->tail;
	if (stack->size == 0)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	free(tmp);
	return (data);
}
