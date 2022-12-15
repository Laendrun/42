NAME = libftmatrices.a
CC = gcc
CCFLAGS = -Wextra -Wall -Werror

SRC = $(addprefix src/, ft_create_matrix.c \
						ft_free_matrix.c \
						ft_matmul.c \
						ft_matrix_to_vec2.c \
						ft_matrix_to_vec3.c \
						ft_print_matrix.c \
						ft_print_vector2.c \
						ft_print_vector3.c \
						ft_scale_vector2.c \
						ft_scale_vector3.c \
						ft_vec2_to_matrix.c \
						ft_vec3_to_matrix.c \
						)
OBJ := $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) -I. $(CCFLAGS) -o $@ -c $?

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
