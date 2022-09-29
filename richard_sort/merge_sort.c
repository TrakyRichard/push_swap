/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/27 15:52:02 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that merge 2 sorted double linked list based on sorting algorithm */
t_stack_bdle ft_merge(t_stack_bdle *left, t_stack_bdle *right)
{
    t_stack_bdle result;
    int chunk;
    int data;

    ft_init_stack_bdle(&result);
    data = 0;
    if (left->size == 0 && right->size == 0)
        return result;
    if (left->size == 0)
    {
        ft_insert_all_node(&result, right);
        return result;
    }
    if (right->size == 0)
    {
        ft_insert_all_node(&result, left);
        return result;
    }
    while (left->head != NULL || right->head != NULL)
    {
        if (left->head->data <= right->head->data)
        {
            data = left->head->data;
            chunk = left->head->chunk;
            ft_push(&result, data, chunk);
            if (left->head->next != NULL)
                left->head = left->head->next;
            else
            {
                ft_insert_all_node(&result, right);
                return result;
            }
        }
        else
        {
            data = right->head->data;
            ft_push(&result, data, chunk);
            if (right->head->next != NULL)
                right->head = right->head->next;
            else
            {
                ft_insert_all_node(&result, left);
                break;
            }
        }
    }
    return result;
}

/* Create a function that sort an array based on merge sort algorithm */
t_stack_bdle *ft_mergeSort(t_stack_bdle **stack)
{
    t_stack_bdle *stack_ref;
    t_stack_bdle *sorted_stack;

    stack_ref = *stack;
    if (stack_ref->head == NULL || stack_ref->head->next == NULL)
        return stack_ref;
    t_stack_bdle middle;
    t_stack_bdle *middle_ref = &middle;
    middle_ref->head = NULL;
    middle_ref->tail = NULL;
    middle_ref->size = 0;
    ft_split_to_get_chunk(stack_ref, &middle, stack_ref->size / 2);
    stack_ref = ft_mergeSort(&stack_ref);
    middle_ref = ft_mergeSort(&middle_ref);
    ft_display_stack(stack_ref->head);
    ft_display_stack(middle_ref->head);
    // sorted_stack->head = ft_merge(&stack_ref->head, &middle_ref->head);
    return sorted_stack;
}

/* Create iterative merge sorte */
t_stack_bdle ft_iterativeMergeSort(t_stack_bdle *stack)
{
    t_stack_bdle left;
    t_stack_bdle right;
    t_stack_bdle result;
    t_stack_bdle sorted_stack;
    int p;
    int i;
    int size;

    size = stack->size;
    ft_init_stack_bdle(&result);
    ft_init_stack_bdle(&sorted_stack);
    p = RUN;
    while (p <= size)
    {
        i = 0;
        while (stack->size > 0)
        {
            ft_init_stack_bdle(&left);
            ft_init_stack_bdle(&right);
            ft_split_to_get_chunk(stack, &left, p);
            ft_split_to_get_chunk(stack, &right, p);
            result = ft_merge(&left, &right);
            ft_bind_two_stacks(&sorted_stack, result.head);
        }
        stack = ft_duplicate_stack(&sorted_stack);
        ft_init_stack_bdle(&sorted_stack);
        p *= 2;
    }
    return result;
}
