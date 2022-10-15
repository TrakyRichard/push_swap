/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:30:09 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/15 04:32:23 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Function that make two rotation at the same time */
void	ft_rrr(t_stack_bdle *st_bdl_a, \
		t_stack_bdle *st_bdl_b)
{
	ft_mvt_bottom_to_top(st_bdl_a, NULL);
	ft_mvt_bottom_to_top(st_bdl_b, NULL);
	ft_putstr_fd("rrr ", 1);
	return ;
}

/* Function that reverse two swap at the same time */
void	ft_rr(t_stack_bdle *st_bdl_a, \
	t_stack_bdle *st_bdl_b)
{
	ft_mvt_top_to_bottom(st_bdl_a, NULL);
	ft_mvt_top_to_bottom(st_bdl_b, NULL);
	ft_putstr_fd("rr ", 1);
	return ;
}

/* Function that swap two stack at the same time */
void	ft_ss(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b)
{
	ft_swap_with_next_node(st_bdl_a, NULL);
	ft_swap_with_next_node(st_bdl_b, NULL);
	ft_putstr_fd("ss ", 1);
	return ;
}
