/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:12:10 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/17 07:47:53 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"
#include "./get_next_line/get_next_line.h"

/* Push swap function */

/* Init the stack
 *  Read the argv and stock the list of int into stack_a
 *  Check duplicate
 * Check if the list is sorted
 * 	Call the sort process function
 *  freeze the stack
 */

void	retrieve_line(t_push_swap *ps, char	*line)
{
	while (line)
	{
		step_processing(ps, line);
		free(line);
		line = get_next_line(0);
	}
	return ;
}

void	step_processing(t_push_swap *ps, char *line)
{
	if (ft_strnumcmp(line, "rrb\n", 4) == 0)
		ft_mvt_bottom_to_top(&ps->stack_b, NULL);
	else if (ft_strnumcmp(line, "rra\n", 4) == 0)
		ft_mvt_bottom_to_top(&ps->stack_b, NULL);
	else if (ft_strnumcmp(line, "rrr\n", 4) == 0)
		ft_rrr(&ps->stack_a, &ps->stack_b);
	else if (ft_strnumcmp(line, "sa\n", 4) == 0)
		ft_swap_with_next_node(&ps->stack_a, NULL);
	else if (ft_strnumcmp(line, "sb\n", 4) == 0)
		ft_swap_with_next_node(&ps->stack_b, NULL);
	else if (ft_strnumcmp(line, "ss\n", 4) == 0)
		ft_ss(&ps->stack_a, &ps->stack_b);
	else if (ft_strnumcmp(line, "pa\n", 4) == 0)
		ft_top_x_to_top_y(&ps->stack_a, &ps->stack_b, NULL);
	else if (ft_strnumcmp(line, "pb\n", 4) == 0)
		ft_top_x_to_top_y(&ps->stack_b, &ps->stack_a, NULL);
	else if (ft_strnumcmp(line, "ra\n", 4) == 0)
		ft_mvt_top_to_bottom(&ps->stack_a, NULL);
	else if (ft_strnumcmp(line, "rb\n", 4) == 0)
		ft_mvt_top_to_bottom(&ps->stack_b, NULL);
	else if (ft_strnumcmp(line, "rr\n", 4) == 0)
		ft_rr(&ps->stack_a, &ps->stack_b);
	else
		print_err_mess();
	return ;
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;
	char		*line;

	ft_init_push_swap_stack(&push_swap);
	if (argc == 2)
		ft_parsing_two_args(argc, argv, &push_swap);
	else if (argc > 2)
		ft_parsing_multiple_args(argc, argv, &push_swap);
	else
		ft_error(NULL);
	check_duplicate(&push_swap.stack_a);
	if (ft_is_sorted(&push_swap.stack_a.head))
		print_suc_mess();
	line = get_next_line(0);
	retrieve_line(&push_swap, line);
	can_terminate(&push_swap);
	free_push_swap(&push_swap);
	return (0);
}
