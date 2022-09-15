/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/15 13:37:29 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
/* Push swap function */

/* Init the stack
 *  Read the argv and stock the list of int into stack_a
 *  Check if the list is sorted
 */

void push_swap(int argc, char **argv)
{
	t_push_swap push_swap;
	init_stack(&push_swap);
	read_argv(argc, argv, &push_swap);
	if (ft_is_sorted(&push_swap.stack_a.tail) == 0)
	{
		// 	mvt_top_to_bottom(&push_swap.stack_a, "ra ");
		// 	mvt_bottom_to_top(&push_swap.stack_a, "rra");
		// 	mvt_top_to_bottom(&push_swap.stack_b, "rb ");
		// 	take_top_x_to_top_y(&push_swap.stack_a, &push_swap.stack_b, "pa");
		// 	ft_display_stack(&push_swap.stack_b.tail);
		// ft_printf("\n");
		// 	take_top_x_to_top_y(&push_swap.stack_b, &push_swap.stack_a, "pb");
		// take_top_x_to_top_y(&push_swap.stack_a, &push_swap.stack_b, "pa");
		// ft_free_stack(&push_swap.stack_a.tail, &push_swap.stack_a.head);
		swap_with_next_node(&push_swap.stack_a, "sa ");
		ft_display_stack(&push_swap.stack_a.tail);

		return;
	}
	ft_printf("The list is not sorted yet");
	return;
}
