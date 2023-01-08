NAME = megaphone

SRC = main.cpp

OBJ := $(SRC:%.cpp=%.o)

C++FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(C++FLAGS) main.o -o $@

%.o: %.cpp
	c++ $(C++FLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all