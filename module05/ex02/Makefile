NAME = bureaucrats
CC = c++
CPP_FLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98 -pedantic -g -fsanitize=address
RM = rm -rf

DEF_COLOR	= "\033[0;39m"
GRAY		= "\033[0;90m"

FILES = Bureaucrat \
		AForm \
		PresidentialPardonForm \
		RobotomyRequestForm \
		ShrubberyCreationForm \
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
	$(RM) $(NAME)* *_shrubbery
	@printf $(DEF_COLOR)

fclean: clean

re: clean all

phony: all clean fclean re
