/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/23 06:33:18 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>

typedef struct s_stack
{
	int		val;
	s_stack	next;
	s_stack prev;
} t_stack;

typedef	struct s_push_swap
{
	s_stack	*stack_a;
	s_stack	*stack_b;
	int		nbre_of_swap;
} t_push_swap;

#endif
