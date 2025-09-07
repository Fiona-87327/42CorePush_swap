# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 13:11:21 by jiyawang          #+#    #+#              #
#    Updated: 2025/09/07 14:45:18 by jiyan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned.c \
ft_puthexl.c ft_puthexu.c ft_putpointer.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME)
 
re: fclean all

.PHONY: all clean fclean re