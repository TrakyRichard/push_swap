/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 04:43:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
/* Function that just write error followed by a new line */
void ft_error(char *str)
{
    if (str == NULL)
        ft_putstr_fd("Error \n", 1);
    else
        ft_putstr_fd(str, 1);
    exit(1);
}

void can_finished_process(t_push_swap *ps)
{
    if (ps->stack_b.size == 0 && ft_is_rev_sorted(&ps->stack_a.head))
        exit(0);
    return;
}

void check_duplicate(t_stack_bdle *stack)
{
    t_node *tmp;
    t_node *tmp2;

    tmp = stack->tail;
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->data == tmp2->data)
                ft_error("There is a duplicate into the stack \n");
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    return;
}
