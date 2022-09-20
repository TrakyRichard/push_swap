/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/18 21:02:18 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that will insert element in a sorting index */
void ft_sorted_insertion(t_stack **head, t_stack *new_node)
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
void ft_insertion_sort(t_stack **head)
{
    t_stack *sorted_ref;
    t_stack *current = *head;
    t_stack *next;

    sorted_ref = NULL;
    while (current != NULL)
    {
        next = current->next;
        ft_sorted_insertion(&sorted_ref, current);
        current = next;
    }
    *head = sorted_ref;
}
