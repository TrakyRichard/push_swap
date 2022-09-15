/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:56:56 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/15 14:08:44 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_node(t_stack **stack1, t_stack **stack2)
{
	t_stack *tmp;

	tmp = *stack1;
	*stack1 = *stack2;
	*stack2 = *stack1;
}

void swap_int(int *a1, int *a2)
{
	int tmp;

	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}
