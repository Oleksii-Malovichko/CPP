NAME = fixed

SRCS = main.cpp Fixed.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): Makefile
	@echo "Compiling..."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Ready!"

clean:
	@echo "Removing the $(NAME)"
	@rm -rf $(NAME)

fclean: clean

re: clean all