NAME = philo

SRC = 	main.c \
		utils.c \
		init.c \
		routine.c \
		routine_utils.c

HELPERS = $(addprefix helpers/,	ft_atoi.c \
								ft_isspace.c \
								ft_putstr_fd.c \
								ft_strlen.c \
								)

OBJ := $(SRC:%.c=%.o)
HELP_OBJ := $(HELPERS:%.c=%.o)

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -pthread

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -I. -c $< -o $@

$(NAME): $(OBJ) $(HELP_OBJ)
	$(CC) $^ -o $@

debug: $(OBJ) $(HELP_OBJ)
	$(CC) -fsanitize=address $^ -o $(NAME)

clean:
	rm -f $(OBJ) $(HELP_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all