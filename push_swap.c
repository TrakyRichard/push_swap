/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/19 15:16:19 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

/* Push swap function */

/* Init the stack
 *  Read the argv and stock the list of int into stack_a
 *  Check duplicate
 * Check if the list is sorted
 * 	Call the sort process function
 *  freeze the stack
 */

void	push_swap(int argc, char **argv)
{
	t_push_swap	push_swap;

	ft_init_push_swap_stack(&push_swap);
	if (argc == 2)
		ft_parsing_two_args(argc, argv, &push_swap);
	else if (argc > 2)
		ft_parsing_multiple_args(argc, argv, &push_swap);
	check_duplicate(&push_swap.stack_a);
	if (ft_is_sorted(&push_swap.stack_a.head))
		return ;
	// system("leaks push_swap");
	ft_sort_process(&push_swap);
	free_push_swap(&push_swap);
	return ;
}
