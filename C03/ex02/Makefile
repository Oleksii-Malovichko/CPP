NAME = frag_trap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
CXX = c++ -std=c++17
CXXFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
