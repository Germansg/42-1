#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/14 19:36:55 by sboudouk          #+#    #+#              #
#    Updated: 2015/03/11 08:26:32 by sboudouk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ft_sh1.c ft_readentry.c ft_envmanage.c ft_utilities.c ft_sh1.h ft_list_to_array.c ft_errors.c ft_util2.c

OBJ = $(SRC:.c=.o)

NAME = ft_minishell1

FLAGS = -Wall -Werror -Wextra -I libft/ -L libft/includes

CC = gcc

all: lib $(OBJ)
	$(CC) $(FLAGS) $(SRC) libft/libft.a

$(NAME): all

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

re: relib fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lib:
	make -C libft

relib:
	make -C
