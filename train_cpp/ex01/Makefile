NAME = prog

CXX = c++

SRCS = main.cpp Animal.cpp

all: $(NAME)

$(NAME): Makefile
	$(CXX) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: clean all