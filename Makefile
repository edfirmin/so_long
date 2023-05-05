# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 14:29:28 by edfirmin          #+#    #+#              #
#    Updated: 2023/05/05 08:17:22 by edfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = element_map_check.c utile1.c utile2.c

FLG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o :
	@gcc $(FLG) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc -I /usr/local/include $(FLG) $(OBJ) -L /usr/local/ -lmlx -framework OpenGl -framework AppKit -o $(NAME)
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all