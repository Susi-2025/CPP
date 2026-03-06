
NAME=Polymor

CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++17

SRCS=main.cpp Animal.cpp WrongAnimal.cpp
OBJS=$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *.replace

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re