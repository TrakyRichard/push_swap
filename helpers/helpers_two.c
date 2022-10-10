
#include "../push_swap.h"
#include "../libft/libft.h"

/* Check if 2 last successive chunks are sorted into the stack a */
int is_chunks_sorted(t_push_swap *ps, int chunk_one, int chunk_two)
{
    t_node *tmp;
    t_stack_bdle stack;

    ft_init_stack_bdle(&stack);
    tmp = ps->stack_a.head;
    while (tmp != NULL && (tmp->chunk == chunk_one || tmp->chunk == chunk_two) && tmp->prev != NULL)
        tmp = tmp->prev;
    {
        ft_unshift(&stack, tmp->data, tmp->chunk);
        tmp = tmp->prev;
    }
    if (tmp != NULL && (tmp->chunk == chunk_one || tmp->chunk == chunk_two))
        ft_unshift(&stack, tmp->data, tmp->chunk);
    if (ft_is_rev_dec_sorted(&stack.head))
        return (1);
    else
        return (0);
}

/* retrieve the size of the last chunk like how many items it's contains */
int get_top_chunk_size(t_stack_bdle stack)
{
    int chunk_nbrs;
    int size;
    t_node *tmp;

    tmp = stack.head;
    chunk_nbrs = tmp->chunk;
    size = 0;
    while (tmp != NULL && tmp->chunk == chunk_nbrs && tmp->prev != NULL)
    {
        size++;
        tmp = tmp->prev;
    }
    return (size);
}

/* Check if there is one value greater than the middle value otherwise no need to rotate*/
int is_value_greater_than_middle(t_stack_bdle stack, int middle)
{
    t_node *tmp;

    tmp = stack.head;
    while (tmp != NULL && tmp->prev != NULL)
    {
        if (tmp->data > middle)
            return (1);
        tmp = tmp->prev;
    }
    return (0);
}

/* function to insert all element for one list to another */
void ft_insert_all_node(t_stack_bdle *stack, t_stack_bdle *stack_to_insert)
{
    t_node *current;

    current = stack_to_insert->tail;
    if (current == NULL)
        return;
    while (current != NULL && current->next != NULL)
    {
        ft_push(stack, current->data, current->chunk);
        current = current->next;
    }
    ft_push(stack, current->data, current->chunk);
}

/* Display the informations into stack a */
void ft_display_stack(t_node *tail)
{
    t_node *tmp;

    tmp = tail;
    while (tmp != NULL && tmp->next != NULL)
    {
        ft_printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    if (tmp != NULL)
    {
        ft_printf("%d ", tmp->data);
    }
}
