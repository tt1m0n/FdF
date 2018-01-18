# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:55 by omakovsk          #+#    #+#              #
#    Updated: 2018/01/16 17:08:48 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -c

SRC = read.c rotate.c main.c brez_alg.c draw_map.c

OBJ	= $(SRC:.c=.o)

all: $(addprefix ../objects/,$(OBJ))

../objects/%.o: %.c
	@gcc $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo src object deleted

fclean: clean

re: fclean all


.PHONY: clean fclean all re
