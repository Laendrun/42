NAME     = push_swap

SRC      = $(addprefix src/, main.c)
OBJ     := $(SRC:%.c=%.o)

CC       = gcc
CCFLAGS  = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iincludes -c $< -o $@