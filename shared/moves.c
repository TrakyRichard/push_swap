/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/15 08:18:44 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

/* function that take the element on top of st_bdl_b and put it on st_bdl_a */
void pa(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, char *inst)
{
    if (st_bdl_b->size == 0)
        return;
    ft_unshift(&st_bdl_a, st_bdl_b->head->data);
    ft_pop(&st_bdl_b);
    ft_putstr_fd("pa ", 1);
}

/* function that take the element on top of st_bdl_a and put it on st_bdl_b */
void    pb(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, char *inst)
{
    if (st_bdl_a->size == 0)
        return;
    ft_unshift(&st_bdl_b, st_bdl_a->head->data);
    ft_pop(&st_bdl_a);
    ft_putstr_fd("pb ", 1);
}

/* function that take the element on top of st_bdl_a and swap it with the previous node of st_bdl_a */
void sa(t_stack_bdle *st_bdl_a, char *inst)
{
    int tmp;

    if (st_bdl_a->size < 2)
        return;
    tmp = st_bdl_a->head->data;
    st_bdl_a->head->data = st_bdl_a->head->next->data;
    st_bdl_a->head->next->data = tmp;
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
    else
        ft_putstr_fd("sa ", 1);
}

/* function that take the element on top of st_bdl_b and swap it with the previous node of st_bdl_b */
void sb(t_stack_bdle *st_bdl_b, char *inst)
{
    int tmp;

    if (st_bdl_b->size < 2)
        return;
    tmp = st_bdl_b->head->data;
    st_bdl_b->head->data = st_bdl_b->head->next->data;
    st_bdl_b->head->next->data = tmp;
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
    else
        ft_putstr_fd("sb ", 1);
}

/* Function that do sa and sb at the same time */
void ss(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b)
{
    sa(st_bdl_a, NULL);
    sb(st_bdl_b, NULL);
    ft_putstr_fd("ss ", 1);
}

/* function that take the element on top of st_bdl_a and put it at the bottom of st_bdl_a */
void ra(t_stack_bdle *st_bdl_a, char *inst)
{
    int tmp;

    if (st_bdl_a->size < 2)
        return;
    tmp = st_bdl_a->head->data;
    ft_pop(&st_bdl_a);
    ft_push(&st_bdl_a, tmp);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
    else
        ft_putstr_fd("ra ", 1);
}

/* function that take the element on top of st_bdl_b and put it at the bottom of st_bdl_b */
void rb(t_stack_bdle *st_bdl_b, char *inst)
{
    int tmp;

    if (st_bdl_b->size < 2)
        return;
    tmp = st_bdl_b->head->data;
    ft_pop(&st_bdl_b);
    ft_push(&st_bdl_b, tmp);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
    else
        ft_putstr_fd("rb ", 1);
}

/* Function that do ra and rb at the same time */
void rr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b)
{
    ra(st_bdl_a, NULL);
    rb(st_bdl_b, NULL);
    ft_putstr_fd("rr ", 1);
}

/* function that take the element at the bottom of st_bdl_a and put it on top of st_bdl_a */
void rra(t_stack_bdle *st_bdl_a, char *inst)
{
    int tmp;

    if (st_bdl_a->size < 2)
        return;
    tmp = st_bdl_a->tail->data;
    ft_shift(&st_bdl_a);
    ft_push(&st_bdl_a, tmp);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
    else
        ft_putstr_fd("rra ", 1);
}

/* function that take the element at the bottom of st_bdl_b and put it on top of st_bdl_b */
void rrb(t_stack_bdle *st_bdl_b, char *inst)
{
    int tmp;

    if (st_bdl_b->size < 2)
        return;
    tmp = st_bdl_b->tail->data;
    ft_shift(&st_bdl_b);
    ft_push(&st_bdl_b, tmp);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
    else
        ft_putstr_fd("rrb ", 1);
}

/* Function that do rra and rrb at the same time */
void rrr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b)
{
    rra(st_bdl_a, NULL);
    rrb(st_bdl_b, NULL);
    ft_putstr_fd("rrr ", 1);
}
