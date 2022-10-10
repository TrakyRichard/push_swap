/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/09 08:39:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* Free double pointer array */
void ft_free_dbl_point(char **str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
}

/* Function to freeze stack */
void ft_free_stack(t_stack **head, t_stack **tail)
{
    t_stack *tmp;

    if (*head == NULL)
        return;

    tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        free(tmp->prev);
    }
    free(tmp);
    *head = NULL;
    *tail = NULL;
}