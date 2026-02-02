CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

PROJECTS := $(wildcard C*/ex*)

all: $(PROJECTS)
	@echo "All projects built."

$(PROJECTS):
	$(MAKE) -C $@

clean:
	for d in $(PROJECTS); do $(MAKE) -C $$d clean; done

fclean:
	for d in $(PROJECTS); do $(MAKE) -C $$d fclean; done

re: fclean all

.PHONY: all clean fclean re $(PROJECTS)