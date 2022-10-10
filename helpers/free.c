/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 04:43:27 by marvin           ###   ########.fr       */
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
void ft_free_stack(t_node **tail, t_node **head)
{
    t_node *tmp;

    if (*tail == NULL)
        return;

    tmp = *tail;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        free(tmp->prev);
    }
    free(tmp);
    *tail = NULL;
    *head = NULL;
}