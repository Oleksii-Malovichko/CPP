NAME = fixed

SRCS = main.cpp Fixed.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

all: $(NAME)

$(NAME): Makefile
	@echo "Compiling..."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Ready!"

clean:
	@echo "Removing $(NAME)"
	@rm -f $(NAME)

fclean: clean

re: clean all