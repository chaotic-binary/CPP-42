NAME		= pony

SRC			= Pony.cpp main.cpp
OBJ			= $(SRC:cpp=o)
INC			= Pony.hpp

FLAGS		= -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

%.o:%.c $(INC)
	@clang++ $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@clang++ $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all