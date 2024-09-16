NAME = megaphone
CC1 = clang++
CC2 = g++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -fsanitize=address
RM = rm -rf

FILES = megaphone

SRCS = $(addsuffix .cpp, $(FILES))

HDRS = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	$(CC2) $(CPP_FLAGS) -o $(NAME) $(SRCS)
	$(RM) $(NAME)
	$(CC1) $(CPP_FLAGS) -o $(NAME) $(SRCS)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJS)
	 
re: clean all

fre: fclean all

phony: all clean fclean re fre