NAME = so_long
SRC = $(addprefix src/, main.c utils.c draw.c map_parser.c path_checker.c game_utils.c map_parser_utils.c free.c)
GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)
OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)
LI-OBJ := $(SRC:%.c=li-%.o)
LI-GNL_OBJ := $(SRC:%.c=li-%.o)
LI-PRINTF_OBJ := $(SRC:%.c=li-%.o)

CCFLAGS = -Wextra -Wall -Werror

all: macos

macos: $(NAME)-macos

linux: $(NAME)-linux

# MacOs
$(NAME)-macos:$(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	gcc $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

debug: $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	gcc $(CCFLAGS) -fsanitize=address $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Linux
$(NAME)-linux: $(LI-OBJ) $(LI-GNL_OBJ) $(LI-PRINTF_OBJ)
	gcc $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# MacOs
%.o: %.c
	gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

# Linux
li-%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Iincludes -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(LI-OBJ) $(LI-GNL_OBJ) $(LI-PRINTF_OBJ)

fclean: clean
	make clean -C mlx/
	make clean -C mlx_linux/
	rm -f $(NAME)

mlx:
	@$(MAKE) re -C mlx/

mlx_linux:
	@$(MAKE) re -C mlx_linux/

re: fclean all