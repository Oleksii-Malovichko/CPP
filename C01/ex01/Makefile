NAME = horde

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(SRCS=.cpp:.o)

all: $(NAME)

$(NAME): Makefile
	@echo "Compiling..."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME) $(OBJS)
	@echo "Ready!"

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all