# compile ft_printf, libft, push_swap together

NAME = push_swap.a
LIBFT = ./libft
FT_PRINTF = ./ft_printf
RM = rm -f
SRCS = push_swap.c ./shared/moves.c ./shared/operations.c ./helpers/helpers.c ./helpers/error.c ./helpers/free.c ./helpers/stack_ops.c ./helpers/swap.c \
richard_sort/richard_sort.c richard_sort/insertion_sort.c \
richard_sort/merge_sort.c helpers/split.c 


CC = gcc
FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		make -C $(LIBFT)
		make -C $(FT_PRINTF)
		cp libft/libft.a $(NAME)
		cp ft_printf/libftprintf.a $(NAME)
		ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
		@$(RM) $(OBJS)

fclean : clean
		@make fclean -C $(LIBFT)
		@make fclean -C $(FT_PRINTF)
		@$(RM) $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
