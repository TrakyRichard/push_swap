/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:58:29 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 06:58:29 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* function to insert all elements for one list to another */
void	ft_insert_all_node(t_stack_bdle *stack, t_stack_bdle *stack_to_insert)
{
	t_node	*current;

	current = stack_to_insert->head;
	if (current == NULL)
		return ;
	while (current != NULL && current->next != NULL)
	{
		ft_unshift(stack, current->data, current->chunk);
		current = current->next;
	}
	ft_unshift(stack, current->data, current->chunk);
	return ;
}

/* Display the informations into stack a */
void	ft_display_stack(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL && tmp->next != NULL)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	if (tmp != NULL)
		ft_printf("%d ", tmp->data);
	return ;
}
