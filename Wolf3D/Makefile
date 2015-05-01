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

SRC = wolf3d.c sdl_manage.c

OBJ = $(SRC:.c=.o)

NAME = wolf3d

FLAGS = -Wall -Werror -Wextra -I ./includes -I ./includes/SDL2 -I ./libft/includes/

CC = gcc


all: lib $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(FLAGS) $(OBJ) libft/libft.a SDL/libSDL2-2.0.0.dylib -o wolf3d

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
