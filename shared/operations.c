/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/29 07:06:33 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void ft_sort_stack(t_push_swap *push_swap)
{
    t_stack_bdle *stack_a;
    t_stack_bdle *stack_b;
    t_stack_bdle sorted_stack;
    int i;

    stack_a = &push_swap->stack_a;
    stack_b = &push_swap->stack_b;
    i = 0;
    sorted_stack = ft_richard_sort(stack_a);
}

int ft_can_continue(t_push_swap *ps)
{
    if (ft_is_rev_sorted(&ps->stack_a.tail) == 0 && ps->stack_b.size == 0)
        return (1);
    return (0);
}

void ft_sorting_process(t_push_swap *ps)
{
    int size;
    int flag_a;
    int flag_b;
    int can_start_checking;

    flag_a = 1;
    can_start_checking = 0;
    flag_b = 0;
    size = ps->stack_a.size;
    while ((ft_can_continue(ps) == 0))
    {
        if (flag_a == 1 && flag_b == 1)
            break;
        while (flag_b == 0 && flag_a == 1 && ps->stack_a.size > 0)
        {
            printf("\n C'est fini gaté les ps->stack_b.tail->chunk son\n");
            printf("\n chunk_to_sort \n");
            ft_display_stack(ps->stack_a.head);
            printf("\n chunk_to_sort \n");
            ft_init_stack_bdle(&ps->chunk_to_sort);
            get_chunk_of_a_to_sort(&ps->chunk_to_sort, ps->chunk_nbrs, ps->stack_a);
            ps->sorted_stack = ft_richard_sort(&ps->chunk_to_sort);
            ps->middle = ft_midpoint(ps->sorted_stack);
            handle_stack_a_sort_process(ps, &flag_a, &flag_b);
        }
        // printf(" \n after 1er rond a \n");
        // ft_display_stack(ps->stack_a.head);
        // printf(" \n after 1er rond b \n");
        // ft_display_stack(ps->stack_b.head);
        // printf(" \n after 1er rond b \n");

        while (flag_a == 0 && flag_b == 1 && ps->stack_b.size > 0)
        {
            printf("\nContinue\n");
            ps->chunk_nbrs = ps->stack_b.tail->chunk;
            ft_init_stack_bdle(&ps->chunk_to_sort);
            // ft_printf("\n display sort the chunk is %d and the precedent chunk is %d \n", ps->stack_b.tail->chunk, ps->stack_b.tail->prev->chunk);
            // ft_display_stack(ps->stack_a.head);
            get_chunk_of_b_to_sort(&ps->chunk_to_sort, ps->chunk_nbrs, ps->stack_b);
            printf("\n chunk_to_sort \n");
            ft_display_stack(ps->chunk_to_sort.head);
            printf("\n chunk_to_sort \n");
            printf("\n ps->stack_b.head \n");
            ft_display_stack(ps->stack_b.head);
            printf("\n ps->stack_b.head \n");
            printf("\n");
            if (ps->chunk_to_sort.size == 2)
            {
                printf("\ntwo\n");
                handle_stack_b_case_of_two_chunks(ps, &flag_a, &flag_b);
                printf("\ntwo\n");
                // continue;
            }
            else if (ps->chunk_to_sort.size == 1)
            {
                printf("\none\n");
                handle_stack_b_case_of_one_nbr(ps, &flag_a, &flag_b);
                printf("\none\n");
            }
            else
            {
                printf("\nelse\n");
                ps->sorted_stack = ft_richard_sort(&ps->chunk_to_sort);
                ps->middle = ft_midpoint(ps->sorted_stack);
                handle_stack_b_sort_process(ps, &flag_a, &flag_b);
                printf("\nelse\n");
            }
            // printf("\n C'est gaté n");
            // ft_display_stack(ps->chunk_to_sort.head);
            // printf("\n C'est gaté \n");
            // ps->sorted_stack = ft_richard_sort(&ps->chunk_to_sort);
            // ps->middle = ft_midpoint(ps->sorted_stack);
            // handle_stack_b_sort_process(ps, &flag_a, &flag_b);
            // continue;
        }
    }
    printf(" \n ps->stack_a \n");
    ft_display_stack(ps->stack_a.head);
    printf(" \n ps->stack_a \n");
    // printf(" \n sorted_stack \n");
    // ft_display_stack(ps->stack_b.head);
    // printf(" \n sorted_stack \n");
    // ft_free_stack(&ps->sorted_stack.head, &ps->sorted_stack.tail);
    // ft_free_stack(&ps->chunk_to_sort.head, &ps->chunk_to_sort.tail);
    // ft_free_stack(&ps->stack_b.head, &ps->stack_b.tail);
}

/* add all data into the stack with the same chunk number */
void get_chunk_of_a_to_sort(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack)
{
    int data;
    t_stack_bdle *tmp;

    tmp = ft_duplicate_stack(&stack);
    // ft_display_stack(tmp->head);
    ft_init_stack_bdle(chunk_to_sort);
    data = 0;
    while (tmp->size > 0 && tmp->head->chunk == chunk)
    {
        // ft_printf(" \n ps->chunk_nbrs %d \n", tmp->head->chunk);
        data = ft_pop(tmp);
        ft_push(chunk_to_sort, data, chunk);
    }
    return;
}

/* Retrieve data into stack b with the same chunk */
void get_chunk_of_b_to_sort(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack)
{
    ft_printf(" \n  Started get_chunk_of_b_to_sort chunk is %d and the last value is%d\n", chunk, stack.tail->data);
    int data;
    t_stack_bdle *tmp;
    tmp = ft_duplicate_stack(&stack);
    ft_init_stack_bdle(chunk_to_sort);
    data = 0;
    while (tmp->size > 0 && tmp->tail->chunk == chunk)
    {
        data = ft_pop(tmp);
        ft_unshift(chunk_to_sort, data, chunk);
        ft_printf(" \n ps->chunk_nbrs %d and tmp->size \n", tmp->tail->chunk, tmp->size);
    }
    ft_printf(" \n tmp->head finished \n");
    ft_display_stack(chunk_to_sort->head);
    ft_printf(" \n tmp->head finished \n");
    return;
}