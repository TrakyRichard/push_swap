/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/15 08:34:04 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void sort_stack(t_push_swap *push_swap)
{
    return;
}

/* Selection sort */
void ft_sort_stack(t_stack **tail, t_stack **head)
{
    t_stack *tmp;
    t_stack *tmp2;
    int     i;
    int     j;
    int     min;

    i = 0;
    j = 0;
    min = 0;
    tmp = *tail;
    tmp2 = *tail;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        i++;
    }
    while (j < i)
    {
        while (tmp2->next != NULL)
        {
            if (tmp2->next->data < tmp2->data)
            {
                min = tmp2->next->data;
                tmp2->next->data = tmp2->data;
                tmp2->data = min;
            }
            tmp2 = tmp2->next;
        }
        tmp2 = *tail;
        j++;
    }
}