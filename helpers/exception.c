/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/17 07:36:28 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Function that just write error followed by a new line */
void	ft_error(char *str)
{
	ft_putstr_fd("\x1b[1;31m", STDOUT_FILENO);
	if (str == NULL)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
		ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
	return ;
}

void	can_finished_process(t_push_swap *ps)
{
	if (ps->stack_b.size == 0 && ft_is_sorted(&ps->stack_a.head))
	{
		ft_display_stack(ps->stack_a.head);
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	check_duplicate(t_stack_bdle *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack->head;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				ft_error(NULL);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return ;
}
