
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 21:25:51 by sboudouk          #+#    #+#              #
#    Updated: 2015/01/26 18:31:43 by sboudouk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = fdf.c fdf_2.c fdf_3.c gnl/get_next_line.c

OBJ = $(SRC:.c=.o)

NAME = fdf

FLAGS = -Wall -Werror -Wextra -L/usr/X11/lib -lmlx -lXext -lX11 -g

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
