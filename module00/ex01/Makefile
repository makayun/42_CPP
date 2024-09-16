NAME = phonebook
CC = @clang++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -fsanitize=address
RM = @rm -rf

DEF_COLOR	= "\033[0;39m"
GRAY		= "\033[0;90m"

FILES = PhoneBook \
		Contact \
		main \

SRCS = $(addsuffix .cpp, $(FILES))

HDRS = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	@printf $(GRAY)
	$(CC) $(CPP_FLAGS) -o $(NAME) $(SRCS)
	@printf $(DEF_COLOR)

clean:
	$(RM) $(NAME)

fclean: clean

re: clean all

phony: all clean fclean re
