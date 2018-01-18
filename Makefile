# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:39 by omakovsk          #+#    #+#              #
#    Updated: 2018/01/16 17:22:31 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
OBJ =  objects/*.o
LIBNAME = objects/libftfdf.a
FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): objectdir
	@make -C libft
	@make -C src
	@ar rc $(LIBNAME) $(OBJ)
	@gcc $(FLAGS) $(LIBNAME) -o $(NAME) 
	@echo "\033[35m --------- fdf ready ------------\033[0m"

objectdir:
	@mkdir -p objects

clean:
	@make clean -C libft
	@make clean -C src
	@rm -rf objects

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m --------------fdf deleted--------------\033[0m"

re: fclean all

.PHONY: clean all fclean re
