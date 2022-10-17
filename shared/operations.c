/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:14:27 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/17 05:00:54 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
/* Refacto finished */
void	ft_sort_process(t_push_swap *ps)
{
	if (ps->stack_a.size == 3)
		ft_sort_three(ps);
	else if (ps->stack_a.size == 4)
		ft_sort_four(ps);
	else if (ps->stack_a.size == 5)
		ft_sort_five(ps);
	else
		while (ft_can_continue(ps))
			ft_sorting_process(ps);
	return ;
}

void	ft_sorting_process(t_push_swap *ps)
{
	int	flg_a;
	int	flg_b;

	flg_a = 1;
	flg_b = 0;
	ft_stack_a_sorting_process(ps, &flg_a, &flg_b);
	ft_stack_b_sorting_process(ps, &flg_a, &flg_b);
	return ;
}

void	check_flag_status(t_push_swap *ps, int *flg_a, int *flg_b)
{
	can_finished_process(ps);
	if (ps->stack_b.size == 0 && ft_is_sorted(&ps->stack_a.head))
	{
		*flg_a = 1;
		*flg_b = 1;
	}
	if (ps->middle->size >= 0 || ps->stack_a.size > 2)
	{
		*flg_a = 1;
		*flg_b = 0;
	}
	if (ps->stack_b.size > 0 && ft_is_sorted(&ps->stack_a.head))
	{
		set_chunk_nbrs(&ps->stack_a, 0);
		*flg_a = 0;
		*flg_b = 1;
	}
	return ;
}

int	ft_can_continue(t_push_swap *ps)
{
	if (ft_is_sorted(&ps->stack_a.head) && ps->stack_b.size == 0)
		exit(EXIT_SUCCESS);
	return (1);
}
