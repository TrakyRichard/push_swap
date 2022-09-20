/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:56:56 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/18 11:54:36 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_swap_node(t_stack **stack1, t_stack **stack2)
{
	t_stack *tmp;

	tmp = *stack1;
	*stack1 = *stack2;
	*stack2 = *stack1;
}

void ft_swap_int(int *a1, int *a2)
{
	int tmp;

	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}
