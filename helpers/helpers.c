/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/17 08:39:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
/* Refacto finished but change a bit the ft_bind_two_stacks function */
/* Read the number passed into the argv into the pushswap function */
void	ft_parsing_two_args(int argc, char *argv[], t_push_swap *push_swap)
{
	int				i;
	char			**str;
	t_stack_bdle	*stack_a;

	i = 0;
	stack_a = &push_swap->stack_a;
	str = ft_split(argv[1], ' ');
	if (argc != 2)
		ft_error(NULL);
	if (ft_digit(argv[1]) == 1)
		ft_error("Somes arguments are not digits \n");
	while (str[i] != NULL)
	{
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			ft_error(NULL);
		ft_unshift(stack_a, ft_atoi(str[i]), 0);
		i++;
	}
	ft_free_dbl_point(str);
	return ;
}

void	ft_parsing_multiple_args(int argc, char **argv, t_push_swap *push_swap)
{
	int				counter;
	t_stack_bdle	*stack_a;

	stack_a = &push_swap->stack_a;
	counter = 1;
	while (argc > counter)
	{
		if (ft_digit(argv[1]) == 1)
			ft_error("Somes arguments are not digits \n");
		if (ft_atoi(argv[counter]) > 2147483647 || \
				ft_atoi(argv[counter]) < -2147483648)
			ft_error(NULL);
		ft_unshift(stack_a, ft_atoi(argv[counter]), 0);
		counter++;
	}
	return ;
}

/* Appropriate function to check wheiter a string
ascii representation is a digit or no */
int	ft_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+'))
			i++;
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	is_one_chunk_in_stack(t_node *stack, int chunk)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->chunk != chunk)
			return (0);
		stack = stack->next;
	}
	if (stack->chunk != chunk)
		return (0);
	return (1);
}

/* Merge two stacks linked list */
void	ft_bind_two_stacks(t_stack_bdle *stack_one, t_node *stack_two)
{
	t_node			*current;

	current = stack_two;
	if (current == NULL)
		return ;
	while (current != NULL && current->next != NULL)
	{
		ft_unshift(stack_one, current->data, current->chunk);
		current = current->next;
	}
	ft_unshift(stack_one, current->data, current->chunk);
	return ;
}
