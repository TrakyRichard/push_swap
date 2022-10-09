/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sorting_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/08 12:39:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Handle the case of 2 numbers into the stack */
void handle_stack_a_case_of_2_nbrs(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ps->stack_a.tail->data > ps->stack_a.head->data)
        ft_swap_with_next_node(&ps->stack_a, "sa ", &ps->nbre_of_swap);
    if (ps->stack_a.size == 2)
    {
        *flg_b = 1;
        *flg_a = 0;
    }
}

void handle_stack_a_sort_step_one(t_push_swap *ps)
{
    while (ps->stack_a.tail->data < ps->middle->value && ps->stack_a.size > 1)
    {
        ps->stack_a.tail->chunk = ps->chunk_nbrs + 1;
        ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pb ", &ps->nbre_of_swap);
        ps->middle->size--;
    }
}

void handle_stack_a_sort_step_two(t_push_swap *ps)
{
    while (ps->stack_a.head->data < ps->middle->value && ps->stack_a.size > 1)
    {
        ft_mvt_bottom_to_top(&ps->stack_a, "rra ", &ps->nbre_of_swap);
        ps->stack_a.tail->chunk = ps->chunk_nbrs + 1;
        ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pb ", &ps->nbre_of_swap);
        ps->middle->size--;
    }
}

void handle_stack_a_sort_step_three(t_push_swap *ps)
{
    int head;

    head = ps->stack_a.head->data;
    while (ps->stack_a.tail->data >= ps->middle->value && ps->stack_a.size > 1)
    {
        ft_mvt_top_to_bottom(&ps->stack_a, "ra ", &ps->nbre_of_swap);
        if (head == ps->stack_a.tail->data || ps->middle->size == 1)
            break;
    }
}

void handle_stack_a_sort_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
    int nothing_to_do;

    nothing_to_do = 0;
    while (ps->stack_a.size > 1)
    {
        if (nothing_to_do && ps->stack_a.size != 2)
            break;
        if (ps->stack_a.size == 2)
            handle_stack_a_case_of_2_nbrs(ps, flg_a, flg_b);
        if (ps->middle->size == 1)
        {
            nothing_to_do = 1;
            ps->chunk_nbrs += 1;
            break;
        }
        handle_stack_a_sort_step_one(ps);
        handle_stack_a_sort_step_two(ps);
        handle_stack_a_sort_step_three(ps);
    }
}
void do_the_preliminary_of_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
    ft_init_stack_bdle(&ps->chunk_to_sort);
    ft_init_stack_bdle(&ps->sorted_stack);
    if (ps->stack_a.tail->chunk != 0)
        get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->stack_a.tail->chunk, ps->stack_a);
    if (ps->chunk_to_sort.size == 0 && ps->stack_a.head->chunk != 0)
        get_elements_reversed_of_stack_a_to_top(ps, ps->stack_a.head->chunk);
    ps->sorted_stack = ft_richard_sort(ps->chunk_to_sort);
    ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
    if (ps->chunk_to_sort.size == 2 || ps->chunk_to_sort.size == 1)
    {
        handle_stack_a_case_of_less_nbrs(ps, flg_a, flg_b);
        get_elements_reversed_of_stack_a_to_top(ps, ps->stack_a.head->chunk);
    }
    return;
}

/* Ordering inside the chunk */
void handle_order_inside_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
    int turn;
    int int_ck_nbrs;
    int int_sort_size;

    turn = 0;
    int_ck_nbrs = ps->chunk_nbrs;
    int_sort_size = 0;
    can_switch_to_stack_b(ps, flg_a, flg_b);
    while (ps->stack_a.tail->chunk == ps->chunk_nbrs && ps->stack_a.size > 0 && *flg_a == 1)
    {
        // /* check if the stack with chunk zero and the stack with chunk on top are arranged */
        // if (is_chunks_sorted(ps, ps->stack_a.tail->chunk, 0))
        // {
        //     if (ps->stack_a.head->chunk != 0)
        //     {
        //         get_elements_reversed_of_stack_a_to_top(&ps->stack_a, ps->stack_a.head->chunk, &ps->nbre_of_swap);
        //         continue;
        //     }
        //     else if (can_switch_to_stack_b(ps, flg_a, flg_b))
        //         break;
        // }
        do_the_preliminary_of_stack_a(ps, flg_a, flg_b);
        while (ps->middle->size > 1)
        {
            reverse_stack_a_process(ps);
            ft_push_chunk_to_stack_b(ps, flg_a, flg_b);
        }
        if (ps->num_of_a_rotate > 0 && ps->middle->size == 1 && ps->can_turn)
        {
            get_elements_reversed_of_stack_a_to_top(ps, ps->stack_a.head->chunk);
            continue;
        }
        can_switch_to_stack_b(ps, flg_a, flg_b);
    }
}

/* Handle the case where the stack_a tail data is greater than middle value */
void ft_push_chunk_to_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
    while (ps->stack_a.tail->chunk == ps->chunk_nbrs && ps->stack_a.tail->data < ps->middle->value)
    {
        if (ps->middle->size > 1)
            ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pa ", &ps->nbre_of_swap);
        else if (ps->middle->size == 1)
            ps->stack_a.tail->chunk = 0;
        else
            break;
        ps->middle->size--;
    }
}

/* Get reversed elements back to top of stack a */
void get_elements_reversed_of_stack_a_to_top(t_push_swap *ps, int chunk_nbrs)
{
    t_stack_bdle *stack_a;

    stack_a = &ps->stack_a;
    while (stack_a->head->chunk == chunk_nbrs)
        ft_mvt_bottom_to_top(stack_a, "rra ", &ps->nbre_of_swap);
    return;
}

void reverse_stack_a_process(t_push_swap *ps)
{
    int turn;
    int int_sort_size;

    turn = 0;
    int_sort_size = 0;
    while (ps->stack_a.tail->data >= ps->middle->value && ps->stack_a.tail->chunk == ps->chunk_nbrs)
    {
        turn = ps->stack_a.head->data;
        int_sort_size = get_top_chunk_size(ps->stack_a);
        if (int_sort_size == 2 || int_sort_size == 1)
            break;
        ft_mvt_top_to_bottom(&ps->stack_a, "ra ", &ps->nbre_of_swap);
        ps->num_of_a_rotate++;
        ps->can_turn = 1;
        if (turn == ps->stack_a.tail->data)
            break;
    }
    return;
}

int can_switch_to_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ps->stack_b.size == 0 && ft_is_sorted(&ps->stack_a.head) == 1)
    {
        *flg_a = 1;
        *flg_b = 1;
        return (1);
    }
    else if (ft_is_rev_sorted(&ps->stack_a.tail) && ps->stack_a.head->chunk == 0)
    {
        set_chunk_nbrs(&ps->stack_a, 0);
        can_dec_ck_nbrs_in_stack_b(ps);
        *flg_b = 1;
        *flg_a = 0;
        return (1);
    }
    // else if (ps->middle->size == 1 && ps->chunk_to_sort.size > 2)
    // {
    //     *flg_b = 1;
    //     *flg_a = 0;
    //     return (1);
    // }
    else
        return (0);
}

/* Handle the case of 2 numbers into the stack */
void handle_stack_a_case_of_less_nbrs(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ps->chunk_to_sort.size == 1 && ft_is_rev_sorted(&ps->stack_a.tail) \
            && is_the_greatest_from_head(&ps->stack_b.tail, ps->stack_a.tail->data))
        ps->stack_a.tail->chunk = 0;
    else if (ps->chunk_to_sort.size == 2 && is_the_greatest_from_head(&ps->stack_b.tail, ps->stack_a.tail->data) \
         && is_the_greatest_from_head(&ps->stack_b.tail, ps->stack_a.tail->prev->data))
    {
        if (ps->stack_a.tail->data > ps->stack_a.tail->prev->data)
        {
            ps->stack_a.tail->chunk = 0;
            ft_swap_with_next_node(&ps->stack_a, "sa ", &ps->nbre_of_swap);
            ps->stack_a.tail->chunk = 0;
        }
        else
        {
            ps->stack_a.tail->chunk = 0;
            ps->stack_a.tail->prev->chunk = 0;
        }
    }
    ps->middle->size = 1;
    if (ft_is_rev_sorted(&ps->stack_a.tail) && ps->stack_b.size == 0)
    {
        *flg_a = 1;
        *flg_b = 1;
    }
    return;
}
