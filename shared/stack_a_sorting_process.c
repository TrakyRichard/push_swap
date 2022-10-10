/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sorting_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/09 15:04:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void ft_stack_a_sorting_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
    int chunk_track;

    chunk_track = ps->stack_a.tail->chunk + 1;
    while (*flg_a && *flg_b == 0 && ft_is_rev_sorted(&ps->stack_a.tail) == 0)
    {
        preliminary_of_stack_a(ps, flg_a, flg_b);
        check_flag_status(ps, flg_a, flg_b);
        chunk_track++;
        while (ps->middle->size > 1 && *flg_a)
        {
            ft_push_to_stack_b(ps, flg_a, flg_b, chunk_track);
            ft_reverse_stack_a(ps);
        }
        if (ps->stack_a.head->chunk != 0)
            get_elements_reversed_of_stack_a_to_top(ps, ps->stack_b.head->chunk);
        check_flag_status(ps, flg_a, flg_b);
    }
    return;
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

void ft_reverse_stack_a(t_push_swap *ps)
{
    int head;

    head = ps->stack_a.head->data;
    while (ps->stack_a.tail->data >= ps->middle->value && ft_is_rev_sorted(&ps->stack_a.tail) == 0 && ps->chunk_to_sort.head->chunk == ps->stack_a.tail->chunk)
    {
        ft_mvt_top_to_bottom(&ps->stack_a, "ra ", &ps->nbre_of_swap);
        ps->num_of_a_rotate++;
        if (head == ps->stack_a.tail->data)
            break;
    }
}