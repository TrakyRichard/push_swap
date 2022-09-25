/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/25 15:02:11 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef RUN
# define RUN 64
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int data;
	int chunk;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

typedef struct s_middle
{
	int data;
	int index;
} t_middle;

typedef struct s_stack_bdle
{
	t_stack *tail;
	t_stack *head;
	int size;
} t_stack_bdle;

typedef struct s_push_swap
{
	t_stack_bdle stack_a;
	t_stack_bdle stack_b;
	t_middle middle;
	char *instructions;
	int nbre_of_swap;
} t_push_swap;

void push_swap(int argc, char **argv);
/* Stack operations */
void ft_push(t_stack_bdle **stack, int data);
int ft_pop(t_stack_bdle **stack);
void ft_unshift(t_stack_bdle **stack_bdle, int data);
int ft_shift(t_stack_bdle **stack);
void ft_display_stack(t_stack *stack);
void ft_rev_stack(t_stack **tail);
void ft_init_t_push_swap(t_push_swap *push_swap);
void ft_init_stack(t_stack *stack);
t_stack_bdle *ft_duplicate_stack(t_stack_bdle *stack);
void ft_init_stack_bdle(t_stack_bdle *stack);
int ft_is_stack_empty(t_stack_bdle *stack);


/* Helper functions */
void ft_read_argv(int argc, char **argv, t_push_swap *push_swap);
int ft_digit(char *str);
void ft_error(char *str);
void ft_free_dbl_point(char **str);
void ft_free_stack(t_stack **head, t_stack **tail);
int ft_is_sorted(t_stack **head);
void ft_swap_node(t_stack **stack1, t_stack **stack2);
void ft_swap_int(int *a1, int *a2);
t_middle ft_midpoint(t_stack *head);
void ft_split_to_get_chunk(t_stack_bdle **stack_ref_bdle, t_stack_bdle *new_chunk, int size);
// void ft_init_sort_var(int *counter, t_stack **head_ref, t_stack **head, \
// 					t_stack **sorted_stack, t_stack **new_chunk);
void ft_split_n_element(t_stack_bdle **stack, t_stack_bdle **new_chunk, int n);
void ft_bind_two_stacks(t_stack_bdle *stack_one, t_stack *stack_two);
void ft_insert_all_node(t_stack_bdle **stack, t_stack_bdle **stack_to_insert);

/* moves operation */
void ft_take_top_x_to_top_y(t_stack_bdle **st_bdl_x, t_stack_bdle **st_bdl_y, char *inst);
void ft_swap_with_next_node(t_stack_bdle **st_bdl, char *inst);
void ft_ss(t_stack_bdle **st_bdl_a, t_stack_bdle **st_bdl_b);
void ft_mvt_top_to_bottom(t_stack_bdle **st_bdl, char *inst);
void ft_rr(t_stack_bdle **st_bdl_a, t_stack_bdle **st_bdl_b);
void ft_mvt_bottom_to_top(t_stack_bdle **st_bdl_a, char *inst);
void ft_rrr(t_stack_bdle **st_bdl_a, t_stack_bdle **st_bdl_b);


/* sorting functions */
t_stack_bdle ft_merge(t_stack_bdle *left, t_stack_bdle *right);
t_stack_bdle *ft_merge_sort(t_stack_bdle **stack);
t_stack_bdle ft_iterative_merge_sort(t_stack_bdle *stack);
void ft_insertion_sort(t_stack **head);
void ft_sort_stack(t_push_swap *push_swap);
t_stack_bdle ft_richard_sort(t_stack_bdle *stack);
void ft_sorted_insertion(t_stack **head, t_stack *new_node);
void ft_sorting_process(t_push_swap **ps);
void handle_stack_a_case_of_2_nbrs(t_stack_bdle *stack_a, t_stack_bdle *stack_b, int chunk);
void handle_stack_a_normal_case(t_stack_bdle *stack_a, t_stack_bdle *stack_b, int chunk, int middle);
void get_chunk_to_sort(t_stack_bdle *stack, int chunk, t_stack_bdle *stack_b);

#endif
