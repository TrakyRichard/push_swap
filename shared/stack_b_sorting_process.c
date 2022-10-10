/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_sorting_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 03:45:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void ft_reverse_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
    int head;

    if (ps->stack_b.size < 2)
        return;
    head = ps->stack_b.head->data;
    while (ps->stack_b.tail->data < ps->middle->value && ps->chunk_to_sort.head->chunk == ps->stack_b.tail->chunk && ps->middle->size >= -1)
    {
        ft_mvt_top_to_bottom(&ps->stack_b, "rb ", &ps->nbre_of_swap);
        ps->num_of_b_rotate++;
        ps->middle->size--;
        if (head == ps->stack_b.tail->data)
        {
            preliminary_of_stack_b(ps, flg_a, flg_b);
            break;
        }
    }
    return;
}

void ft_push_to_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ps->stack_b.size == 0)
        return;
    while (ps->stack_b.tail->data >= ps->middle->value && ps->stack_b.tail->chunk == ps->chunk_to_sort.head->chunk)
    {
        ps->last_chunk_of_b = ps->stack_b.tail->chunk;
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
        if (ps->stack_b.size == 0)
            break;
    }
    return;
}

void ft_stack_b_sorting_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
    can_finished_process(ps);
    while (*flg_b && *flg_a == 0)
    {
        ps->last_chunk_of_b = ps->stack_b.tail->chunk;
        preliminary_of_stack_b(ps, flg_a, flg_b);
        is_chunk_b_already_sorted(ps, flg_a, flg_b);
        while (ps->chunk_to_sort.head->chunk == ps->stack_b.tail->chunk && ps->middle->size > -1 && ps->stack_b.size > 0 && *flg_b)
        {
            ft_push_to_stack_a(ps, flg_a, flg_b);
            ft_reverse_stack_b(ps, flg_a, flg_b);
            if (ps->stack_b.size == 0)
                return;
            if (ps->stack_b.size == 1 || ps->stack_b.size == 2)
            {
                preliminary_of_stack_b(ps, flg_a, flg_b);
                check_flag_status(ps, flg_a, flg_b);
            }
        }
        check_flag_status(ps, flg_a, flg_b);
    }
    return;
}

void is_chunk_b_already_sorted(t_push_swap *ps, int *flg_a, int *flg_b)
{
    while (ft_is_rev_dec_sorted(&ps->chunk_to_sort.tail))
    {
        while (ps->chunk_to_sort.size > 0 && ft_is_rev_sorted(&ps->stack_a.tail))
        {
            can_finished_process(ps);
            ps->stack_b.tail->chunk = 0;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
            ft_pop(&ps->chunk_to_sort);
        }
        preliminary_of_stack_b(ps, flg_a, flg_b);
    }
    return;
}

/* Get reversed elements back to top of stack b */
void get_elements_reversed_of_stack_b_to_top(t_push_swap *ps, int chunk_nbrs)
{
    t_stack_bdle *stack_b;

    stack_b = &ps->stack_b;
    if (is_one_chunk_in_stack(stack_b->head, chunk_nbrs))
        return;
    while (stack_b->head->chunk == chunk_nbrs)
        ft_mvt_bottom_to_top(stack_b, "rrb ", &ps->nbre_of_swap);
    return;
}