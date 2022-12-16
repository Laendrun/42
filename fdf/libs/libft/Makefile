# SRC & OBJS for mandatory functions
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c  ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c
OBJS := $(SRC:%.c=%.o)

# SRC & OBJS for bonus functions
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS_BONUS := $(SRC_BONUS:%.c=%.o)

# PRINTF SRC
PRINTF_SRC = ft_printf.c ft_print_c.c ft_print_s.c ft_print_d.c ft_print_u.c ft_print_p.c ft_print_x.c

# GNL SRC
GNL_SRC = get_next_line.c

# Additionnal functions
ADD_SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_strcmp.c ft_strstr.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
			ft_memccpy.c ft_strchr.c

# SRC & OBJS for additionnal functions
SRC_SUP = $(ADD_SRC) $(PRINTF_SRC) $(GNL_SRC)
OBJS_SUP := $(SRC_SUP:%.c=%.o)

# "Base" variables
NAME = libft.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

# Additional variables
RM = rm -f
ARTARGET = ar rcs $(NAME)
RANTARGET = ranlib $(NAME)
OBJSA = $(OBJS) $(OBJS_BONUS) $(OBJS_SUP)

TEST_SRC = __test.c
TEST_OUTPUT = test

# Delete variables
RMTARGET = $(RM) $(NAME)
RMA = $(RM) $(OBJSA)

# main rules
all: everything

# compile .c -> .o
%.o: %.c
	$(CC) -I. $(CCFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(ARTARGET) $(OBJS)
	$(RANTARGET)
	
clean:
	@$(RMA)

fclean: clean
	@$(RMTARGET)

re: fclean all

# bonus rules
bonus: $(OBJS) $(OBJS_BONUS)
	$(ARTARGET) $(OBJS) $(OBJS_BONUS)
	$(RANTARGET)

# additional rules
everything: $(OBJSA)
	@$(ARTARGET) $(OBJSA)
	@$(RANTARGET)

clear: fclean 
	clear

test: everything
	$(RM) $(TEST_OUTPUT)
	$(CC) $(CCFLAGS) -L. -lft $(TEST_SRC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT) | cat -e