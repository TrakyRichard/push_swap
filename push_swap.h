/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/15 14:38:13 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
typedef struct s_stack
{
	int data;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

typedef struct s_stack_bdle
{
	t_stack *head;
	t_stack *tail;
	int size;
} t_stack_bdle;

typedef struct s_push_swap
{
	t_stack_bdle stack_a;
	t_stack_bdle stack_b;
	char *instructions;
	int nbre_of_swap;
} t_push_swap;

void push_swap(int argc, char **argv);
/* Stack operations */
void ft_push(t_stack_bdle **stack, int data);
int ft_pop(t_stack_bdle **stack);
void ft_unshift(t_stack_bdle **stack_bdle, int data);
int ft_shift(t_stack_bdle **stack);
void ft_display_stack(t_stack **stack);
void ft_rev_stack(t_stack **head);
void init_stack(t_push_swap *push_swap);

/* Helper functions */
void read_argv(int argc, char **argv, t_push_swap *push_swap);
int ft_digit(char *str);
void ft_error(char *str);
void ft_free_dbl_point(char **str);
void ft_free_stack(t_stack **tail, t_stack **head);
int ft_is_sorted(t_stack **tail);
void swap_node(t_stack **stack1, t_stack **stack2);
void swap_int(int *a1, int *a2);

/* Sorting functions */
void sort_stack(t_push_swap *push_swap);

/* moves operation */
void take_top_x_to_top_y(t_stack_bdle *st_bdl_x, t_stack_bdle *st_bdl_y, char *inst);
void swap_with_next_node(t_stack_bdle *st_bdl, char *inst);
void ss(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b);
void mvt_top_to_bottom(t_stack_bdle *st_bdl, char *inst);
void rr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b);
void mvt_bottom_to_top(t_stack_bdle *st_bdl_a, char *inst);
void rrr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b);

#endif
