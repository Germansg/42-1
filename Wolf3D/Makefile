#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 17:28:23 by sboudouk          #+#    #+#              #
#    Updated: 2015/04/29 17:35:54 by sboudouk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = wolf3d.c gnl/get_next_line.c

OBJ = $(SRC:.c=.o)

NAME = Wolf3D

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: lib $(OBJ)
    $(CC) $(FLAGS) $(SRC) libft/libft.a -o $(NAME)

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
    make -C libft re
