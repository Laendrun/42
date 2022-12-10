NAME = so_long
SRC = main.c utils.c draw.c map_parser.c path_checker.c
GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)
OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

# MacOs
$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	gcc $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

# Linux
#$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
#	gcc $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# MacOs
%.o: %.c
	gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

# Linux
#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Iincludes -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all