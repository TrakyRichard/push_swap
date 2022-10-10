/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/09 14:05:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Function that will insert element at the begining of stack */
void ft_unshift(t_stack_bdle *stack_bdle, int data, int chunk)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
        ft_error("Error: malloc failed in ft_unshift");
    new_node->data = data;
    new_node->chunk = chunk;
    new_node->next = stack_bdle->head;
    new_node->prev = NULL;
    if (stack_bdle->tail == NULL)
    {
        stack_bdle->tail = new_node;
        stack_bdle->head = new_node;
    }
    else
    {
        stack_bdle->head->prev = new_node;
        stack_bdle->head = new_node;
    }
    stack_bdle->size++;
    return;
}

/* Add a new node into existing double link list */
void ft_push(t_stack_bdle *stack, int data, int chunk)
{
    t_stack *new_node;
    t_stack *tmp;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
        ft_error("new_node of push operation allocation failed \n");
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
    return;
}

/* pop last element of a stack into doubly linked list */
int ft_pop(t_stack_bdle *stack)
{
    int data;
    t_stack *tmp;

    if (stack->tail == NULL)
        ft_error("stack is empty \n");
    data = stack->tail->data;
    tmp = stack->tail;
    if (stack->tail->prev != NULL)
        stack->tail = stack->tail->prev;
    if (stack->tail == NULL)
        stack->head = NULL;
    else
    {
        if (stack->tail->next != NULL)
            stack->tail->next = NULL;
    }
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

/* shift removes the first item into the stack  */
int ft_shift(t_stack_bdle *stack)
{
    int data;
    t_stack *tmp;

    if (stack->head == NULL)
        ft_error("stack->head is empty \n");
    data = stack->head->data;
    tmp = stack->head;
    stack->head = stack->head->next;
    if (stack->head != NULL)
        stack->head->prev = NULL;
    stack->size--;
    free(tmp);
    return (data);
}
