# Colors
RED			= "\033[1;31m"
GREEN		= "\033[1;32m"
RESET		= "\033[m"

# Variables
NAME		=	ft_container
CXX			=	c++
FCXXLAGS	=	-Wall -Wextra -Werror

SRC			=	test.cpp
OBJ			=	$(addprefix $(OBJDIR), $(SRC:.cpp=.o))
OBJDIR		=	obj/

VECTOR_DIR	= vector/
UTILS_DIR	= utils/

HEADERS		=	$(addprefix $(UTILS_DIR), type_traits.hpp) \
				$(addprefix $(VECTOR_DIR), vector.hpp)

INC			=	-I $(UTILS_DIR) -I $(VECTOR_DIR)

all: $(NAME) 

$(OBJDIR)%.o : %.cpp
	mkdir -p ${@D}
	$(CXX) $(CXXLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@echo -n "Compiling " $(NAME)
	@$(CXX) $(CXXLAGS) $(OBJ) $(MINILIBX) -o $@
	@echo ${GREEN}"\tOK"${RESET}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: re clean fclean