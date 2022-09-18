/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:44:40 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/18 03:26:23 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that split element at 2 parts pretty much identical */
t_stack *split(t_stack *head)
{
    t_stack *slow;
    t_stack *fast;
    t_stack *tmp;

    slow = head;
    fast = head;
    while (fast != NULL && slow != NULL)
    {
        slow - slow->next->next;
        fast = fast->next->next;
    }
    tmp = slow->next;
    slow->next = NULL;
    return tmp;
}

/* Create N sorted split of our linked list */
t_stack *n_split(t_stack **head, int size)
{
	int i;
	t_stack *current;
	t_stack *chunk_node;

	current = *head;
	chunk_node  NULL;
	while (i < size && current != NULL)
	{
		ft_push(&chunk_node, current->data);
		current = current->next;
		size++;
	}
	return chunk_node;
}

/* Split to get new chunk */
void split_to_get_chunk(t_stack **new_chunk, t_stack **head_ref)
{
	(*new_chunk) = n_split(&head_ref, RUN);
		if((*new_chunk)->next != NULL)
			(*head_ref) = (*new_chunk)->next;
		else
			(*head_ref) = NULL;
		(*new_chunk)->next = NULL;
}
