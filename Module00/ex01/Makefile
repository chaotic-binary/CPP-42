NAME		=	phonebook

SRC_DIR		=	./src/
SRC			=	phonebook.cpp Contact_class.cpp
O_DIR		=	./bin
OBJ			=	$(addprefix $(O_DIR)/, $(SRC:cpp=o))
I_DIR		=	./include
INCLUDES	=	$(addprefix $(I_DIR)/, $(SRC:cpp=hpp))

FLAGS		=	-Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(O_DIR)/%.o:./src/%.cpp $(INCLUDES) | $(O_DIR)
	@clang++ $(FLAGS) -I $(I_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	@clang++ $(FLAGS) -I $(I_DIR) -o $(NAME) $(OBJ)

$(O_DIR):
	@mkdir $(O_DIR)

clean:
	@rm -f $(OBJ)
	@rmdir $(O_DIR)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all