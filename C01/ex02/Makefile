NAME = output

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra

SRCS = main.cpp

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Ready"

clean:
	@echo "remove $(NAME)"
	@rm -rf $(NAME)

fclean: clean

re: clean all