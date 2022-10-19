# compile ft_printf, libft, push_swap together

NAME = push_swap.a
BONUS_NAME = checker
LIBFT = ./libft
FT_PRINTF = ./ft_printf
GNL = ./bonus/get_next_line
RM = rm -f
SRCS = push_swap.c ./shared/moves.c ./shared/operations.c ./helpers/helpers.c \
./helpers/helpers_two.c ./helpers/helpers_three.c ./helpers/init.c ./helpers/sort.c \
./helpers/stack_a_helper.c ./helpers/stack_b_helper.c ./helpers/stack_b_helper_two.c \
./helpers/exception.c \
./helpers/free.c ./helpers/stack_ops.c ./richard_sort/richard_sort.c \
./richard_sort/insertion_sort.c ./richard_sort/merge_sort.c ./helpers/split.c \
./shared/stack_a_sorting_process.c ./shared/stack_b_sorting_process.c ./shared/small_chunks_sort.c \

BONUSRCS = ./bonus/checker.c ./bonus/move.c ./bonus/utils.c ./bonus/get_next_line/get_next_line_utils.c \
			./bonus/get_next_line/get_next_line.c

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSRCS:.c=.o)

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

$(BONUSOBJS): %.o : %.c
		$(CC) $(flgS) -c $< -o $@

all : $(NAME)

bonus : $(BONUSOBJS) $(NAME)
		$(CC) $(flgS) $(BONUSOBJS) ./push_swap.a -o bonus/$(BONUS_NAME)

clean :
		@$(RM) $(OBJS) $(BONUSOBJS)

fclean : clean
		@make fclean -C $(LIBFT)
		@make fclean -C $(FT_PRINTF)
		@$(RM) $(NAME) $(BONUSOBJS) ./bonus/checker ./push_swap

re : fclean all

.PHONY : all clean fclean re bonus
