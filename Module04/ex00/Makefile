NAME		=	test

SRC			=	Sorcerer.cpp, Victim.cpp, Peon.cpp
O_DIR		=	./bin
OBJ			=	$(addprefix $(O_DIR)/, $(SRC:cpp=o)) \
				$(addprefix $(O_DIR)/, $(MAIN:cpp=o))
INCLUDE		=	$(SRC:cpp=hpp)
MAIN		=	main.cpp

FLAGS		= -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(O_DIR)/%.o:%.cpp $(INCLUDE) | $(O_DIR)
	@clang++ $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@clang++ $(FLAGS) -o $(NAME) $(OBJ)

$(O_DIR):
	@mkdir $(O_DIR)

clean:
	@rm -rf $(O_DIR)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all