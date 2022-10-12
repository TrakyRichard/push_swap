/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/12 03:39:04 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that will insert element in a sorting index */
void	ft_sorted_insertion(t_node **head, t_node *new_node)
{
	t_node	*current;

	if (*head == NULL || (*head)->data >= new_node->data)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL && current->next->data < new_node->data)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
	return ;
}

/* Create an insertion sort function  */
void	ft_insertion_sort(t_node **head)
{
	t_node	*sorted_ref;
	t_node	*current;
	t_node	*next;

	sorted_ref = NULL;
	current = *head;
	while (current != NULL)
	{
		next = current->next;
		ft_sorted_insertion(&sorted_ref, current);
		current = next;
	}
	*head = sorted_ref;
	return ;
}
