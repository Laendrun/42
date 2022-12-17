# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Make

NAME = fdf
SRC = $(addprefix src/, main.c \
						inputs.c \
						utils.c \
						render_utils.c \
						draw.c \
						map_parser.c \
						free.c \
						points.c \
						arrows.c \
						)
OBJ := $(SRC:%.c=%.o)

CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):$(OBJ)
	@echo "$(CYAN)Compiling mlx$(DEF_COLOR)"
	make -C libs/mlx/
	@echo "$(CYAN)Compiling libft$(DEF_COLOR)"
	make -C libs/libft/
	@echo "$(BLUE)Linking all objects files$(DEF_COLOR)"
	gcc $(CCFLAGS) $^ -Llibs/mlx -Llibs/libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)fdf compiled$(DEF_COLOR)"

debug: $(OBJ)
	gcc $(CCFLAGS) -fsanitize=address $^ -Llibs/mlx -Llibs/libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	@echo "$(BLUE)Compiling $@ from $<$(DEF_COLOR)"
	gcc $(CCFLAGS) -Ilibs/libft -Ilibs/mlx -Iincludes -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning mlx$(DEF_COLOR)"
	make clean -C libs/mlx/
	@echo "$(YELLOW)Cleaning libft$(DEF_COLOR)"
	make clean -C libs/libft/
	@echo "$(YELLOW)Cleaning fdf$(DEF_COLOR)"
	rm -f $(OBJ)

clean-fdf:
	@echo "$(YELLOW)Cleaning fdf$(DEF_COLOR)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Deleting mlx.a$(DEF_COLOR)"
	make fclean -C libs/mlx/
	@echo "$(RED)Deleting libft.a$(DEF_COLOR)"
	make fclean -C libs/libft/
	@echo "$(RED)Deleting fdf$(DEF_COLOR)"
	@rm -f $(NAME)

libs:
	@echo "$(BLUE)Compiling MLX$(DEF_COLOR)"
	make -C libs/mlx/
	@echo "$(BLUE)Compiling libft$(DEF_COLOR)"
	make -C libs/libft/
	@echo "$(GREEN)Libraries Compiled.$(DEF_COLOR)"

re: fclean all

.PHONY: libs