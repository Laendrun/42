# SRC & OBJS for mandatory functions
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_memchr.c \
	  ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
	  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	  ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS := $(SRC:%.c=%.o)

# SRC & OBJS for bonus functions
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS_BONUS := $(SRC_BONUS:%.c=%.o)

# SRC & OBJS for additionnal functions
SRC_SUP = ft_putchar.c ft_putstr.c ft_putnbr.c ft_strcmp.c ft_strstr.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c
OBJS_SUP := $(SRC_SUP:%.c=%.o)

# "Base" variables
TARGET = libft.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

# Additional variables
RM = rm -f
ARTARGET = ar rcs $(TARGET)
RANTARGET = ranlib $(TARGET)
OBJSA = $(OBJS) $(OBJS_BONUS) $(OBJS_SUP)

# Delete variables
RMTARGET = $(RM) $(TARGET)
RMA = $(RM) $(OBJSA)

# compile .c -> .o
%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

# main rules
all: $(TARGET)

$(TARGET): $(OBJS)
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