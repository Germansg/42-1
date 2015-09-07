#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/14 19:36:55 by sboudouk          #+#    #+#              #
#    Updated: 2015/03/25 15:29:47 by sboudouk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ft_sh1.c ft_readentry.c ft_envmanage.c ft_utilities.c ft_list_to_array.c ft_errors.c ft_util2.c

OBJ = $(SRC:.c=.o)

NAME = ft_minishell1

FLAGS = -Wall -Werror -Wextra

CC = clang


all: lib $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(FLAGS) $(OBJ) libft/libft.a -o ft_minishell1

%.o: %.c
	$(CC) $(FLAGS) -c $<

re: cleanlib lib all

clean:
	rm -f $(OBJ)

fclean: cleanlib clean
	rm -f $(NAME)

lib:
	make -C libft

cleanlib:
	make fclean -C libft
