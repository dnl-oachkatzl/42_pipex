# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 12:20:34 by daspring          #+#    #+#              #
#    Updated: 2024/07/31 14:04:52 by daspring         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wextra -Wall -O3

NAME = pipex

SRCS =	pipex.c \
		pipex_utils.c
OBJS =	$(SRCS:.c=.o)

$(NAME) : $(OBJS) libft/libft.a
	@cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "created pipex"

%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

libft/libft.a :
	@make -C ./libft/ all

all : $(NAME) libft/libft.a
clean :
	@rm -f $(OBJS)
	@echo "removed pipex objects-files"
	@make -C ./libft/ clean
fclean : clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean
	@echo "removed pipex"
re : fclean all

.PHONY=all fclean clean re
