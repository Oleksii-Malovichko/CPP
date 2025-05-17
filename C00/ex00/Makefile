NAME=megaphone

CPP=c++
CPP_FLAGS=-Wall -Wextra -Werror -std=c++11
SRCS=megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@echo "Compiling $(NAME)"
	@$(CPP) $(CPP_FLAGS) $(SRCS) -o $(NAME)
	@echo "Ready"

re: clean all

clean:
	@echo "Remove $(NAME)"
	@rm -rf $(NAME)

fclean: clean

.PHONY: all re clean fclean