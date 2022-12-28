NAME = push_swap

SRC = $(addprefix src/, main.c \
						ps_list_1.c \
						ps_list_2.c \
						ps_list_3.c \
						debug.c \
						utils.c \
						utils2.c \
						ps_swap.c \
						ps_push.c \
						ps_rotate.c \
						ps_rev_rotate.c \
						small_sort.c \
						big_sort.c \
						check.c \
						normalize.c \
						sort_utils.c \
						)
OBJ := $(SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Werror -Wall -Wextra

all: $(NAME)

libft:
	@make -C libft/

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $^ -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iincludes -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

debug: $(OBJ)
	$(CC) $(CCFLAGS) -fsanitize=address -Llibft -lft $^ -o $(NAME)

.PHONY: libft