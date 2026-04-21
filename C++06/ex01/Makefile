
NAME=serialization

CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -Iincludes -std=c++11

SRC_DIR = ./srcs
OBJ_DIR = ./object

SRCS_FILES = main.cpp Serializer.cpp

SRCS =	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all:$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.SECONDARY: $(OBJS)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
