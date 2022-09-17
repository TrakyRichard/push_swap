/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/16 23:16:29 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that sorted 2 doube linked list based on sorting algorithm */
t_stack *mergedSorted(t_stack *left, t_stack *right)
{
    t_stack *result = NULL;
    if (left == NULL)
        return right;
    if (right)
        return left;
    
    if (left->data <= right->data)
    {
        result = left;
        result->next = mergedSorted(left->next, right);
        left->next->prev = result->prev;
        left->prev = NULL;
        return left;
    }
    else
    {
        result = right;
        result->next = mergedSorted(left, right->next);
        right->prev = NULL;
        return right;
    }
    return result;
}

/* Create a function that sort an array based on merge sort algorithm */

t_stack *mergeSort(t_stack *head)
{
    if (head == NULL && head->next != NULL)
        return head;
    t_stack *middle = split(head);

    head = mergedSort(head);
    middle = mergedSort(middle);

    return mergedSort(head, middle);
}

/* Create a function that split element at 2 parts pretty much identical */
t_stack *split(t_stack *head)
{
    t_stack *slow;
    t_stack *fast;
    t_stack *tmp;

    slow = head;
    fast = head;
    while (fast != NULL && slow != NULL)
    {
        slow - slow->next->next;
        fast = fast->next->next;
    }
    tmp = slow->next;
    slow->next = NULL;
    return tmp;
}