/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/25 14:50:02 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

/* function that take the element on top of st_bdl_b and put it on st_bdl_a */
void ft_take_top_x_to_top_y(t_stack_bdle **st_bdl_x, t_stack_bdle **st_bdl_y, char *inst)
{
    t_stack_bdle *st_bdl_x_ref;
    t_stack_bdle *st_bdl_y_ref;

    st_bdl_y_ref = *st_bdl_y;
    st_bdl_x_ref = *st_bdl_x;
    if (st_bdl_x_ref->size == 0)
        return;
    ft_unshift(&st_bdl_y_ref, st_bdl_x_ref->tail->data);
    ft_pop(&st_bdl_x_ref);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
}

/* function that take the element on top of st_bdl_a and swap it with the next_node node of st_bdl_a */
void ft_swap_with_next_node(t_stack_bdle **st_bdl, char *inst)
{
    int tmp;

    t_stack_bdle *st_bdl_ref;
    t_stack *new_node;

    st_bdl_ref = *st_bdl;
    if (st_bdl_ref->size < 2)
        return;
    ft_shift(&st_bdl_ref);
    tmp = st_bdl_ref->head->data;
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
        ft_error("Error: malloc failed in ft_unshift");
    new_node->next = st_bdl_ref->head->next;
    st_bdl_ref->head->next = new_node;
    new_node->prev = st_bdl_ref->head;
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
}

/* Function that swap two stack at the same time */
void ft_ss(t_stack_bdle **st_bdl_a, t_stack_bdle **st_bdl_b)
{
    t_stack_bdle *st_bdl_a_ref;
    t_stack_bdle *st_bdl_b_ref;

    st_bdl_a_ref = *st_bdl_a;
    st_bdl_b_ref = *st_bdl_b;
    ft_swap_with_next_node(&st_bdl_a_ref, NULL);
    ft_swap_with_next_node(&st_bdl_b_ref, NULL);
    ft_putstr_fd("ss ", 1);
}

/* function that take the element on top of the stack and put it at the bottom of stack */
void ft_mvt_top_to_bottom(t_stack_bdle **st_bdl, char *inst)
{
    int tmp;
    t_stack_bdle *st_bdl_ref;

    st_bdl_ref = *st_bdl;
    if (st_bdl_ref->size < 2)
        return;
    tmp = st_bdl_ref->tail->data;
    ft_pop(&st_bdl_ref);
    ft_unshift(&st_bdl_ref, tmp);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
}

/* Function that reverse two swap at the same time */
void ft_rr(t_stack_bdle **st_bdl_a, t_stack_bdle **st_bdl_b)
{
    t_stack_bdle *st_bdl_a_ref;
    t_stack_bdle *st_bdl_b_ref;

    st_bdl_a_ref = *st_bdl_a;
    st_bdl_b_ref = *st_bdl_b;
    ft_mvt_top_to_bottom(&st_bdl_a_ref, NULL);
    ft_mvt_top_to_bottom(&st_bdl_b_ref, NULL);
    ft_putstr_fd("rr ", 1);
}

/* function that take the element at the bottom of the swap and put at the bottom */
void ft_mvt_bottom_to_top(t_stack_bdle **st_bdl, char *inst)
{
    int tmp;
    t_stack_bdle *st_bdl_ref;

    st_bdl_ref = *st_bdl;
    if (st_bdl_ref->size < 2)
        return;
    tmp = st_bdl_ref->head->data;
    ft_shift(&st_bdl_ref);
    ft_push(&st_bdl_ref, tmp);
    if (inst != NULL)
        ft_putstr_fd(inst, 1);
}

/* Function that make two rotation at the same time */
void ft_rrr(t_stack_bdle **st_bdl_a, t_stack_bdle **st_bdl_b)
{
    t_stack_bdle *st_bdl_a_ref;
    t_stack_bdle *st_bdl_b_ref;

    st_bdl_a_ref = *st_bdl_a;
    st_bdl_b_ref = *st_bdl_b;
    ft_mvt_bottom_to_top(&st_bdl_a_ref, NULL);
    ft_mvt_bottom_to_top(&st_bdl_b_ref, NULL);
    ft_putstr_fd("rrr ", 1);
}
