# gcc -Iincludes -L. -lftprintf -Werror -Wextra -Wall -fsanitize=address test.c

# SRC & OBJS for mandatory functions
SRC = main.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_strstr.c ft_strlen.c ft_putstr_fd.c ft_lstlast.c \
	ft_get_flags.c ft_isflag.c
OBJS := $(SRC:%.c=%.o)

# SRC & OBJS for bonus functions
SRC_BONUS = 
OBJS_BONUS := $(SRC_BONUS:%.c=%.o)

# SRC & OBJS for additionnal functions
SRC_SUP = 
OBJS_SUP := $(SRC_SUP:%.c=%.o)

# "Base" variables
NAME = libftprintf.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
INC_DIR = includes

# Additional variables
RM = rm -f
ARTARGET = ar rcs $(NAME)
RANTARGET = ranlib $(NAME)
OBJSA = $(OBJS) $(OBJS_BONUS) $(OBJS_SUP)

# Delete variables
RMTARGET = $(RM) $(NAME)
RMA = $(RM) $(OBJSA)

# compile .c -> .o
%.o: %.c
	$(CC) -I$(INC_DIR) $(CCFLAGS) -o $@ -c $?

# main rules
all: $(NAME)

$(NAME): $(OBJS)
	$(ARTARGET) $(OBJS)
	$(RANTARGET)
	
clean:
	$(RMA)

fclean: clean
	$(RMTARGET)

re: fclean all

# bonus rules
bonus: $(OBJS) $(OBJS_BONUS)
	$(ARTARGET) $(OBJS) $(OBJS_BONUS)
	$(RANTARGET)

# additional rules
everything: $(OBJSA)
	$(ARTARGET) $(OBJSA)
	$(RANTARGET)

clear: fclean 
	clear