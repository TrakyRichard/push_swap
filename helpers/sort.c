/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/16 15:09:52 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void sort_stack(t_push_swap *push_swap)
{
    return;
}

/* Selection sort */
void ft_sort_stack(t_stack **head, t_stack **tail)
{
    t_stack *tmp;
    t_stack *tmp2;
    int     i;
    int     j;
    int     min;

    i = 0;
    j = 0;
    min = 0;
    tmp = *head;
    tmp2 = *head;
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
        tmp2 = *head;
        j++;
    }
}