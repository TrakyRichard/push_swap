#include "../push_swap.h"
#include "../libft/libft.h"

void ft_push_to_stack_b(t_push_swap *ps, int *flg_a, int *flg_b, int chunk_track)
{
    while (ps->stack_a.tail->data < ps->middle->value && ps->stack_a.tail->chunk == ps->chunk_to_sort.head->chunk && *flg_a)
    {
            ps->stack_a.tail->chunk = chunk_track;
            ft_take_top_x_to_top_y(&ps->stack_a, &ps->stack_b, "pa ", &ps->nbre_of_swap);
            ps->middle->size--;
    }
}

void ft_reverse_stack_a(t_push_swap *ps)\
{
    int head;

    head = ps->stack_a.head->data;
    while (ps->stack_a.tail->data >= ps->middle->value \
        && ft_is_rev_sorted(&ps->stack_a.tail) == 0 && ps->chunk_to_sort.head->chunk == ps->stack_a.tail->chunk)
    {
        ft_mvt_top_to_bottom(&ps->stack_a, "ra ", &ps->nbre_of_swap);
        ps->num_of_a_rotate++;
        if (head == ps->stack_a.tail->data)
            break;
    }
}

void ft_reverse_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
    int head;

    if (ps->stack_b.size < 2)
        return;
    head = ps->stack_b.head->data;
    while (ps->stack_b.tail->data < ps->middle->value \
            && ps->chunk_to_sort.head->chunk == ps->stack_b.tail->chunk && ps->middle->size >= -1)
    {
        ft_mvt_top_to_bottom(&ps->stack_b, "rb ", &ps->nbre_of_swap);
        ps->num_of_b_rotate++;
        ps->middle->size--;
        if (head == ps->stack_b.tail->data)
        {
            preliminary_of_stack_b(ps, flg_a, flg_b);
            break;
        }
    }
    return;
}

void ft_sort_process_2(t_push_swap *ps)
{
    while (ft_can_continue(ps) == 0)
        ft_sorting_process_2(ps);
    return ;
}

int is_the_greatest_from_head(t_stack **stack, int number)
{
    t_stack *tmp;

    tmp = (*stack);
    if (tmp == NULL)
        return (1);
    while (tmp->prev != NULL && tmp != NULL && tmp->data != number)
    {
        if (tmp->data > number)
            return (0);
        tmp = tmp->prev;
    }
    if (tmp != NULL && tmp->data > number)
        return (0);
    return (1);
}

void retrieve_chunk_to_sort_of_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
    ft_init_stack_bdle(&ps->chunk_to_sort);
    ft_init_stack_bdle(&ps->sorted_stack);
    if (ft_is_rev_sorted(&ps->stack_a.tail) == 0)
    {
        if (ps->stack_a.tail->chunk == 0 && ps->stack_a.head->chunk != 0)
        {
            get_elements_reversed_of_stack_a_to_top(ps, ps->stack_a.head->chunk);
            get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->stack_a.tail->chunk, ps->stack_a);
        }
        else
            get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->stack_a.tail->chunk, ps->stack_a);
    }
    return ;
}

void preliminary_of_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ft_is_rev_sorted(&ps->stack_a.tail) == 0)
    {
        retrieve_chunk_to_sort_of_a(ps, flg_a, flg_b);
        while ((ps->chunk_to_sort.size == 2 || ps->chunk_to_sort.size == 1))
        {
            handle_stack_a_case_of_less_nbrs(ps, flg_a, flg_b);
            retrieve_chunk_to_sort_of_a(ps, flg_a, flg_b);
        }
        ps->sorted_stack = ft_richard_sort(ps->chunk_to_sort);
        ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
    }
    return;
}

void retrieve_chunk_to_sort_of_b(t_push_swap *ps)
{
    can_finished_process(ps);
    get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->stack_b.tail->chunk, ps->stack_b);
    if (ps->chunk_to_sort.size > 2 && ps->stack_b.tail->data < ps->stack_b.head->data)
    {
        get_elements_reversed_of_stack_b_to_top(ps, ps->stack_b.head->chunk);
        get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->stack_b.tail->chunk, ps->stack_b);
    }
    return ;
}

void preliminary_of_stack_b(t_push_swap *ps, int *flg_a, int *flg_b)
{
    int can_turn;

    can_turn = 0;
    can_finished_process(ps);
    retrieve_chunk_to_sort_of_b(ps);
    while (ps->chunk_to_sort.size == 2 || ps->chunk_to_sort.size == 1)
    {
        if (ft_is_rev_sorted(&ps->stack_a.tail) && ps->stack_b.tail->data >= ps->stack_b.head->data)
        {
            if (ps->stack_b.size == 2 || ps->stack_b.size == 1)
                handle_stack_b_case_of_less_nbrs(ps, flg_a, flg_b);
            else if (ps->chunk_to_sort.size == 2 && is_the_greatest_from_head(&ps->stack_b.tail->prev->prev, ps->stack_b.tail->data) && is_the_greatest_from_head(&ps->stack_b.tail->prev->prev, ps->stack_b.tail->prev->data))
                handle_stack_b_case_of_less_nbrs(ps, flg_a, flg_b);
            else if (ps->chunk_to_sort.size == 1 && is_the_greatest_from_head(&ps->stack_b.tail->prev, ps->stack_b.tail->data))
                handle_stack_b_case_of_less_nbrs(ps, flg_a, flg_b);
            else
            {
                ps->stack_b.tail->chunk = ps->stack_b.head->chunk;
                ft_mvt_top_to_bottom(&ps->stack_b, "rb ", &ps->nbre_of_swap);
                break;
            }
        }
        else
        {
            get_elements_reversed_of_stack_b_to_top(ps, ps->stack_b.head->chunk);
            get_chunk_to_sort_from_tail(&ps->chunk_to_sort, ps->stack_b.tail->chunk, ps->stack_b);
            break;
        }
        if (ps->stack_b.size > 0)
            retrieve_chunk_to_sort_of_b(ps);
        else
            break;
    }
    ps->sorted_stack = ft_richard_sort(ps->chunk_to_sort);
    ps->middle = ft_midpoint(ps->sorted_stack, ps->middle);
    return ;
}

void ft_push_to_stack_a(t_push_swap *ps, int *flg_a, int *flg_b)
{
    if (ps->stack_b.size == 0)
        return ;
    while (ps->stack_b.tail->data >= ps->middle->value && ps->stack_b.tail->chunk == ps->chunk_to_sort.head->chunk)
    {
        ps->last_chunk_of_b = ps->stack_b.tail->chunk;
        ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
        if (ps->stack_b.size == 0)
            break;
    }
    return ;
}

void ft_stack_a_sorting_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
    int chunk_track;

    chunk_track = ps->stack_a.tail->chunk + 1;
    while (*flg_a && *flg_b == 0 && ft_is_rev_sorted(&ps->stack_a.tail) == 0)
    {
        preliminary_of_stack_a(ps, flg_a, flg_b);
        check_flag_status(ps, flg_a, flg_b);
        chunk_track++;
        while (ps->middle->size > 1 && *flg_a)
        {
            ft_push_to_stack_b(ps, flg_a, flg_b, chunk_track);
            ft_reverse_stack_a(ps);
        }
        if (ps->stack_a.head->chunk != 0)
            get_elements_reversed_of_stack_a_to_top(ps, ps->stack_b.head->chunk);
        check_flag_status(ps, flg_a, flg_b);
    }
    return ;
}

void ft_stack_b_sorting_process(t_push_swap *ps, int *flg_a, int *flg_b)
{
    can_finished_process(ps);
    while (*flg_b && *flg_a == 0)
    {
        ps->last_chunk_of_b = ps->stack_b.tail->chunk;
        preliminary_of_stack_b(ps, flg_a, flg_b);
        while (ft_is_rev_dec_sorted(&ps->chunk_to_sort.tail))
        {
            while (ps->chunk_to_sort.size > 0 && ft_is_rev_sorted(&ps->stack_a.tail))
            {
                can_finished_process(ps);
                ps->stack_b.tail->chunk = 0;
                ft_take_top_x_to_top_y(&ps->stack_b, &ps->stack_a, "pb ", &ps->nbre_of_swap);
                ft_pop(&ps->chunk_to_sort);
            }
            preliminary_of_stack_b(ps, flg_a, flg_b);
        }
        while (ps->chunk_to_sort.head->chunk == ps->stack_b.tail->chunk && ps->middle->size > -1 && ps->stack_b.size > 0 && *flg_b)
        {
            ft_push_to_stack_a(ps, flg_a, flg_b);
            ft_reverse_stack_b(ps, flg_a, flg_b);
            if (ps->stack_b.size == 0)
                return;
            if (ps->stack_b.size == 1 || ps->stack_b.size == 2)
            {
                preliminary_of_stack_b(ps, flg_a, flg_b);
                check_flag_status(ps, flg_a, flg_b);
            }
        }
        check_flag_status(ps, flg_a, flg_b);
    }
    return ;
}

void ft_sorting_process_2(t_push_swap *ps)
{
    int flg_a;
    int flg_b;

    flg_a = 1;
    flg_b = 0;
    ft_stack_a_sorting_process(ps, &flg_a, &flg_b);
    ft_stack_b_sorting_process(ps, &flg_a, &flg_b);
    return ;
}

void can_finished_process(t_push_swap *ps)
{
    if (ps->stack_b.size == 0 && ft_is_rev_sorted(&ps->stack_a.tail))
        exit(0);
    return ;
}

void check_flag_status(t_push_swap *ps, int *flg_a, int *flg_b)
{
    can_finished_process(ps);
    if (ps->stack_b.size == 0 && ft_is_rev_sorted(&ps->stack_a.head))
    {
        *flg_a = 1;
        *flg_b = 1;
    }
    if (ps->last_chunk_of_a != ps->stack_a.tail->chunk || ps->middle->size >= 0 || ps->stack_a.size > 2)
    {
        *flg_a = 1;
        *flg_b = 0;
    }
    if (ps->stack_b.size > 0  && ft_is_rev_sorted(&ps->stack_a.tail))
    {
        set_chunk_nbrs(&ps->stack_a, 0);
        *flg_a = 0;
        *flg_b = 1;
    }
    return;
}

/*
2931 9203 2027 9939 -1217 8933 7476 6104 -351 7003 9073 4783 2246 8384 2880 6546 9589 3697 -678 5475 7642 8403 4917 -1192 9357 9706 7873 4744 -614 6384 3519 7182 9908 3565 2459 7249 1022 3401 7185 3980 -229 -133 -790 180 9259 7111 3873 7423 1780 8927 1158 8 -810 242 5726 3126 5874 5200 3208 -62 1271 5867 3085 3312 5382 2446 2307 2647 3460 4617 2883 -707 5066 2319 2460 2436 7216 5859 -902 -748 2681 1381 4406 3597 9888 582 7344 4450 6381 2861 -103 6827 6736 1846 -726 6318 5855 6700 7835 1760
 */