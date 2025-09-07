NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I incl -I ../ft_printf
AR = ar rcs
RM = rm -f

SRCS = $(wildcard *.c) $(wildcard ../ft_printf/*.c)
OBJS = $(patsubst ../ft_printf/%.c,ft_printf_%.o,$(wildcard ../ft_printf/*.c)) $(SRCS:.c=.o)
HDR = libft.h incl/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf_%.o: ../ft_printf/%.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
