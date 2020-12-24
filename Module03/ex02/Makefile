NAME		=	test

SRC			=	FragTrap.cpp ScavTrap.cpp ClapTrap.cpp
O_DIR		=	./bin
OBJ			=	$(addprefix $(O_DIR)/, $(SRC:cpp=o)) \
				$(addprefix $(O_DIR)/, $(MAIN:cpp=o))
INCLUDE		=	$(SRC:cpp=hpp)
MAIN		=   main.cpp

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
	@rm -f $(OBJ)
	@rmdir $(O_DIR)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all