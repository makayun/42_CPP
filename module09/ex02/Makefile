NAME	:= PmergeMe
CC		:= c++
RM		:= rm -rf
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

DEF_COLOR	:= "\033[0;39m"
GRAY		:= "\033[0;90m"

FILES := main \
		PmergeMe \
		FJVector \
		FJDeque \


SRCS = $(addsuffix .cpp, $(FILES))

HDRS = $(wildcard *hpp)

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	@printf $(GRAY)
	$(CC) $(CPP_FLAGS) -o $(NAME) $(SRCS)
	@printf $(DEF_COLOR)

clean:
	@printf $(GRAY)
	$(RM) $(NAME) *.dSYM
	@printf $(DEF_COLOR)

fclean: clean

re: clean all

debug: CPP_FLAGS += -DDEBUG
debug: re

fast: CPP_FLAGS += -Ofast
fast: re

safe: CPP_FLAGS += -g -fsanitize=address
safe: re

.PHONY: all clean fclean re
