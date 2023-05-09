/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:16:44 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/09 15:04:04 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "lib/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_test
{
	void	*mlx_ptr;
	void	*window;
	void	*map;
	void	*perso;
	void	*wall;
	void	*colec;
	void	*exit;
	int		k;
	int		l;
}				t_test;

void	*ft_free(char *str1, char *str2);
void	ft_exit(int i);
void	map_close(char *str);
void	map_rect(char *str);
void	map_elem(char *str);
void	map_no_elem(char *buffer);
void	map_road(char *str);
char	*map_check(int fd);

#endif