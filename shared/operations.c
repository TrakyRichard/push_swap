#include "../push_swap.h"
#include "../libft/libft.h"

void ft_sort_process(t_push_swap *ps)
{
    if (ps->stack_a.size == 3)
        ft_sort_three(ps);
    else if (ps->stack_a.size == 4)
        ft_sort_four(ps);
    else if (ps->stack_a.size == 5)
        ft_sort_five(ps);
    else
        while (ft_can_continue(ps) == 0)
            ft_sorting_process(ps);
    return;
}

void ft_sorting_process(t_push_swap *ps)
{
    int flg_a;
    int flg_b;

    flg_a = 1;
    flg_b = 0;
    ft_stack_a_sorting_process(ps, &flg_a, &flg_b);
    ft_stack_b_sorting_process(ps, &flg_a, &flg_b);
    return;
}

void check_flag_status(t_push_swap *ps, int *flg_a, int *flg_b)
{
    can_finished_process(ps);
    if (ps->stack_b.size == 0 && ft_is_rev_sorted(&ps->stack_a.tail))
    {
        *flg_a = 1;
        *flg_b = 1;
    }
    if (ps->last_chunk_of_a != ps->stack_a.head->chunk || ps->middle->size >= 0 || ps->stack_a.size > 2)
    {
        *flg_a = 1;
        *flg_b = 0;
    }
    if (ps->stack_b.size > 0 && ft_is_rev_sorted(&ps->stack_a.head))
    {
        set_chunk_nbrs(&ps->stack_a, 0);
        *flg_a = 0;
        *flg_b = 1;
    }
    return;
}

int ft_can_continue(t_push_swap *ps)
{
    if (ft_is_rev_sorted(&ps->stack_a.head) && ps->stack_b.size == 0)
        return (1);
    return (0);
}