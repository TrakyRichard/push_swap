/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/20 22:03:31 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void ft_sort_stack(t_push_swap *push_swap)
{
    t_stack_bdle *stack_a;
    t_stack_bdle *stack_b;
    t_stack_bdle sorted_stack;
    int i;

    stack_a = &push_swap->stack_a;
    stack_b = &push_swap->stack_b;
    i = 0;
    sorted_stack = ft_richard_sort(&stack_a);
}