NAME = harl

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Harl.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
