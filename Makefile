# Colors
RED			= "\033[1;31m"
GREEN		= "\033[1;32m"
RESET		= "\033[m"

# Variables
NAME		=	ft_container
CXX			=	c++ -std=c++98
CXXFLAGS	=	-Wall -Wextra -Werror

SRC			=	test.cpp
OBJ			=	$(addprefix $(OBJDIR), $(SRC:.cpp=.o))
OBJDIR		=	obj/

VECTOR_DIR	= vector/
UTILS_DIR	= utils/

HEADERS		=	$(addprefix $(UTILS_DIR), type_traits.hpp) \
				$(addprefix $(VECTOR_DIR), vector.hpp)

INC			=	-I./$(UTILS_DIR) -I./$(VECTOR_DIR)

ifeq ($(DMEM),1)
CXX 			+= -fsanitize=address -fno-omit-frame-pointer -g3
endif

ifeq ($(REAL),1)
CXXFLAGS	+= -DREAL=1
endif

all: $(NAME)
	./$(NAME)

$(OBJDIR)%.o : %.cpp
	mkdir -p ${@D}
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	@echo -n "Compiling " $(NAME)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@echo ${GREEN}"\tOK"${RESET}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: re clean fclean