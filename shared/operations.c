/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/21 07:16:12 by rkanmado         ###   ########.fr       */
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
    int data;

    stack_a = &(*push_swap)->stack_a;
    stack_b = &(*push_swap)->stack_b;
    while((*push_swap)->middle.index > 0)
    {
        while (stack_a->size > 1)
        {
            if (stack_a->head->data > (*push_swap)->middle.data)
            {
                data = ft_pop(&stack_a);
                ft_take_top_x_to_top_y(&stack_a, &stack_b, "pa");
            }
        }
        while (stack_a->size == 2)
        {
            if (stack_a->head->data > stack_b->tail->data)
            {
                ft_mvt_top_to_bottom(&stack_a, "ra");
                ft_take_top_x_to_top_y(&stack_a, &stack_b, "pb");
            }
        }
    }
}
