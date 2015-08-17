#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/04 10:21:03 by sboudouk          #+#    #+#              #
#    Updated: 2015/06/04 10:21:04 by sboudouk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_SERV = serveur.c 

SRC_CLIENT = client.c

OBJ_SERV = $(SRC_SERV:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

NAME_SERV = launch_serv

NAME_CLIENT = client_exec

FLAGS = -O3 -Wall -Werror -Wextra -I ./includes -I ./libft/includes/

CC = gcc

all: lib $(NAME_SERV) $(NAME_CLIENT)

serv: $(NAME_SERV)
$(NAME_SERV): $(OBJ_SERV)
	@ $(CC) $(FLAGS) $(OBJ_SERV) libft/libft.a -o launch_serv

client: $(NAME_CLIENT)
$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) libft/libft.a -o client_exec

%.o: %.c
	$(CC) $(FLAGS) -c $<

re: cleanlib lib all

clean:
	rm -f $(OBJ_SERV) $(OBJ_CLIENT)

fclean: cleanlib clean
	rm -f $(NAME_SERV) $(NAME_CLIENT)

lib:
	make -C libft

cleanlib:
	make fclean -C libft
