/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 04:43:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that will insert element in a sorting index */
void ft_sorted_insertion(t_node **tail, t_node *new_node)
{
    t_node *current;

    if (*tail == NULL || (*tail)->data >= new_node->data)
    {
        new_node->next = *tail;
        *tail = new_node;
    }
    else
    {
        current = *tail;
        while (current->next != NULL && current->next->data < new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

/* Create an insertion sort function  */
void ft_insertion_sort(t_node **tail)
{
    t_node *sorted_ref;
    t_node *current = *tail;
    t_node *next;

    sorted_ref = NULL;
    while (current != NULL)
    {
        next = current->next;
        ft_sorted_insertion(&sorted_ref, current);
        current = next;
    }
    *tail = sorted_ref;
}
