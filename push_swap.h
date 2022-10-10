/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/10 05:16:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#ifndef RUN
#define RUN 64
#endif

#ifdef _MSC_VER
#include <crtdbg.h>
#else
#define _ASSERT(expr) ((void)0)

#define _ASSERTE(expr) ((void)0)
#endif
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
typedef struct s_node
{
	int data;
	int chunk;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_stack_bdle
{
	t_node *head;
	t_node *tail;
	int size;
} t_stack_bdle;

typedef struct s_richard_sort
{
	int i;
	t_stack_bdle new_chunk;
	t_stack_bdle sorted_stack;
	t_stack_bdle result;
} t_richard_sort;

typedef struct s_merge_sort
{
	t_stack_bdle left;
	t_stack_bdle right;
	t_stack_bdle result;
	t_stack_bdle sorted_stack;
} t_merge_sort;

typedef struct s_middle
{
	int size;
	int value;
} t_middle;

typedef struct s_push_swap
{
	t_stack_bdle stack_a;
	t_stack_bdle stack_b;
	t_stack_bdle sorted_stack;
	t_stack_bdle chunk_to_sort;
	t_middle *middle;
	int nbre_of_swap;
} t_push_swap;

void push_swap(int argc, char **argv);
/* Exceptions */
void ft_error(char *str);
void can_finished_process(t_push_swap *ps);
void check_duplicate(t_stack_bdle *stack);

/* Free */
void ft_free_dbl_point(char **str);
void ft_free_stack(t_node **tail, t_node **head);
void free_push_swap(t_push_swap *ps);

/* Helpers_three */
void get_chunk_to_sort_from_head(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack);
void get_chunk_to_sort_from_tail(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack);
void set_chunk_nbrs(t_stack_bdle *stack, int chunk_nbrs);

/* Helpers_two */
int is_chunks_sorted(t_push_swap *ps, int chunk_one, int chunk_two);
int get_top_chunk_size(t_stack_bdle stack);
int is_value_greater_than_middle(t_stack_bdle stack, int middle);
void ft_insert_all_node(t_stack_bdle *stack, t_stack_bdle *stack_to_insert);
void ft_display_stack(t_node *tail);

/* Helpers */
void ft_read_argv(int argc, char *argv[], t_push_swap *push_swap);
int ft_digit(char *str);
int is_one_chunk_in_stack(t_node *stack, int chunk);
void ft_bind_two_stacks(t_stack_bdle *stack_one, t_node *stack_two);

/* Init */
void ft_init_push_swap_stack(t_push_swap *push_swap);
void ft_init_stack_bdle(t_stack_bdle *stack);
t_stack_bdle ft_duplicate_stack(t_stack_bdle *stack);

/* Sort */
int ft_is_rev_dec_sorted(t_node **head);
int ft_is_rev_sorted(t_node **head);
int ft_is_sorted(t_node **tail);
int is_the_greatest_from_head(t_node **stack, int number);

/* Split */
t_middle *ft_midpoint(t_stack_bdle stack, t_middle *actual_middle);
void ft_split_n_element(t_stack_bdle *stack, t_stack_bdle *new_chunk, int n);
void ft_split_to_get_chunk(t_stack_bdle *stack_ref_bdle, t_stack_bdle *new_chunk, int n);

/* Stack_a_helper */
void handle_stack_a_case_of_less_nbrs(t_push_swap *ps);
void retrieve_chunk_to_sort_of_a(t_push_swap *ps, int *flg_a, int *flg_b);
void preliminary_of_stack_a(t_push_swap *ps, int *flg_a, int *flg_b);

/* Stack_b_helper */
void retrieve_chunk_to_sort_of_b(t_push_swap *ps);
void preliminary_of_stack_b(t_push_swap *ps, int *flg_a, int *flg_b);
void handle_stack_b_case_of_less_nbrs(t_push_swap *ps);
void push_sorted_chunk_in_stack_a(t_push_swap *ps, int *flg_a, int *flg_b);
void handle_stack_b_two_nbrs_case(t_push_swap *ps);

/* Stack_ops */
void ft_unshift(t_stack_bdle *stack_bdle, int data, int chunk);
void ft_push(t_stack_bdle *stack, int data, int chunk);
int ft_pop(t_stack_bdle *stack);
int ft_shift(t_stack_bdle *stack);

/* moves */
void ft_take_top_x_to_top_y(t_stack_bdle *st_bdl_x, t_stack_bdle *st_bdl_y, char *inst, int *swap_nbrs);
void ft_swap_with_next_node(t_stack_bdle *st_bdl, char *inst, int *swap_nbrs);
void ft_insert_before_tail(t_stack_bdle *st_bdl, int data, int chunk);
void ft_ss(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, int *swap_nbrs);
void ft_mvt_top_to_bottom(t_stack_bdle *st_bdl, char *inst, int *swap_nbrs);
void ft_rr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, int *swap_nbrs);
void ft_mvt_bottom_to_top(t_stack_bdle *st_bdl_a, char *inst, int *swap_nbrs);
void ft_rrr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, int *swap_nbrs);

/* Operations */
void ft_sort_process(t_push_swap *ps);
void ft_sorting_process(t_push_swap *ps);
void check_flag_status(t_push_swap *ps, int *flg_a, int *flg_b);
int ft_can_continue(t_push_swap *ps);

/* stack_a_sorting_process */
void ft_stack_a_sorting_process(t_push_swap *ps, int *flg_a, int *flg_b);
void ft_reverse_stack_a(t_push_swap *ps);
void get_elements_reversed_of_stack_a_to_top(t_push_swap *ps, int chunk_nbrs);
void is_chunk_a_already_sorted(t_push_swap *ps, int *flg_a, int *flg_b);
void ft_push_to_stack_a(t_push_swap *ps, int *flg_a, int *flg_b);
;

/* stack_b_sorting_process */
void ft_push_to_stack_b(t_push_swap *ps, int *flg_a, int *flg_b, int chunk_track);
void ft_reverse_stack_b(t_push_swap *ps, int *flg_a, int *flg_b);
void ft_stack_b_sorting_process(t_push_swap *ps, int *flg_a, int *flg_b);
void get_elements_reversed_of_stack_b_to_top(t_push_swap * ps, int chunk_nbrs);
void is_chunk_b_already_sorted(t_push_swap *ps, int *flg_a, int *flg_b);

/* richard_sort */
void ft_sorted_insertion(t_node **tail, t_node *new_node);
void ft_insertion_sort(t_node **tail);
t_stack_bdle ft_merge(t_stack_bdle *left, t_stack_bdle *right);
t_stack_bdle ft_iterativeMergeSort(t_stack_bdle *stack);
t_stack_bdle ft_richard_sort(t_stack_bdle stack);
void init_richard_sort(t_richard_sort *r_sort);
void set_new_value_of_counter(t_stack_bdle *stack, int *i);

/* small chunk sort */
void ft_sort_three(t_push_swap *ps);
void ft_sort_five(t_push_swap *ps);
void ft_sort_four(t_push_swap *ps);

#endif