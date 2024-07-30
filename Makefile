# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 12:20:34 by daspring          #+#    #+#              #
#    Updated: 2024/07/30 15:32:19 by daspring         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# preliminary Makefile

CFLAGS= -wall -werror -wextra -O3

NAME=pipex

$(NAME) : pipex.c
	@cc pipex.c -o $(NAME)
	@echo "created pipex"

all : $(NAME)

fclean :
	@rm -f $(NAME)
	@echo "removed pipex"

re : fclean all

.PHONY=all fclean clean re
