NAME = zombie

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS = $(SRCS=.cpp:.o)

all: $(NAME)

$(NAME): $(OBJS) Makefile
	@echo "Compiling..."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME) $(OBJS)
	@echo "Ready!"

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: clean fclean re all