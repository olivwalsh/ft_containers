# Colors
RED				= "\033[1;31m"
GREEN			= "\033[1;32m"
RESET			= "\033[m"
BLUE			= \033[1;34m
END				= \e[0m

# Variables
NAME			=	ft_container
REAL_BIN		=	std_container
CXX				=	c++ -std=c++98 -g3
CXXFLAGS		=	-Wall -Wextra -Werror

OBJ_DIR			=	obj/
CONTAINERS_DIR	= 	containers/
UTILS_DIR		= 	$(addprefix $(CONTAINERS_DIR), utils/)
ITERATOR_DIR	=	$(addprefix $(UTILS_DIR), iterator/)
SRC_DIR			= 	mains/

SRC				=	erase.cpp utils.cpp
OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

HEADERS			=	$(addprefix $(UTILS_DIR), type_traits.hpp) \
					$(addprefix $(CONTAINERS_DIR), vector.hpp, stack.hpp)

INC				=	-I./$(UTILS_DIR) -I./$(ITERATOR_DIR) -I./$(CONTAINERS_DIR)

ifeq ($(DMEM),1)
CXXFLAGS 		+= -fsanitize=address -fno-omit-frame-pointer -g3
endif

ifeq ($(REAL),1)
CXXFLAGS		+= -DREAL=1
endif

all: $(NAME)

diff:
	make re
	make re NAME=std_container REAL=1
	@echo "Checking diff between ft and std"
	@./$(NAME) 2>/dev/null 1>ft
	@./$(REAL_BIN) 2>/dev/null 1>std
	@DIFF=$$(diff ft std >/dev/null 2>&1; echo $$?) ; \
	export DIFF ; \
	$(MAKE) check_diff

check_diff:
ifeq ($(DIFF),0)
	@echo ${GREEN}"OK - ft and std output are the same"${RESET}
else
	@echo ${RED}"KO - ft and std differ"${RESET}
endif

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	@mkdir -p ${@D}
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@
	@printf	"\033[2K\r${BLUE}[Building - $<] $(END)\n"

$(NAME): $(OBJ)
	@printf "Compiling $(NAME)"; \
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@; \
	echo $(GREEN) " OK" $(RESET)

clean:
	@echo " ... Deleting obj folder"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo " ... Deleting binary and output files"
	@rm -f $(NAME)
	@rm -f $(REAL_BIN)
	@rm -f ft
	@rm -f std

re: clean fclean all

.PHONY: re clean fclean