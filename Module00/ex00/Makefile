NAME		= megaphone

SRC			= megaphone.cpp
OBJ			= $(SRC:cpp=o)
CC			= clang++
FLAGS		= -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all