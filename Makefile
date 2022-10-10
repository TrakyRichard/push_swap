# compile ft_printf, libft, push_swap together

NAME = push_swap.a
LIBFT = ./libft
FT_PRINTF = ./ft_printf
RM = rm -f
SRCS = push_swap.c ./shared/moves.c ./shared/operations.c ./helpers/helpers.c \
./helpers/helpers_two.c ./helpers/helpers_three.c ./helpers/init.c ./helpers/sort.c \
./helpers/stack_a_helper.c ./helpers/stack_b_helper.c ./helpers/exception.c \
./helpers/free.c ./helpers/stack_ops.c ./richard_sort/richard_sort.c \
./richard_sort/insertion_sort.c ./richard_sort/merge_sort.c ./helpers/split.c \
./shared/stack_a_sorting_process.c ./shared/stack_b_sorting_process.c ./shared/small_chunks_sort.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
flgS = -g


$(NAME) : $(OBJS)
		make -C $(LIBFT)
		make -C $(FT_PRINTF)
		cp libft/libft.a $(NAME)
		cp ft_printf/libftprintf.a $(NAME)
		ar rcs $(NAME) $(OBJS)
		${CC} -g tests/main.c push_swap.a -o push_swap

$(OBJS) : %.o : %.c
		$(CC) $(flgS) -c $< -o $@

all : $(NAME)

clean :
		@$(RM) $(OBJS)

fclean : clean
		@make fclean -C $(LIBFT)
		@make fclean -C $(FT_PRINTF)
		@$(RM) $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
