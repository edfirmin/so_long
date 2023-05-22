# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edilson <edilson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 14:29:28 by edfirmin          #+#    #+#              #
#    Updated: 2023/05/22 15:33:54 by edilson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = map_check.c utile1.c check_close_map.c check_elem.c check_no_elem.c \
check_rect.c check_road.c so_long.c print_map.c print_mouv_utile.c \
print_mouv.c utile2.c

FLG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o :
	@gcc $(FLG) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	cd lib ; make
	cd ft_printf ; make
	@gcc -I /usr/local/include $(FLG) $(OBJ) lib/libft.a ft_printf/libftprintf.a -L /usr/local/ -lmlx -framework OpenGl -framework AppKit -o $(NAME)
clean :
	@rm -f $(OBJ)
	cd lib ; make clean
	cd ft_printf ; make clean

fclean : clean
	@rm -f $(NAME)
	cd lib ; make fclean
	cd ft_printf ; make fclean

re : fclean all