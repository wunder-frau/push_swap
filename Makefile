NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC_PATH = src/
ACTIONS_path = actions
SORT_path = sort
OBJ_PATH = obj/

SRC = 	main.c \
			$(ACTIONS_path)/pa_pb.c $(ACTIONS_path)/ra_rb_rr.c \
			$(ACTIONS_path)/rra_rrb_rrr.c $(ACTIONS_path)/sa_sb_ss.c \
			$(SORT_path)/find_optimal.c $(SORT_path)/micro_sort.c \
			$(SORT_path)/quicksort.c $(SORT_path)/stack_helpers.c \
			$(SORT_path)/to_front.c \
			io_utils.c list_utils.c node_utils.c \
			print_utils.c \

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
	mkdir $(OBJ_PATH) $(OBJ_PATH)actions $(OBJ_PATH)sort

clean:
	make clean -C ./libft
	@rm -rf $(OBJ_PATH) $(OBJ_PATH)actions

fclean: clean
	make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re