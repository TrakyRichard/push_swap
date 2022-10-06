/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/05 03:13:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

/* Read the number passed into the argv into the pushswap function */
void ft_read_argv(int argc, char *argv[], t_push_swap *push_swap)
{
    int i;
    char **str;
    char *current_char;
    t_stack_bdle *stack_a;

    i = 0;
    stack_a = &push_swap->stack_a;
    str = ft_split(argv[1], ' ');
    if (argc != 2)
        ft_error("Argument length must be egal to 2 \n");
    if (ft_digit(argv[1]) == 1)
        ft_error("Somes arguments are not digits \n");
    while (str[i] != NULL)
    {
        if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
            ft_error("The number is too big or too small \n");
        ft_push(stack_a, ft_atoi(str[i]), 0);
        i++;
    }
    ft_free_dbl_point(str);
}

/* Appropriate function to check wheiter a string ascii representation is a digit or no */
int ft_digit(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] == '-' || str[i] == '+'))
            i++;
        if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
            return (1);
        i++;
    }
    return (0);
}

/* check if the stack is already sorted and return it */
int ft_is_sorted(t_stack **head)
{
    t_stack *tmp;

    tmp = *head;
    while (tmp->next != NULL)
    {
        if (tmp->data > tmp->next->data)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

/* check if the stack is already sorted and return it */
int ft_is_rev_sorted(t_stack **tail)
{
    t_stack *tmp;

    tmp = *tail;
    while (tmp->prev != NULL)
    {
        if (tmp->data > tmp->prev->data)
            return (0);
        tmp = tmp->prev;
    }
    return (1);
}

/* check if the stack is already sorted in decroissant order and return 0 */
int ft_is_rev_dec_sorted(t_stack **tail)
{
    t_stack *tmp;

    tmp = *tail;
    while (tmp->prev != NULL)
    {
        if (tmp->data < tmp->prev->data)
            return (0);
        tmp = tmp->prev;
    }
    return (1);
}

/* initialize stack bundle */
void ft_init_stack_bdle(t_stack_bdle *stack)
{
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}
