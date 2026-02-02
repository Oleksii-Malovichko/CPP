NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Ready"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Remove $(OBJS)"
	@rm -f $(OBJS)

fclean: clean
	@echo "Remove $(NAME)"
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re