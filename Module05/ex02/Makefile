NAME		=	test

SRC			=	Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp
O_DIR		=	./bin
OBJ			=	$(addprefix $(O_DIR)/, $(SRC:cpp=o)) \
				$(addprefix $(O_DIR)/, $(MAIN:cpp=o))
INCLUDE		=	$(SRC:cpp=hpp)
MAIN		=   main.cpp

FLAGS		= -std=c++98 #-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(O_DIR)/%.o:%.cpp | $(O_DIR) $(INCLUDE)
	@clang++ $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@clang++ $(FLAGS) -o $(NAME) $(OBJ)
	@./$(NAME)

$(O_DIR):
	@mkdir $(O_DIR)

clean:
	@rm -rf $(O_DIR)
	@rm ./_tree*
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all