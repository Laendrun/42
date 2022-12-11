NAME = FdF
SRC = $(addprefix src/, keyboard.c main.c utils.c map_parser.c)
LIBFT_SRC = $(addprefix libft/, ft_split.c ft_calloc.c ft_strlen.c ft_atoi.c)
GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)
OBJ := $(SRC:%.c=%.o)
LIBFT_OBJ := $(LIBFT_SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

# MacOs
$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(LIBFT_OBJ)
	gcc $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# MacOs
%.o: %.c
	gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(LIBFT_OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

mlx:
	@$(MAKE) re -C mlx/

re: fclean all