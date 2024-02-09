NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC_PATH = src/
ACTIONS_PATH = actions/
SORT_PATH = sort/
UTILS_PATH = utils/
OBJ_PATH = build/

ACTIONS_SRC = pa_pb.c ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss.c
SORT_SRC = find_optimal.c micro_sort.c quicksort.c stack_helpers.c to_front.c
UTILS_SRC = distance.c io.c list.c node.c position.c validation.c

SRC = main.c \
	$(addprefix $(ACTIONS_PATH), $(ACTIONS_SRC)) \
	$(addprefix $(SORT_PATH), $(SORT_SRC)) \
	$(addprefix $(UTILS_PATH), $(UTILS_SRC)) \

LIBFT = libft/libft.a
OBJ =	$(SRC:.c=.o)
OBJS =	$(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH) $(OBJ_PATH)actions $(OBJ_PATH)sort $(OBJ_PATH)utils

clean:
	make clean -C ./libft
	@rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re