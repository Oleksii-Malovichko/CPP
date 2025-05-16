NAME = violence

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): Makefile
	@echo "Compiling..."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Ready!"

clean:
	@echo "Remove $(NAME)"
	@rm -rf $(NAME)

fclean: clean

re: clean all
