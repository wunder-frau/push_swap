NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC_PATH = src/
OBJ_PATH = obj/

SRC = 	main.c \
			io_utils.c list_utils.c node_utils.c \
			stack_helpers.c quicksort.c actions.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))
LIBFT = libft/libft.a
OBJ =	$(SRC:.c=.o)
OBJS =	$(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

clean:
	make clean -C ./libft
	@rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re