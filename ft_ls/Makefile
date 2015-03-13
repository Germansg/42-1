#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/15 16:14:51 by sboudouk          #+#    #+#              #
#    Updated: 2015/01/16 11:41:28 by sboudouk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ft_check_options.c ft_list_dir.c get_files.c ft_listdir.c ft_display.c ft_setting.c ft_get_arglist.c ft_recurse.c ft_sort_ar.c ft_sort_rt.c ft_bonus.c ft_display_l.c tools.c ft_sorting2.c ft_freellist.c ft_finalrainbow.c

OBJ = $(SRC:.c=.o)

NAME = ft_ls

FLAGS = -Wall -Werror -Wextra -I libft/ -L libft/includes/

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
