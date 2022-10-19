/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:11:49 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 07:11:49 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

/* Initialise the stack */
void	ft_init_push_swap_stack(t_push_swap *push_swap)
{
	push_swap->middle = 0;
	push_swap->middle = malloc(sizeof(t_middle));
	if (push_swap->middle == NULL)
		ft_error(NULL);
	push_swap->middle->value = 0;
	push_swap->middle->size = 0;
	ft_init_stack_bdle(&push_swap->stack_a);
	ft_init_stack_bdle(&push_swap->stack_b);
	ft_init_stack_bdle(&push_swap->sorted_stack);
	ft_init_stack_bdle(&push_swap->chunk_to_sort);
	return ;
}

/* initialize stack bundle */
void	ft_init_stack_bdle(t_stack_bdle *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return ;
}

/* Function that duplicate a stack bundle */
t_stack_bdle	ft_duplicate_stack(t_stack_bdle *stack)
{
	t_stack_bdle	new_stack;
	t_node			*current;

	new_stack.head = NULL;
	new_stack.tail = NULL;
	new_stack.size = 0;
	current = stack->tail;
	if (current == NULL)
		return (new_stack);
	while (current != NULL && current->prev != NULL)
	{
		ft_push(&new_stack, current->data, current->chunk);
		current = current->prev;
	}
	ft_push(&new_stack, current->data, current->chunk);
	return (new_stack);
}

/* Display the informations into stack a */
void	ft_rev_stack(t_node *tail)
{
	t_node	*tmp;

	tmp = tail;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->data, 1);
		tmp = tmp->prev;
	}
	return ;
}
