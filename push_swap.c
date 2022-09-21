/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/21 05:36:14 by rkanmado         ###   ########.fr       */
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
	ft_init_t_push_swap(&push_swap);
	ft_read_argv(argc, argv, &push_swap);
	if (ft_is_sorted(&push_swap.stack_a.head) == 0)
	{
		ft_display_stack(push_swap.stack_a.head);
		return;
	}
	ft_sort_stack(&push_swap);
	return;
}
