/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/09/29 06:23:48 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#ifndef RUN
#define RUN 32
#endif

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
typedef struct s_stack
{
	int data;
	int chunk;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

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
	t_stack_bdle sorted_stack;
	t_stack_bdle chunk_to_sort;
	int middle;
	int chunk_nbrs;
	char *instructions;
	int nbre_of_swap;
} t_push_swap;

void push_swap(int argc, char **argv);
/* Stack operations */
void ft_push(t_stack_bdle *stack, int data, int chunk);
int ft_pop(t_stack_bdle *stack);
void ft_unshift(t_stack_bdle *stack_bdle, int data, int chunk);
int ft_shift(t_stack_bdle *stack);
void ft_display_stack(t_stack *stack);
void ft_rev_stack(t_stack *tail);
void ft_init_push_swap_stack(t_push_swap *push_swap);
t_stack_bdle *ft_duplicate_stack(t_stack_bdle *stack);

/* Helper functions */
void ft_read_argv(int argc, char **argv, t_push_swap *push_swap);
int ft_digit(char *str);
void ft_error(char *str);
void ft_free_dbl_point(char **str);
void ft_free_stack(t_stack **head, t_stack **tail);
int ft_is_sorted(t_stack **head);
void ft_swap_node(t_stack **stack1, t_stack **stack2);
void ft_insert_before_tail(t_stack_bdle *st_bdl, int data, int chunk);
void ft_swap_int(int *a1, int *a2);
int ft_midpoint(t_stack_bdle stack);
void ft_split_to_get_chunk(t_stack_bdle *stack_ref_bdle, t_stack_bdle *new_chunk, int size);
void ft_init_stack_bdle(t_stack_bdle *stack);
// void ft_init_sort_var(int *counter, t_stack **head_ref, t_stack **head, \
// 					t_stack **sorted_stack, t_stack **new_chunk);
void ft_split_n_element(t_stack_bdle *stack, t_stack_bdle *new_chunk, int n);
void ft_bind_two_stacks(t_stack_bdle *stack_one, t_stack *stack_two);
void ft_insert_all_node(t_stack_bdle *stack, t_stack_bdle *stack_to_insert);
/* moves operation */
void ft_take_top_x_to_top_y(t_stack_bdle *st_bdl_x, t_stack_bdle *st_bdl_y, char *inst);
void ft_swap_with_next_node(t_stack_bdle *st_bdl, char *inst);
void ft_ss(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b);
void ft_mvt_top_to_bottom(t_stack_bdle *st_bdl, char *inst);
void ft_rr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b);
void ft_mvt_bottom_to_top(t_stack_bdle *st_bdl_a, char *inst);
void ft_rrr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b);

/* sorting functions */
t_stack_bdle ft_merge(t_stack_bdle *left, t_stack_bdle *right);
t_stack_bdle *ft_mergeSort(t_stack_bdle **stack);
t_stack_bdle ft_iterativeMergeSort(t_stack_bdle *stack);
void ft_insertion_sort(t_stack **head);
void ft_sort_stack(t_push_swap *push_swap);
t_stack_bdle ft_richard_sort(t_stack_bdle *stack);
void ft_sorted_insertion(t_stack **head, t_stack *new_node);
int ft_is_rev_sorted(t_stack **tail);

void ft_sorting_process(t_push_swap *ps);
void get_chunk_of_a_to_sort(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack);
void get_chunk_of_b_to_sort(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack);
void handle_stack_a_case_of_2_nbrs(t_push_swap *ps, int *flag_a, int *flag_b);
void handle_stack_a_sort_process(t_push_swap *ps, int *flag_a, int *flag_b);
void handle_stack_b_case_of_less_nbrs(t_push_swap *ps, int *flag_a, int *flag_b);
void handle_stack_b_sort_process(t_push_swap *ps, int *flag_a, int *flag_b);
void handle_stack_b_case_of_two_chunks(t_push_swap *ps, int *flag_a, int *flag_b);
void handle_stack_b_case_of_one_nbr(t_push_swap *ps, int *flag_a, int *flag_b);
int ft_can_continue(t_push_swap *ps);
// void set_new_value_of_chunk(t_push_swap *ps, int can_increment);
#endif
