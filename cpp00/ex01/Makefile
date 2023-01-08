NAME = phonebook

# Directories
OBJ_DIR = objs/

SRC =	main.cpp \
		Contact.cpp \
		PhoneBook.cpp

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ := $(SRC:%.cpp=%.o)

C++FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(C++FLAGS) $^ -o $@

$(OBJ_DIR)%.o: %.cpp
	c++ $(C++FLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all