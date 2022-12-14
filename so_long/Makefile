NAME = so_long
SRC = $(addprefix src/, main.c utils.c draw.c map_parser.c path_checker.c game_utils.c map_parser_utils.c free.c)
GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)
OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):$(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	gcc $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

debug: $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	gcc $(CCFLAGS) -fsanitize=address $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

mlx:
	@$(MAKE) re -C mlx/

re: fclean all