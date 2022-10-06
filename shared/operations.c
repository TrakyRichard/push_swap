/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/05 03:52:38 by marvin           ###   ########.fr       */
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
    sorted_stack = ft_richard_sort(push_swap->stack_a);
}

int ft_can_continue(t_push_swap *ps)
{
    if (ft_is_rev_sorted(&ps->stack_a.tail) && ps->stack_b.size == 0)
        return (1);
    return (0);
}

void ft_sorting_process(t_push_swap *ps)
{
    int size;
    int flg_a;
    int flg_b;

    flg_a = 1;
    flg_b = 0;
    size = ps->stack_a.size;
    while ((ft_can_continue(ps) == 0))
    {
        if (flg_a == 1 && flg_b == 1)
            break;
        while (flg_b == 0 && flg_a == 1 && ps->stack_a.size > 1)
        {
            ft_init_stack_bdle(&ps->chunk_to_sort);
            ft_init_stack_bdle(&ps->sorted_stack);
            ps->chunk_to_sort = ft_duplicate_stack(&ps->stack_a);
            ps->sorted_stack = ft_richard_sort(ps->chunk_to_sort);
            ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
            handle_stack_a_sort_process(ps, &flg_a, &flg_b);        }
        ft_ping_pong_process(ps, &flg_a, &flg_b);
    }
    printf(" \n ps->stack_a and the number of swap is %d\n", ps->nbre_of_swap);
    ft_display_stack(ps->stack_a.head);
    printf(" \n ps->stack_aand the number of swap is %d\n", ps->nbre_of_swap);
}

/* add all data into the stack with the same chunk number */
void get_chunk_to_sort_from_head(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack)
{
    int data;
    t_stack_bdle tmp;

    tmp = ft_duplicate_stack(&stack);
    ft_init_stack_bdle(chunk_to_sort);
    data = 0;
    while (tmp.size > 0 && tmp.head->chunk == chunk)
    {
        data = ft_pop(&tmp);
        ft_push(chunk_to_sort, data, chunk);
    }
    return;
}

/* Retrieve data into stack b with the same chunk */
void get_chunk_to_sort_from_tail(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack)
{
    int data;
    t_stack_bdle tmp;
    ft_init_stack_bdle(&tmp);
    tmp = ft_duplicate_stack(&stack);
    ft_init_stack_bdle(chunk_to_sort);
    data = 0;
    while (tmp.size > 0 && tmp.tail->chunk == chunk)
    {
        data = ft_pop(&tmp);
        ft_unshift(chunk_to_sort, data, chunk);
    }
    return;
}

/* This ping pong consiste to arrange the data containing in stack a rely on stack b */
void ft_ping_pong_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
   while ((*flg_a != 1 || *flg_b != 1) && ps->stack_b.size > 0)
    {
        // ps->chunk_nbrs = ps->stack_b.tail->chunk;
        // ft_init_stack_bdle(&ps->chunk_to_sort);
        // get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->chunk_nbrs, ps->stack_b);
        // if (ps->chunk_to_sort.size == 2)
        //     handle_stack_b_case_of_two_chunks(ps, flg_a, flg_b);
        // else if (ps->chunk_to_sort.size == 1)
        //     handle_stack_b_case_of_one_chunk(ps, flg_a, flg_b);
        // else
        // {
            // ps->sorted_stack = ft_richard_sort(ps->chunk_to_sort);
            // ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
            while (*flg_a != 1 || *flg_b != 1)
            {
                if (*flg_b == 1 && *flg_a == 0)
                    handle_order_inside_stack_b(ps, flg_a, flg_b);
                if (*flg_a == 1 && *flg_b == 0)
                    handle_order_inside_stack_a(ps, flg_a, flg_b);
            }
        // }
    }
    return;
}



void set_chunk_nbrs(t_stack_bdle *stack, int chunk_nbrs)
{
    t_stack *tmp;

    tmp = stack->head;
    while (tmp != NULL && tmp->next != NULL)
    {
        tmp->chunk = chunk_nbrs;
        tmp = tmp->next;
    }
    tmp->chunk = chunk_nbrs;
    return;
}