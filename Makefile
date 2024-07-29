# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 12:20:34 by daspring          #+#    #+#              #
#    Updated: 2024/07/29 12:25:36 by daspring         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# preliminary Makefile

CFLAGS= -wall -werror -wextra -O3

NAME=pipex

$(NAME) : pipex.c
	cc pipex.c -o $(NAME)

all : $(NAME)

fclean :
	@rm -f $(NAME)

re : fclean all

.PHONY=all fclean clean re
