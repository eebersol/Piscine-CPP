NAME = easyfind

CC = clang++

FLAGS = -Wall -Wextra -Werror

OBJ_DIR = ./obj/

SRC_DIR = ./srcs/

INCLUDE_DIR = ./includes

FILES = main.cpp\
		span.cpp\

FILES_TTP = Array.tpp\

OBJS = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(FILES))
OBJS_TTP = $(patsubst %.tpp, $(OBJ_DIR_TTP)%.o, $(FILES_TTP))

all: $(NAME)

$(NAME): mkdir_obj assemble $(OBJS)
	@ /bin/echo -n "Archiving object in $(NAME):"
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@ echo " \033[32mAll done!\033[0m"

assemble:
	@ echo "Assembling:"

mkdir_obj:
	@ mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@ /bin/echo -n "    $(notdir $@)"
	@ $(CC) $(FLAGS) -c -o $@ $< -I $(INCLUDE_DIR)
	@ echo " \033[32mOK\033[0m"

$(OBJ_DIR_TTP)%.o: $(SRC_DIR)%.tpp
	@ /bin/echo -n "    $(notdir $@)"
	@ $(CC) $(FLAGS) -c -o $@ $< -I $(INCLUDE_DIR)
	@ echo " \033[32mOK\033[0m"

clean:
	@ /bin/echo -n "Removing object files:"
	@ rm -rf $(OBJ_DIR)
	@ echo " \033[32mdone\033[0m"

fclean: clean
	@ /bin/echo -n "Removing binary:"
	@ rm -rf $(NAME)
	@ echo " \033[32mdone\033[0m"

debug:
	@ $(CC) $(FLAGS) -o $(NAME) $(SRC_DIR)/*.cpp -I $(INCLUDE_DIR) -lncurses -g

re: fclean all

.PHONY: all $(NAME) mkdir_obj assemble clean fclean re
