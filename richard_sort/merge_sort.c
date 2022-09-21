/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/21 04:09:17 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that merge 2 sorted double linked list based on sorting algorithm */
t_stack_bdle ft_merge(t_stack_bdle *left, t_stack_bdle *right)
{
    t_stack_bdle result;
    t_stack_bdle *result_ref;
    t_stack_bdle *left_ref;
    t_stack_bdle *right_ref;
    int data;
    result_ref = &result;
    left_ref = left;
    right_ref = right;
    ft_init_stack_bdle(&result);
    data = 0;
    if (left_ref->size == 0 && right_ref->size == 0)
        return result;
    if (left_ref->size == 0)
    {
        ft_insert_all_node(&result_ref, &right);
        return result;
    }
    if (right_ref->size == 0)
    {
        ft_insert_all_node(&result_ref, &left);
        return result;
    }
    while (left_ref->head != NULL || right_ref->head != NULL)
    {
        if (left_ref->head->data <= right_ref->head->data)
        {
            data = left_ref->head->data;
            ft_push(&result_ref, data);
            if (left_ref->head->next != NULL)
                left_ref->head = left_ref->head->next;
            else
            {
                ft_insert_all_node(&result_ref, &right);
                return result;
            }
        }
        else
        {
            data = right_ref->head->data;
            ft_push(&result_ref, data);
            if (right_ref->head->next != NULL)
                right_ref->head = right_ref->head->next;
            else
            {
                ft_insert_all_node(&result_ref, &left);
                return result;
            }
        }
    }
    return result;
}

/* Create a function that sort an array based on merge sort algorithm */
t_stack_bdle *ft_merge_sort(t_stack_bdle **stack)
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
    ft_split_to_get_chunk(&stack_ref, &middle, stack_ref->size / 2);
    stack_ref = ft_merge_sort(&stack_ref);
    middle_ref = ft_merge_sort(&middle_ref);
    ft_display_stack(stack_ref->head);
    ft_display_stack(middle_ref->head);
    // sorted_stack->head = ft_merge(&stack_ref->head, &middle_ref->head);
    return sorted_stack;
}

typedef struct s_ft_iterative_merge_sort
{
    t_stack_bdle left;
    t_stack_bdle right;
    t_stack_bdle result;
    t_stack_bdle sorted_stack;
    int p;
    int i;
    int size;
} t_ft_iterative_merge_sort;

/* Create iterative merge sorte */
t_stack_bdle ft_iterative_merge_sort(t_stack_bdle *stack)
{
    t_ft_iterative_merge_sort it_sort;

    it_sort.size = stack->size;
    ft_init_stack_bdle(&it_sort.result);
    ft_init_stack_bdle(&it_sort.sorted_stack);
    it_sort.p = RUN;
    while (it_sort.p <= it_sort.size)
    {
        it_sort.i = 0;
        while (stack->size > 0)
        {
            ft_init_stack_bdle(&it_sort.left);
            ft_init_stack_bdle(&it_sort.right);
            ft_split_to_get_chunk(&stack, &it_sort.left, it_sort.p);
            ft_split_to_get_chunk(&stack, &it_sort.right, it_sort.p);
            it_sort.result = ft_merge(&it_sort.left, &it_sort.right);
            ft_bind_two_stacks(&it_sort.sorted_stack, it_sort.result.head);
        }
        stack = ft_duplicate_stack(&it_sort.sorted_stack);
        ft_init_stack_bdle(&it_sort.sorted_stack);
        it_sort.p *= 2;
    }
    return it_sort.result;
}
