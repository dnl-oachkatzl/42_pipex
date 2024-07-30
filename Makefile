# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 12:20:34 by daspring          #+#    #+#              #
#    Updated: 2024/07/30 22:17:00 by daspring         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -g

NAME=pipex

$(NAME) : pipex.c
	@cc $(CFLAGS) pipex.c libft/libft.a -o $(NAME)
	@echo "created pipex"

libft/libft.a :
	make -C ./libft/ all

all : $(NAME)

fclean :
	@rm -f $(NAME)
	@echo "removed pipex"

re : fclean all

.PHONY=all fclean clean re
