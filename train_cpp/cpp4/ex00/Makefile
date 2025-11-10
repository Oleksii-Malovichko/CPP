NAME = animal

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all