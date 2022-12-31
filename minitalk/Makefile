NAME = minitalk

SRV_SRC = $(addprefix src/, server.c \
							mt_utils.c \
							)
CLT_SRC = $(addprefix src/, client.c \
							mt_utils.c \
							)
SRV_OBJ := $(SRV_SRC:%.c=%.o)
CLT_OBJ := $(CLT_SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Werror -Wall -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iincludes -Ilibft -c $< -o $@

$(NAME): client server

client: $(CLT_OBJ)
	@make -C libft
	$(CC) $^ -Llibft -lft -o $@

server: $(SRV_OBJ)
	@make -C libft
	$(CC) $^ -Llibft -lft -o $@

clean:
	rm -f $(CLT_OBJ) $(SRV_OBJ)

fclean: clean
	rm -f client server
	make fclean -C libft/

re: fclean all

libft:
	@make -C libft/

.PHONY: libft