NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++ -std=c++11
CXXFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -DDEBUG


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

debug: CXXFLAGS += $(DEBUGFLAGS)

debug: re

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f output.txt

re: fclean all