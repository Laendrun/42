NAME = philo

SRC = 	main.c \
		utils.c \
		libft.c \
		libft_utils.c

OBJ := $(SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -pthread

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all