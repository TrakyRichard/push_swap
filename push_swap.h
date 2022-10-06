/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/06 03:12:13 by marvin           ###   ########.fr       */
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
	int num_of_a_rotate;
	int num_of_b_rotate;
	int last_chunk_of_a;
	int last_chunk_of_b;
	int chunk_nbrs;
	char *instructions;
	int nbre_of_swap;
	int can_turn;
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
t_stack_bdle ft_duplicate_stack(t_stack_bdle *stack);

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
t_middle *ft_midpoint(t_stack_bdle stack, t_middle *actual_middle);
void ft_split_to_get_chunk(t_stack_bdle *stack_ref_bdle, t_stack_bdle *new_chunk, int size);
void ft_init_stack_bdle(t_stack_bdle *stack);
// void ft_init_sort_var(int *counter, t_stack **head_ref, t_stack **head, \
// 					t_stack **sorted_stack, t_stack **new_chunk);
void ft_split_n_element(t_stack_bdle *stack, t_stack_bdle *new_chunk, int n);
void ft_bind_two_stacks(t_stack_bdle *stack_one, t_stack *stack_two);
void ft_insert_all_node(t_stack_bdle *stack, t_stack_bdle *stack_to_insert);
/* moves operation */
void ft_take_top_x_to_top_y(t_stack_bdle *st_bdl_x, t_stack_bdle *st_bdl_y, char *inst, int *swap_nbrs);
void ft_swap_with_next_node(t_stack_bdle *st_bdl, char *inst, int *swap_nbrs);
void ft_ss(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, int *swap_nbrs);
void ft_mvt_top_to_bottom(t_stack_bdle *st_bdl, char *inst, int *swap_nbrs);
void ft_rr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, int *swap_nbrs);
void ft_mvt_bottom_to_top(t_stack_bdle *st_bdl_a, char *inst, int *swap_nbrs);
void ft_rrr(t_stack_bdle *st_bdl_a, t_stack_bdle *st_bdl_b, int *swap_nbrs);

/* sorting functions */
t_stack_bdle	ft_merge(t_stack_bdle *left, t_stack_bdle *right);
t_stack_bdle	*ft_mergeSort(t_stack_bdle **stack);
t_stack_bdle	ft_iterativeMergeSort(t_stack_bdle *stack);
void			ft_insertion_sort(t_stack **head);
void			ft_sort_stack(t_push_swap *push_swap);
t_stack_bdle	ft_richard_sort(t_stack_bdle stack);
void			ft_sorted_insertion(t_stack **head, t_stack *new_node);
int				ft_is_rev_sorted(t_stack **tail);
int				ft_is_rev_dec_sorted(t_stack **tail);

void			ft_sorting_process(t_push_swap *ps);
void			get_chunk_to_sort_from_head(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack);
void			get_chunk_to_sort_from_tail(t_stack_bdle *chunk_to_sort, int chunk, t_stack_bdle stack);
void			get_elements_reversed_of_stack_a_to_top(t_push_swap *ps, int chunk_nbrs);
void			get_elements_reversed_of_stack_b_to_top(t_push_swap *ps, int chunk_nbrs);
void			handle_order_inside_stack_a(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_order_inside_stack_b(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_stack_a_case_of_2_nbrs(t_push_swap *ps, int *flg_a, int *flg_b);
void			ft_ping_pong_process(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_stack_a_sort_process(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_stack_b_case_of_less_nbrs(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_stack_a_case_of_less_nbrs(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_stack_b_sort_process(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_stack_b_case_of_two_chunks(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_stack_b_case_of_one_chunk(t_push_swap *ps, int *flg_a, int *flg_b);
void			ft_order_rev_sorted_chunk_on_stack_b(t_push_swap *ps, int *flg_a, int *flg_b);
void			ft_order_rev_dec_chunk_on_stack_b(t_push_swap *ps, int *flg_a, int *flg_b);
int				ft_can_continue(t_push_swap *ps);
void			ft_push_chunk_to_stack_a(t_push_swap *ps, int *flg_a, int *flg_b);
void			ft_push_chunk_to_stack_b(t_push_swap *ps, int *flg_a, int *flg_b);
int 			can_dec_ck_nbrs_in_stack_b(t_push_swap *ps);
int				can_switch_to_stack_a(t_push_swap *ps, int *flg_a, int *flg_b);
int 			can_switch_to_stack_b(t_push_swap *ps, int *flg_a, int *flg_b);
void			set_chunk_nbrs(t_stack_bdle *stack, int chunk_nbrs);
int				is_chunks_sorted(t_push_swap *ps, int chunk_one, int chunk_two);
int				get_top_chunk_size(t_stack_bdle stack);
void 			reverse_stack_a_process(t_push_swap *ps);
void 			reverse_stack_b_process(t_push_swap *ps, int *flg_a, int *flg_b);
void			do_the_preliminary_of_stack_b(t_push_swap *ps);
void			do_the_preliminary_of_stack_a(t_push_swap *ps, int *flg_a, int *flg_b);
void			handle_stack_a_sort_step_one(t_push_swap *ps);
void			handle_stack_a_sort_step_two(t_push_swap *ps);
void			handle_stack_a_sort_step_three(t_push_swap *ps);
// void set_new_value_of_chunk(t_push_swap *ps, int can_increment);
#endif
