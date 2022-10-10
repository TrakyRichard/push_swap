/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 04:43:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

/* Push swap function */

/* Init the stack
 *  Read the argv and stock the list of int into stack_a
 *  Check if the list is sorted
 */

void push_swap(int argc, char **argv)
{
	t_push_swap push_swap;
	ft_init_push_swap_stack(&push_swap);
	ft_read_argv(argc, argv, &push_swap);
	check_duplicate(&push_swap.stack_a);
	if (ft_is_rev_sorted(&push_swap.stack_a.head))
		return;
	ft_sort_process(&push_swap);
	return;
}
