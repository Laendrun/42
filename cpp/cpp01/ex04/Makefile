NAME = sed

# Directories
OBJ_DIR = objs/

SRC =	main.cpp \

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ := $(SRC:%.cpp=%.o)

C++FLAGS = -Wall -Wextra -Werror -std=c++98
#

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	c++ $(C++FLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp
	c++ $(C++FLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)