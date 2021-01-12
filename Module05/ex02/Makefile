NAME		=	test

SRC			=	Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp
BIN			=	./bin
OBJ			=	$(addprefix $(BIN)/, $(SRC:cpp=o)) \
				$(addprefix $(BIN)/, $(MAIN:cpp=o))
DEP			=	$(OBJ:%.o=%.d)
INCLUDE		=	$(SRC:cpp=hpp)
MAIN		=	main.cpp
CC			=	clang++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(BIN)/%.o:%.cpp $(INCLUDE) | $(BIN)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

-include $(DEP)

$(BIN):
	@mkdir $(BIN)

clean:
	@rm -rf $(BIN)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all