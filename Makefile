SRCS = $(wildcard *.c)

OBJ = $(SRCS:.c=.o)
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
