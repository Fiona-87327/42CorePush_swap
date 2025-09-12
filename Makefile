NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -Iincludes

SRC_DIR     = src
OBJ_DIR     = obj

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/stack.c \
	$(SRC_DIR)/ops_swap.c \
	$(SRC_DIR)/ops_push.c \
	$(SRC_DIR)/ops_rotate.c \
	$(SRC_DIR)/ops_rev_rotate.c \
	$(SRC_DIR)/index.c \
	$(SRC_DIR)/sort_small.c \
	$(SRC_DIR)/sort_big.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
