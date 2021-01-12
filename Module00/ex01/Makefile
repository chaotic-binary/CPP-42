NAME		=	phonebook

SRC_DIR		=	./src/
SRC			=	phonebook.cpp Contact_class.cpp
BIN			=	./bin
OBJ			=	$(addprefix $(BIN)/, $(SRC:cpp=o))
DEP			= 	$(OBJ:%.o=%.d)
I_DIR		=	./include
INCLUDE		=	$(addprefix $(I_DIR)/, $(SRC:cpp=hpp))
CC			=	clang++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(BIN)/%.o:./src/%.cpp $(INCLUDES) | $(BIN)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(BIN):
	@mkdir $(BIN)

-include $(DEP)

clean:
	@rm -rf $(BIN)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all