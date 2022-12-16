NAME = push_swap

SRC = $(addprefix src/, main.c)
OBJ := $(SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	$(CC) $^ -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iincludes -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
	make re -C libft/

debug: $(OBJ)
	$(CC) $(CCFLAGS) -fsanitize=address -Llibft -lft $^ -o $(NAME)

.PHONY: libft