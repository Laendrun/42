SRC = ft_printf.c
SRC_HELPERS = $(addprefix helpers/, ft_putchar.c ft_putnbr.c ft_putunbr.c ft_put_ptr.c ft_put_hex.c)
SRC_PRINTERS = $(addprefix printers/, ft_print_c.c ft_print_s.c ft_print_d.c ft_print_u.c ft_print_p.c ft_print_x.c)

OBJS := $(SRC:%.c=%.o)
OBJS_HELPERS := $(SRC_HELPERS:%.c=%.o)
OBJS_PRINTERS := $(SRC_PRINTERS:%.c=%.o)

NAME = libftprintf.a
CC = gcc
CCFLAGS = -Werror -Wall -Wextra
INC_DIR = .

%.o: %.c
	$(CC) -I$(INC_DIR) $(CCFLAGS) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_HELPERS) $(OBJS_PRINTERS)
	ar rcs $(NAME) $(OBJS) $(OBJS_HELPERS) $(OBJS_PRINTERS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_HELPERS) $(OBJS_PRINTERS)

fclean: clean
	rm -f $(NAME)

re: fclean all

clear: fclean 
	clear

test: all
	gcc $(CCFLAGS) -I. -L. -lftprintf test.c