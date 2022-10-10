/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:13:59 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 07:13:59 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

/* check if the stack is already sorted in decroissant order and return 0 */
int	ft_is_rev_dec_sorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->prev != NULL)
	{
		if (tmp->data < tmp->prev->data)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

/* check if the stack is already sorted and return it */
int	ft_is_rev_sorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->prev != NULL)
	{
		if (tmp->data > tmp->prev->data)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

/* check if the stack is already sorted and return it */
int	ft_is_sorted(t_node **tail)
{
	t_node	*tmp;

	tmp = *tail;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_the_grtst_from_head(t_node **stack, int number)
{
	t_node	*tmp;

	tmp = (*stack);
	if (tmp == NULL)
		return (1);
	while (tmp->prev != NULL && tmp != NULL && tmp->data != number)
	{
		if (tmp->data > number)
			return (0);
		tmp = tmp->prev;
	}
	if (tmp != NULL && tmp->data > number)
		return (0);
	return (1);
}
