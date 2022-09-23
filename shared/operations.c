/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/23 21:10:53 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void ft_sort_stack(t_push_swap *push_swap)
{
    t_stack_bdle sorted_stack;
    int i;
    i = 0;
    sorted_stack = ft_richard_sort(&push_swap->stack_a);
    push_swap->middle = ft_midpoint(sorted_stack.head);
	ft_sorting_process(&push_swap);
}

void ft_sorting_process(t_push_swap **push_swap)
{
    t_stack_bdle *stack_a;
    t_stack_bdle *stack_b;
    t_stack_bdle stack_to_sort;
    int data;
    int chunk;
    int middle

    stack_a = &(*push_swap)->stack_a;
    stack_b = &(*push_swap)->stack_b;
    middle = (*push_swap)->middle;
    chunk = 0;

    while (stack_a->head->chunk == chunk && stack_a->size > 1)
    {
        get_chunk_to_sort(&stack_to_sort, chunk, stack_a);
        middle = get_middle_sorted(stack_to_sort);

        while(stack_a->head->next != NULL)
        {
            if (stack_a->size == 2)
            {
                if (stack_a->head->data < stack_a->tail->data)
                {
                    stack_a->head->chunk = chunk;
                    t_take_top_x_to_top_y(stack_a, stack_b, "pb");

                }
                else
                {
                    ft_swap_with_next_node(stack_a, "sa");
                    stack_a->head->chunk = chunk;
                    ft_take_top_x_to_top_y(stack_a, stack_b,"pb");
                }
                break;
            }
            while (stack_a->head->data > middle && stack_a->size > 1)
            {
                data = ft_pop(stack_a);
                ft_push(stack_b, data, chunk);
            }
            while (stack_a->head < middle && stack_a->size > 1)
            {
                while (stack_a->tail->data < middle)
                {
                    ft_mvt_bottom_to_top(stack_a, "rra");
                    ft_take_top_x_to_top_y(&stack_a, &stack_b, "pb");
                }
                while (stack_a->tail->data > middle && stack_a->size > 1)
                {
                    ft_mvt_top_to_bottom(stack_a, "ra");
                }
            }
        }
    }
}
