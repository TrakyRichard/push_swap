# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 07:00:30 by rkanmado          #+#    #+#              #
#    Updated: 2022/10/05 03:21:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MANDATORIESSRCS=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUSSRCS=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
		ft_lstiter.c ft_lstmap.c

MANDATORIESOBJS = $(MANDATORIESSRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)


CC = cc
Cflg = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MANDATORIESOBJS)
	@ar rcs $(NAME) $(MANDATORIESOBJS)

$(MANDATORIESOBJS): $(MANDATORIESSRCS)
		   	$(CC) $(Cflg) -c $(MANDATORIESSRCS)

bonus: $(BONUSOBJS)
	@ar rcs $(NAME) $(BONUSOBJS)

$(BONUSOBJS): $(BONUSSRCS)
	$(CC) $(Cflg) -c $(BONUSSRCS)

clean:
	@rm -f $(MANDATORIESOBJS) $(BONUSOBJS)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean bonus fclean re
