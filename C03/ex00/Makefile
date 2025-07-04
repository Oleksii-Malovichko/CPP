NAME = and_open

SRCS = main.cpp ClapTrap.cpp
CXX = c++ -std=c++17
CXXFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
