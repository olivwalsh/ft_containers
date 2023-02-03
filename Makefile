# Colors
RED				= "\033[1;31m"
GREEN			= "\033[1;32m"
RESET			= "\033[m"

# Variables
NAME			=	ft_container
CXX				=	c++ -std=c++98
CXXFLAGS		=	-Wall -Wextra -Werror

OBJ_DIR			=	obj/
CONTAINERS_DIR	= 	containers/
UTILS_DIR		= 	utils/
SRC_DIR			= 	tests/

OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
SRC				=	vector.cpp

HEADERS			=	$(addprefix $(UTILS_DIR), type_traits.hpp) \
					$(addprefix $(CONTAINERS_DIR), vector.hpp, stack.hpp)

INC				=	-I./$(UTILS_DIR) -I./$(CONTAINERS_DIR)

ifeq ($(DMEM),1)
CXXFLAGS 		+= -fsanitize=address -fno-omit-frame-pointer -g3
endif

ifeq ($(REAL),1)
CXXFLAGS		+= -DREAL=1
endif

all: $(NAME)
	./$(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	mkdir -p ${@D}
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@echo -n "Compiling " $(NAME)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@echo ${GREEN}"\tOK"${RESET}

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: re clean fclean