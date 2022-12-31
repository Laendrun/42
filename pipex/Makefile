NAME = pipex

SRC = $(addprefix src/, main.c \
						pipex_utils.c \
						pipex_utils2.c \
						pipex_utils3.c \
						checks.c \
						)

SRC_BON = $(addprefix src/, main_bonus.c \
						pipex_utils_bonus.c \
						pipex_utils2_bonus.c \
						pipex_utils3_bonus.c \
						checks_bonus.c \
						)
OBJ := $(SRC:%.c=%.o)
OBJ_BON := $(SRC_BON:%.c=%.o)

CC = gcc
CCFLAGS = -Werror -Wall -Wextra

all: $(NAME)

libft:
	@make -C libft/

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $^ -Llibft -lft -o $(NAME)

bonus: $(OBJ_BON)
	@make -C libft
	$(CC) $^ -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iincludes -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BON)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

debug: $(OBJ)
	$(CC) $(CCFLAGS) -fsanitize=address -Llibft -lft $^ -o $(NAME)

.PHONY: libft test