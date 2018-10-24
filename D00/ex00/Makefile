# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/08 19:11:03 by eebersol          #+#    #+#              #
#    Updated: 2018/10/02 18:13:24 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program

NAME		= megaphone

CFLAGS		= -Wall -Wextra -Werror

SRC			= megaphone.cpp\

CC 			= clang++ 

OBJ			= $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME)  $(OBJ)
	@echo $(NAME) " : compiled"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJ)
	@echo "Clean all .o files"

fclean:	clean
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: fclean all
 
.PHONY: clean fclean re