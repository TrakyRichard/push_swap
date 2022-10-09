/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_sorting_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/08 22:55:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Handle the case of 2 numbers into the stack */
void handle_stack_b_case_of_less_nbrs(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ps->chunk_to_sort.size == 1)
    {
        // if (!is_the_greatest_from_head(&ps->chunk_to_sort, ps->stack_b.tail->data))

        if (ft_is_rev_sorted(&ps->stack_a.tail))
            ps->stack_b.tail->chunk = 0;
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
    }
    else if (ps->chunk_to_sort.size == 2)
    {
        if (ps->stack_b.tail->data >= ps->stack_b.tail->prev->data)
        {
            ps->stack_b.tail->chunk = 0;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
            ps->stack_b.tail->chunk = 0;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
        }
        else
        {
            ft_swap_with_next_node(&ps->stack_b, "sb ", &ps->nbre_of_swap);
            ps->stack_b.tail->chunk = 0;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
            ps->stack_b.tail->chunk = 0;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
        }
    }
    ps->chunk_to_sort.size = 0;
    if (ft_is_rev_sorted(&ps->stack_a.tail) && ps->stack_b.size == 0)
    {
        *flg_a = 1;
        *flg_b = 1;
    }
    return;
}

void handle_stack_b_sort_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
    while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.size > 0)
    {
        if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
            handle_stack_b_case_of_less_nbrs(ps, flg_a, flg_b);
        while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.tail->data >= ps->middle->value && ps->stack_b.size > 0)
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa ", &ps->nbre_of_swap);
        // while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.head->data > ps->middle->value && ps->stack_b.size > 0)
        // {
        //     // ps->stack_b.tail->chunk = ps->chunk_nbrs - 1;
        //     ft_mvt_bottom_to_top(&ps->stack_b, "rrb ", &ps->nbre_of_swap);
        //     ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa ", &ps->nbre_of_swap);
        // }
        int turn;

        turn = 0;
        while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.tail->data < ps->middle->value && ps->stack_b.size > 0)
        {
                if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
            {
                handle_stack_b_case_of_less_nbrs(ps, flg_a, flg_b);
                break;
            }
            turn = ps->stack_b.tail->data;
            ft_mvt_top_to_bottom(&ps->stack_b, "rb ", &ps->nbre_of_swap);
            if (ps->stack_b.tail->data == turn)
                break;
        }
    }
    if (ps->chunk_nbrs > 0)
        ps->chunk_nbrs--;
    if (ps->stack_b.size == 0)
    {
        *flg_b = 1;
        *flg_a = 1;
    }
    return;
}

void do_the_preliminary_of_stack_b(t_push_swap *ps)
{
    get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->chunk_nbrs, ps->stack_b);
        if (ps->chunk_to_sort.size == 0)
        {
            get_elements_reversed_of_stack_b_to_top(ps, ps->chunk_nbrs);
            get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->chunk_nbrs, ps->stack_b);
        }
    if (ps->chunk_to_sort.size == 0)
        ps->chunk_nbrs--;
    if ((ps->stack_b.head->chunk != ps->chunk_nbrs) || ps->chunk_nbrs == 1)
    {
        ft_init_stack_bdle(&ps->sorted_stack);
        ps->sorted_stack = ft_richard_sort(ps->chunk_to_sort);
        ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
    }
    if (ps->chunk_to_sort.size % 2 == 0)
        ps->middle->size = (ps->chunk_to_sort.size / 2) + 1;
    else
        ps->middle->size = (ps->chunk_to_sort.size / 2);
    return ;
}

/* Ordering inside the chunk */
void handle_order_inside_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
    while (ps->stack_b.size > 0 && *flg_b == 1)
    {
        do_the_preliminary_of_stack_b(ps);
        if (can_switch_to_stack_a(ps, flg_a, flg_b))
            break;
        if (ps->chunk_to_sort.size == 2 || ps->chunk_to_sort.size == 1)
        {
            handle_stack_b_case_of_less_nbrs(ps, flg_a, flg_b);
            if (ps->stack_b.size == 0)
                break;
            if (can_dec_ck_nbrs_in_stack_b(ps))
                continue;
        }
        while (ps->middle->size > 0)
        {
            ft_push_chunk_to_stack_a(ps, flg_a, flg_b);
            reverse_stack_b_process(ps, flg_a, flg_b);
        }
        can_switch_to_stack_a(ps, flg_a, flg_b);
        can_dec_ck_nbrs_in_stack_b(ps);
    }
}

void reverse_stack_b_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
    while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.tail->data < ps->middle->value && ps->stack_b.size > 0)
    {
        if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
            break;
        ft_mvt_top_to_bottom(&ps->stack_b, "rb ", &ps->nbre_of_swap);
        ps->num_of_b_rotate++;
        ps->can_turn = 1;
    }
    return ;
}

int can_switch_to_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ps->stack_b.size == 0 && ft_is_rev_sorted(&ps->stack_a.head))
    {
        *flg_a = 1;
        *flg_b = 1;
        return (1);
    }
    else if ((ps->stack_b.tail->chunk != ps->chunk_nbrs) && ft_is_rev_sorted(&ps->stack_a.head))
    {
        *flg_b = 0;
        *flg_a = 1;
        return (1);
    }
    else if (ps->middle->size == 0 && ps->chunk_to_sort.size > 2)
    {
        *flg_b = 0;
        *flg_a = 1;
        return (1);
    }
    else
        return (0);
}

/* Function to check if there is a way to decrement the ps->chunk_nbrs */
int can_dec_ck_nbrs_in_stack_b(t_push_swap *ps)
{
    if (((ps->stack_b.tail->chunk != ps->chunk_nbrs && ps->stack_b.head->chunk != ps->chunk_nbrs) || ps->stack_b.size == 1) \
         && ft_is_rev_sorted(&ps->stack_a.tail) && ps->chunk_nbrs > 1)
    {
        ps->chunk_nbrs--;
       return (1);
    }
    return (0);
}

/* Handle the case where the stack_a tail data is greater than middle value */
void ft_push_chunk_to_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
        while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.tail->data >= ps->middle->value)
        {
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
            ps->middle->size--;
        }
}

/* Order reversed sorted chunk */
void ft_order_rev_sorted_chunk_on_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
    int size;

    size = ps->chunk_to_sort.size;
    while (ps->stack_b.tail->chunk == ps->chunk_nbrs && size > 0)
    {
        ft_mvt_top_to_bottom(&ps->stack_b, "rb ", &ps->nbre_of_swap);
        size--;
    }
    while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.tail->data >= ps->middle->value)
    {
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
        if (ps->stack_b.head->chunk == ps->chunk_nbrs)
            ft_mvt_bottom_to_top(&ps->stack_b, "rrb ", &ps->nbre_of_swap);
        can_switch_to_stack_a(ps, flg_a, flg_b);
    }
}

/* Order reversed dec sorted chunk */
void ft_order_rev_dec_chunk_on_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
    while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.tail->data >= ps->middle->value)
    {
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
        can_switch_to_stack_a(ps, flg_a, flg_b);
    }
}

/* Get reversed elements back to top of stack b */
void get_elements_reversed_of_stack_b_to_top(t_push_swap *ps, int chunk_nbrs)
{
    t_stack_bdle *stack_b;

    stack_b = &ps->stack_b;
    if (is_one_chunk_in_stack(stack_b->head, chunk_nbrs))
        return ;
    while (stack_b->head->chunk == chunk_nbrs)
        ft_mvt_bottom_to_top(stack_b, "rrb ", &ps->nbre_of_swap);
    return;
}

/* Handle case of 2 chunks found */
void handle_stack_b_case_of_two_chunks(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ps->stack_b.tail->data > ps->stack_b.tail->prev->data)
    {
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa ", &ps->nbre_of_swap);
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa ", &ps->nbre_of_swap);
    }
    else
    {
        ft_swap_with_next_node(&ps->stack_b, "sb ", &ps->nbre_of_swap);
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa ", &ps->nbre_of_swap);
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa ", &ps->nbre_of_swap);
    }
    if (ps->stack_b.size == 0)
    {
        *flg_b = 1;
        *flg_a = 1;
    }
    ps->chunk_nbrs--;
    return;
}

/* Handle the case of 1 numbers into the stack */
void handle_stack_b_case_of_one_chunk(t_push_swap *ps, int *flg_a, int *flg_b)
{
    ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa ", &ps->nbre_of_swap);
    if (ps->stack_b.size == 0)
    {
        *flg_b = 1;
        *flg_a = 1;
    }
    ps->chunk_nbrs--;
    return;
}