
NAME=a.out

CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS=main.cpp Fix.cpp
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