NAME = ft_retro

CC = clang++

FLAGS = -Wall -Wextra -Werror

OBJ_DIR = ./obj/

SRC_DIR = ./srcs/

INCLUDE_DIR = ./includes

FILES = main.cpp \
			Game.class.cpp \
			Map.class.cpp \
			Square.class.cpp\
			Asteroid.class.cpp \
			AEntity.class.cpp \
			SpaceShips.class.cpp \
			Heroes.class.cpp \
			Enemy.class.cpp \
			Bullet.class.cpp \
			Wave.class.cpp \
			Weapon.class.cpp \
			Obstacle.class.cpp \
			Background.class.cpp \
			SpaceBackground.class.cpp

OBJS = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(FILES))

all: $(NAME)

$(NAME): mkdir_obj assemble $(OBJS)
	@ /bin/echo -n "Archiving object in $(NAME):"
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJS) -lncurses
	@ echo " \033[32mAll done!\033[0m"

assemble:
	@ echo "Assembling:"

mkdir_obj:
	@ mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
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
