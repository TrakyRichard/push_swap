/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_sorting_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/29 06:58:42 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Handle the case of 2 numbers into the stack */
void handle_stack_b_case_of_less_nbrs(t_push_swap *ps, int *flag_a, int *flag_b)
{
    if (ps->stack_b.size == 1)
    {
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
    }
    if (ps->stack_b.size == 2)
    {
        if (ps->stack_b.tail->data >= ps->middle)
        {
            // ps->stack_b.tail->chunk = ps->chunk_nbrs;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
            // ps->stack_b.tail->chunk = ps->chunk_nbrs;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
        }
        else
        {
            ft_swap_with_next_node(&ps->stack_b, "sb");
            // ps->stack_b.tail->chunk = ps->chunk_nbrs;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
            // ps->stack_b.tail->chunk = ps->chunk_nbrs;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
        }
        ps->chunk_nbrs--;
    }
    return;
}

void handle_stack_b_sort_process(t_push_swap *ps, int *flag_a, int *flag_b)
{
    printf("infinit loop handle_stack_b_sort_process\n");
    while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.size > 0)
    {
        if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
        {
            handle_stack_b_case_of_less_nbrs(ps, flag_a, flag_b);
            // break;
        }
        while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.tail->data >= ps->middle && ps->stack_b.size > 0)
        {
            printf("infinit loop while1\n");
            // ps->stack_b.tail->chunk = ps->chunk_nbrs;
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
        }
        while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.head->data > ps->middle && ps->stack_b.size > 0)
        {
            printf("infinit loop while2 \n");
            ps->stack_b.tail->chunk = ps->chunk_nbrs - 1;
            ft_mvt_bottom_to_top(&ps->stack_b, "rrb");
            ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
        }
        while (ps->stack_b.tail->chunk == ps->chunk_nbrs && ps->stack_b.tail->data < ps->middle && ps->stack_b.size > 0)
        {
            printf("infinit loop while3 and chunk nbr is %d and the middle is %d\n", ps->chunk_nbrs, ps->middle);
            ft_display_stack(ps->stack_b.head);
            printf("\n");
            ft_display_stack(ps->stack_a.head);
            printf("\n");
            if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
            {
                handle_stack_b_case_of_less_nbrs(ps, flag_a, flag_b);
                break;
            }
            ps->stack_b.tail->chunk = ps->chunk_nbrs - 1;
            ft_mvt_top_to_bottom(&ps->stack_b, "rb");
            break;
        }
        // continue;
    }
    if (ps->chunk_nbrs > 0)
        ps->chunk_nbrs--;
    if (ps->stack_b.size == 0)
    {
        *flag_b = 1;
        *flag_a = 1;
    }
    printf("\n stack b process and the chunk tail is %d and the chunk number is %d and the middle is %d \n", ps->stack_b.tail->chunk, ps->chunk_nbrs, ps->middle);
    return;
}

/* Handle case of 2 chunks found */
void handle_stack_b_case_of_two_chunks(t_push_swap *ps, int *flag_a, int *flag_b)
{
    if (ps->stack_b.tail->data > ps->stack_b.tail->prev->data)
    {
        printf("\n stack b case of two chunks the first is %d and the second is %d and chunk is %d \n", ps->stack_b.tail->data, ps->stack_b.tail->prev->data, ps->chunk_nbrs);
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
    }
    else
    {
        printf("\n stack b case of two chunks the first is %d and the second is %d and chunk is %d \n", ps->stack_b.tail->data, ps->stack_b.tail->prev->data, ps->chunk_nbrs);
        ft_swap_with_next_node(&ps->stack_b, "sb");
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
        ft_printf("\n Probleme b \n");
        ft_display_stack(ps->stack_b.head);
        ft_printf("\n Probleme a \n");
        ft_display_stack(ps->stack_a.head);
    }
    if (ps->stack_b.size == 0)
    {
        *flag_b = 1;
        *flag_a = 1;
    }
    ps->chunk_nbrs--;
    return;
}

/* Handle the case of 1 numbers into the stack */
void handle_stack_b_case_of_one_nbr(t_push_swap *ps, int *flag_a, int *flag_b)
{
 
    ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa");
    printf("\n stack b case of one nbr and chunk is %d and b size is %d \n", ps->chunk_nbrs, ps->stack_b.size);
    if (ps->stack_b.size == 0)
    {
        *flag_b = 1;
        *flag_a = 1;
    }
    ps->chunk_nbrs--;
    return;
}