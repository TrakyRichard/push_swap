NAME = libftprintf.a
LIBFT = ./libft
RM = rm -f
SRCS = 	ft_printf.c \
			src/ft_print_char.c \
			src/ft_print_str.c \
			src/ft_print_adrr.c \
			src/ft_print_hex.c \
			src/ft_print_num.c \
			src/ft_print_uns.c \

CC = gcc
FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
					make -C ./libft
					cp libft/libft.a $(NAME)
					ar rcs $(NAME) $(OBJS)


all: 		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean: 	clean
				@make fclean -C $(LIBFT)
				@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re
