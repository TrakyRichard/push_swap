/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/16 15:09:52 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Function that will insert element at the begining of stack */
void ft_unshift(t_stack_bdle **stack_bdle, int data)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
        ft_error("Error: malloc failed in ft_unshift");
    new_node->data = data;
    new_node->next = (*stack_bdle)->head;
    new_node->prev = NULL;
    if ((*stack_bdle)->tail == NULL)
    {
        (*stack_bdle)->tail = new_node;
        (*stack_bdle)->head = new_node;
    }
    else
    {
        (*stack_bdle)->head->prev = new_node;
        (*stack_bdle)->head = new_node;
    }
    (*stack_bdle)->size++;
}

/* Initialise the stack */
void init_stack(t_push_swap *push_swap)
{
    push_swap->stack_a.tail = NULL;
    push_swap->stack_a.head = NULL;
    push_swap->stack_a.size = 0;
    push_swap->stack_b.tail = NULL;
    push_swap->stack_b.head = NULL;
    push_swap->stack_b.size = 0;
    push_swap->instructions = NULL;
    push_swap->nbre_of_swap = 0;
}

/* Add a new node into existing double link list */
void ft_push(t_stack_bdle **stack, int data)
{
    t_stack *new_node;
    t_stack *tmp;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
        ft_error("new_node of push operation allocation failed \n");
    new_node->data = data;
    if ((*stack)->tail == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        (*stack)->tail = new_node;
        (*stack)->head = new_node;
    }
    else
    {
        new_node->next = NULL;
        new_node->prev = (*stack)->tail;
        (*stack)->tail->next = new_node;
        (*stack)->tail = new_node;
    }
    (*stack)->size++;
}

/* pop last element of a stack into doubly linked list */
int ft_pop(t_stack_bdle **stack)
{
    int data;
    t_stack *tmp;

    if ((*stack)->tail == NULL)
        ft_error("stack is empty \n");
    data = (*stack)->tail->data;
    tmp = (*stack)->tail;
    (*stack)->tail = (*stack)->tail->prev;
    if ((*stack)->tail != NULL)
        (*stack)->tail->next = NULL;
    (*stack)->size--;
    free(tmp);
    return (data);
}

/* shift removes the first item into the stack  */
int ft_shift(t_stack_bdle **stack)
{
    int data;
    t_stack *tmp;

    if ((*stack)->head == NULL)
        ft_error("stack->head is empty \n");
    data = (*stack)->head->data;
    tmp = (*stack)->head;
    (*stack)->head = (*stack)->head->next;
    if ((*stack)->head != NULL)
        (*stack)->head->prev = NULL;
    (*stack)->size--;
    free(tmp);
    return (data);
}

/* Display the informations into stack a */
void ft_display_stack(t_stack **head)
{
    t_stack *tmp;

    tmp = *head;
    while (tmp != NULL)
    {
        ft_putnbr_fd(tmp->data, 1);
        tmp = tmp->next;
    }
}

/* Display the informations into stack a */
void ft_rev_stack(t_stack **tail)
{
    t_stack *tmp;

    tmp = *tail;
    while (tmp != NULL)
    {
        ft_putnbr_fd(tmp->data, 1);
        tmp = tmp->prev;
    }
}


