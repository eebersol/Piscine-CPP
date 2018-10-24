# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/08 19:11:03 by eebersol          #+#    #+#              #
#    Updated: 2018/10/03 12:45:58 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program

NAME		= replace

CFLAGS		= -Wall -Wextra -Werror

SRC			= replace.cpp\

CC 			= clang++ 

OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(NAME) " : compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJ)
	@echo "Clean all .o files"

fclean:	clean
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: fclean all
 
.PHONY: clean fclean re