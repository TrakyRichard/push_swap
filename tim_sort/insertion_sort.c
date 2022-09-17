/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/16 16:25:05 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that will insert element in a sorting index */
void sorted_insertion(t_stack **head, t_stack *new_node)
{
    t_stack *current;

    if (*head == NULL || (*head)->data >= new_node->data)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        current = *head;
        while (current->next != NULL && current->next->data < new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

/* Create an insertion sort function  */
void insertion_sort(t_stack **head)
{
    t_stack *sorted = NULL;
    t_stack *current = *head;
    t_stack *next;

    while (current != NULL)
    {
        next = current->next;
        sorted_insertion(&sorted, current);
        current = next;
    }
    *head = sorted;
}