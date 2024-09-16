NAME = phonebook
CC = @clang++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -fsanitize=address
RM = @rm -rf

FILES = PhoneBook \
		Contact \
		main \

SRCS = $(addsuffix .cpp, $(FILES))

HDRS = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	$(CC) $(CPP_FLAGS) -o $(NAME) $(SRCS)

clean:
	$(RM) $(NAME)

fclean: clean
	 
re: clean all

phony: all clean fclean re