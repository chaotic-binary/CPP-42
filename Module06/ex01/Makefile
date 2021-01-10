NAME		= test

SRC			= main.cpp serialize.cpp
OBJ			= $(SRC:cpp=o)
INC			= serialize.hpp

FLAGS		= -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

%.o:%.c $(INC)
	@clang++ $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@clang++ $(FLAGS) -o $(NAME) $(OBJ)
	./$(NAME)

clean:
	@rm -f $(OBJ)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all
