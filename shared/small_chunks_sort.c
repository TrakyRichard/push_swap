#include "../push_swap.h"
#include "../libft/libft.h"

void ft_sort_three(t_push_swap *ps)
{
    t_stack_bdle *stack;

    stack = &ps->stack_a;
    if (stack->head->data > stack->head->next->data && stack->head->data > stack->tail->data)
    {
        if (stack->head->next->data < stack->tail->data)
            ft_swap_with_next_node(&ps->stack_a, "sa ", &ps->nbre_of_swap);
    }
    else if (stack->head->next->data > stack->head->data && stack->head->next->data > stack->tail->data)
    {
        if (stack->head->data < stack->tail->data)
            ft_mvt_bottom_to_top(&ps->stack_a, "rra ", &ps->nbre_of_swap);
        else
        {
            ft_mvt_bottom_to_top(&ps->stack_a, "rra ", &ps->nbre_of_swap);
            ft_swap_with_next_node(&ps->stack_a, "sa ", &ps->nbre_of_swap);
        }
    }
    else if (stack->tail->data > stack->head->next->data && stack->tail->data > stack->head->data)
    {
        if (stack->head->next->data < stack->head->data)
            ft_mvt_top_to_bottom(&ps->stack_a, "ra ", &ps->nbre_of_swap);
        else
        {
            ft_swap_with_next_node(&ps->stack_a, "sa ", &ps->nbre_of_swap);
            ft_mvt_bottom_to_top(&ps->stack_a, "rra ", &ps->nbre_of_swap);
        }
    }
    can_finished_process(ps);
    return;
}

void ft_sort_five(t_push_swap *ps)
{
    int i;

    i = 0;
    ft_init_stack_bdle(&ps->chunk_to_sort);
    ft_init_stack_bdle(&ps->sorted_stack);

    get_chunk_to_sort_from_tail(&ps->chunk_to_sort, 0, ps->stack_a);
    ps->sorted_stack = ft_richard_sort(ps->chunk_to_sort);
    ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
    while (i < 2)
    {
        if (ps->stack_a.tail->data < ps->middle->value)
        {
            ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pb ", &ps->nbre_of_swap);
            i++;
        }
        else
            ft_mvt_top_to_bottom(&ps->stack_a, "ra ", &ps->nbre_of_swap);
    }
    ft_sort_three(ps);
    handle_stack_b_two_nbrs_case(ps);
    can_finished_process(ps);
    return;
}

void ft_sort_four(t_push_swap *ps)
{
    int i;

    i = 0;
    ft_init_stack_bdle(&ps->chunk_to_sort);
    ft_init_stack_bdle(&ps->sorted_stack);

    get_chunk_to_sort_from_tail(&ps->chunk_to_sort, 0, ps->stack_a);
    ps->sorted_stack = ft_richard_sort(ps->chunk_to_sort);
    ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
    while (i < 1)
    {
        if (ps->stack_a.tail->data < ps->middle->value)
        {
            ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pb ", &ps->nbre_of_swap);
            i++;
        }
        else
            ft_mvt_top_to_bottom(&ps->stack_a, "ra ", &ps->nbre_of_swap);
    }
    ft_sort_three(ps);
    ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pa ", &ps->nbre_of_swap);
    can_finished_process(ps);
    return;
}