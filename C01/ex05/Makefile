NAME = complain

SRCS = main.cpp Harl.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

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