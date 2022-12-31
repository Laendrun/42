NAME = minitalk

SRC = $(addprefix src/, client.c \
						server.c \
						)
						
OBJ := $(SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Werror -Wall -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iincludes -Ilibft -c $< -o $@

$(NAME): client server

client: src/client.o
	@make -C libft
	$(CC) $< -Llibft -lft -o $@

server: src/server.o
	@make -C libft
	$(CC) $< -Llibft -lft -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

libft:
	@make -C libft/

.PHONY: libft