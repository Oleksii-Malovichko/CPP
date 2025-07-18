NAME = animal

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
CXX = c++ -std=c++11
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all