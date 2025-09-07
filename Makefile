NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./libft/incl -I ./libft

SRCS = push_swap.c sort.c utils.c
OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

$(LIBFT):
	$(MAKE) -C ./libft

re: fclean all

.PHONY: all clean fclean re
