NAME = fixed
CC = clang++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -Wpedantic -g -fsanitize=address
RM = rm -rf

DEF_COLOR	= "\033[0;39m"
GRAY		= "\033[0;90m"

FILES =	Fixed \
		main \

SRCS = $(addsuffix .cpp, $(FILES))

HDRS = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	@printf $(GRAY)
	$(CC) $(CPP_FLAGS) -o $(NAME) $(SRCS)
	@printf $(DEF_COLOR)

clean:
	@printf $(GRAY)
	$(RM) $(NAME)
	@printf $(DEF_COLOR)

fclean: clean

re: clean all

phony: all clean fclean re
