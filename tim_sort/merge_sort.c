/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:41:36 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/18 03:48:33 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create a function that merge 2 sorted double linked list based on sorting algorithm */
t_stack *ft_merge(t_stack *left, t_stack *right)
{
    t_stack *result = NULL;
    if (left == NULL)
        return right;
    if (right)
        return left;

    if (left->data <= right->data)
    {
        result = left;
        result->next = ft_merge(left->next, right);
        left->next->prev = result->prev;
        left->prev = NULL;
        return left;
    }
    else
    {
        result = right;
        result->next = ft_merge(left, right->next);
        right->prev = NULL;
        return right;
    }
    return result;
}

