NAME = account
CC = clang++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -fsanitize=address
RM = rm -rf

DEF_COLOR	= "\033[0;39m"
GRAY		= "\033[0;90m"

FILES = tests \
		Account

SRCS = $(addsuffix .cpp, $(FILES))

all: $(NAME)

$(NAME): $(SRCS)
	@printf $(GRAY)
	$(CC) $(CPP_FLAGS) -o $(NAME) $(SRCS)
	@printf $(DEF_COLOR)

clean:
	$(RM) $(NAME)

re: clean all

fre: fclean all

phony: all clean fclean re
