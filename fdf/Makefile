NAME = fdf
SRC = $(addprefix src/, main.c)
OBJ := $(SRC:%.c=%.o)

CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):$(OBJ)
	gcc $(CCFLAGS) $^ -Llibs/mlx -Llibs/libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

debug: $(OBJ)
	gcc $(CCFLAGS) -fsanitize=address $^ -Llibs/mlx -Llibs/libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc $(CCFLAGS) -Ilibs/libft -Ilibs/mlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C libs/mlx/
	make clean -C libs/libft/
	rm -f $(NAME)

libs:
	make -C libs/mlx/
	make -C libs/libft/

re: fclean all

.PHONY: libs