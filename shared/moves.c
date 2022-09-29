/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/28 20:03:30 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

/* function that take the element on top of st_bdl_b and put it on st_bdl_a */
void ft_take_top_x_to_top_y(t_stack_bdle *st_bdl_x, t_stack_bdle *st_bdl_y, char *inst)
{
    int data;
    int chunk;

    chunk = st_bdl_x->tail->chunk;
    data = st_bdl_x->tail->data;
    if (st_bdl_x->size == 0)
        return;
    ft_push(st_bdl_y, data, chunk);
    ft_pop(st_bdl_x);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
}

/* function that take the element on top of st_bdl_a and swap it with the next_node node of st_bdl_a */
void ft_swap_with_next_node(t_stack_bdle *st_bdl, char *inst)
{
    int tmp1;
    int chunk1;
    int tmp2;
    int chunk2;

    t_stack *new_node;
    if (st_bdl->size < 2)
        return;
    tmp1 = st_bdl->tail->data;
    chunk2 = st_bdl->tail->chunk;
    ft_pop(st_bdl);
    tmp2 = st_bdl->tail->data;
    chunk2 = st_bdl->tail->chunk;
    ft_pop(st_bdl);
    ft_push(st_bdl, tmp1, chunk1);
    ft_push(st_bdl, tmp2, chunk2);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
}

/* Insert after function */
void ft_insert_before_tail(t_stack_bdle *st_bdl, int data, int chunk)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
        ft_error("Error: malloc failed in ft_insert_after");
    new_node->data = data;
    new_node->chunk = chunk;
    if (st_bdl->tail->prev != NULL)
        new_node->prev = st_bdl->tail->prev->next;
    else
        new_node->prev = NULL;
    new_node->next = st_bdl->tail;
    if (st_bdl->tail->prev != NULL)
        st_bdl->tail->prev->next = new_node;
    st_bdl->tail->prev = new_node;
    st_bdl->size++;
}

/* Function that swap two stack at the same time */
void ft_ss(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b)
{
    ft_swap_with_next_node(st_bdl_a, NULL);
    ft_swap_with_next_node(st_bdl_b, NULL);
    ft_putstr_fd("ss ", 1);
}

/* function that take the element on top of the stack and put it at the bottom of stack */
void ft_mvt_top_to_bottom(t_stack_bdle *st_bdl, char *inst)
{
    int tmp;
    int chunk;

    if (st_bdl->size < 2)
        return;
    tmp = st_bdl->tail->data;
    chunk = st_bdl->tail->chunk;
    ft_pop(st_bdl);
    ft_unshift(st_bdl, tmp, chunk);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
}

/* Function that reverse two swap at the same time */
void ft_rr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b)
{
    ft_mvt_top_to_bottom(st_bdl_a, NULL);
    ft_mvt_top_to_bottom(st_bdl_b, NULL);
    ft_putstr_fd("rr ", 1);
}

/* function that take the element at the bottom of the swap and put at the bottom */
void ft_mvt_bottom_to_top(t_stack_bdle *st_bdl_a, char *inst)
{
    int tmp;
    int chunk;
    if (st_bdl_a->size < 2)
        return;
    tmp = st_bdl_a->head->data;
    chunk = st_bdl_a->head->chunk;
    ft_shift(st_bdl_a);
    ft_push(st_bdl_a, tmp, chunk);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
}

/* Function that make two rotation at the same time */
void ft_rrr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b)
{
    ft_mvt_bottom_to_top(st_bdl_a, NULL);
    ft_mvt_bottom_to_top(st_bdl_b, NULL);
    ft_putstr_fd("rrr ", 1);
}
