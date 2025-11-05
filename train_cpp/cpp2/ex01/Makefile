NAME = fixed

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp Fixed.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all