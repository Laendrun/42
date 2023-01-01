NAME = philosophers

SRC = $(addprefix src/, main.c \
						)

OBJ := $(SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Werror -Wall -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iincludes -Ilibft -c $< -o $@

$(NAME): $(OBJ)
	@make -C libft/
	$(CC) $^ -Llibft -lft -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all