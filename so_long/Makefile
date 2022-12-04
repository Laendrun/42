NAME = excutableName
SRC = main.c
OBJ := $(SRC:%.c=%.o)

CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wextra -Wall -Werror $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

# $(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
#	gcc $(CCFLAGS) -Imlx -c $< -o $@
	gcc -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all