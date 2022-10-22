SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_memchr.c \
	  ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
	  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	  ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_SUP = ft_putchar.c ft_putstr.c ft_putnbr.c ft_strcmp.c \
		  ft_strstr.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

TARGET = libft.a
OBJS := $(SRC:%.c=%.o)
OBJS_SUP := $(SRC_SUP:%.c=%.o)
OBJS_BONUS := $(SRC_BONUS:%.c=%.o)

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

RMTARGET = rm -f $(TARGET)
RMOBJS = rm -f $(OBJS)
RMSUP = rm -f $(OBJS_SUP)
RMBONUS = rm -f $(OBJS_BONUS)

ARTARGET = ar rc $(TARGET)
RANTARGET = ranlib $(TARGET)

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(ARTARGET) $(OBJS)
	$(RANTARGET)

sup: $(OBJS) $(OBJS_SUP)
	$(ARTARGET) $(OBJS)
	$(ARTARGET) $(OBJS_SUP)
	$(RANTARGET)

bonus: $(OBJS) $(OBJS_BONUS)
	$(ARTARGET) $(OBJS)
	$(ARTARGET) $(OBJS_BONUS)
	$(RANTARGET)

everything: $(OBJS) $(OBJS_SUP) $(OBJS_BONUS)
	$(ARTARGET) $(OBJS)
	$(ARTARGET) $(OBJS_SUP)
	$(ARTARGET) $(OBJS_BONUS)
	$(RANTARGET)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

clean:
	$(RMOBJS)

clean_sup: clean
	$(RMSUP)

clean_bonus: clean
	$(RMBONUS)

clean_all: clean clean_sup clean_bonus

fclean: clean
	$(RMTARGET)

fclean_sup: clean clean_sup
	$(RMTARGET)

fclean_bonus: clean clean_bonus
	$(RMTARGET)

fclean_all: clean_all
	$(RMTARGET)

re: fclean all

re_all: fclean_all everything

.PHONY: all
