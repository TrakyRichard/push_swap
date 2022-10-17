/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/17 06:22:22 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
/* Refacto finished */
/* Free double pointer array */
void	ft_free_dbl_point(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}

/* Function to freeze stack */
void	ft_free_stack(t_node **head, t_node **tail)
{
	t_node	*tmp;

	if (*head == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
	*head = NULL;
	*tail = NULL;
	return ;
}

void	free_push_swap(t_push_swap *ps)
{
	ft_free_stack(&ps->stack_a.head, &ps->stack_a.tail);
	ft_free_stack(&ps->stack_b.head, &ps->stack_b.tail);
	free(ps->middle);
	ft_free_stack(&ps->chunk_to_sort.head, &ps->chunk_to_sort.tail);
	ft_free_stack(&ps->sorted_stack.head, &ps->sorted_stack.tail);
	return ;
}
