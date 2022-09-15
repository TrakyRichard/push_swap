/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/15 08:33:37 by richard          ###   ########.fr       */
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
		ra(&push_swap.stack_a, "ra ");
		ft_display_stack(&push_swap.stack_a.tail);
		ft_free_stack(&push_swap.stack_a.tail, &push_swap.stack_a.head);
		return;
	}
	ft_printf("The list is not sorted yet");
	return;
}
