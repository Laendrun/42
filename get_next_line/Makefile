SRC = test.c get_next_line.c get_next_line_utils.c
SRC_BONUS = test.c get_next_line_bonus.c get_next_line_utils_bonus.c
#SRC = get_next_line.c get_next_line_utils.c

OBJS := $(SRC:%.c=%.o)
BONUS_OBJS := $(SRC_BONUS:%.c=%.o)

NAME = get_next_line

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

bonus: $(BONUS_OBJS)
	gcc $(BONUS_OBJS) -o $(NAME)

test: $(BONUS_OBJS)
	gcc $(BONUS_OBJS) -o test.out

.PHONY: test