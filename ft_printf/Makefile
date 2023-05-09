# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 13:45:22 by edfirmin          #+#    #+#              #
#    Updated: 2023/04/13 10:18:57 by edfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printchar.c ft_printf.c ft_printhexa_maj.c ft_printhexa_min.c \
ft_printnbr.c ft_printnbrus.c ft_printstr.c ft_printadd.c

FLG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o :
	gcc $(FLG) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
