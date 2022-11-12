SRC = test.c get_next_line.c get_next_line_utils.c

OBJS := $(SRC:%.c=%.o)

all: test

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

test: $(OBJS)
	gcc $(OBJS) -fsanitize=address -o test.out

clean:
	rm -f $(OBJS)