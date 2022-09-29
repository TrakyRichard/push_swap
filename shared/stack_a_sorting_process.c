/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sorting_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/29 06:44:32 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Handle the case of 2 numbers into the stack */
void handle_stack_a_case_of_2_nbrs(t_push_swap *ps, int *flag_a, int *flag_b)
{
    if (ps->stack_a.tail->data < ps->middle)
    {
        ps->stack_a.tail->chunk = ps->chunk_nbrs + 1;
        ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pb");
    }
    else
    {
        ps->stack_a.tail->chunk = ps->chunk_nbrs + 1;
        ft_swap_with_next_node(&ps->stack_a, "sa");
        ps->stack_a.tail->chunk = ps->chunk_nbrs + 1;
        ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pb");
    }
    if (ps->stack_a.size == 1)
    {
        *flag_b = 1;
        *flag_a = 0;
    }
}

void handle_stack_a_sort_process(t_push_swap *ps, int *flag_a, int *flag_b)
{
    int data;

    data = 0;
    while (ps->stack_a.tail->chunk == ps->chunk_nbrs)
    {
        if (ps->stack_a.size == 2)
        {
            handle_stack_a_case_of_2_nbrs(ps, flag_a, flag_b);
            break;
        }
        while (ps->stack_a.tail->chunk == ps->chunk_nbrs && ps->stack_a.tail->data < ps->middle && ps->stack_a.size > 0)
        {
            ps->stack_a.tail->chunk = ps->chunk_nbrs + 1;
            ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pb");
        }
        while (ps->stack_a.tail->chunk == ps->chunk_nbrs && ps->stack_a.head->data < ps->middle && ps->stack_a.size > 0)
        {
            ft_mvt_bottom_to_top(&ps->stack_a, "rra");
            ps->stack_a.tail->chunk = ps->chunk_nbrs + 1;
            ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pb");
        }
        while (ps->stack_a.tail->chunk == ps->chunk_nbrs && ps->stack_a.tail->data >= ps->middle && ps->stack_a.size > 0)
        {
            ps->stack_a.tail->chunk = ps->chunk_nbrs + 1;
            ft_mvt_top_to_bottom(&ps->stack_a, "ra");
        }
        // break;
    }
    ps->chunk_nbrs = ps->stack_a.tail->chunk;
}