/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:16:44 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/11 12:38:20 by edfirmin         ###   ########.fr       */
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
# include "mlx.h"
# include "ft_printf/ft_printf.h"

typedef struct s_img
{
	void	*mlx_ptr;
	char	**smap;
	void	*window;
	void	*map;
	void	*perso;
	void	*wall;
	void	*colec;
	void	*exit;
}				t_img;

typedef struct s_int
{
	int		i;
	int		j;
	int		img_lo;
	int		img_la;
	int		x;
	int		y;
	int		a;
	int		b;
	int		f;
	int		g;
	int		len;
	int		lon;
	int		fd;
}				t_int;
void	*ft_free(char *str1, char *str2);
void	ft_exit(int i);
void	map_close(char *str);
void	map_rect(char *str);
void	map_elem(char *str);
void	map_no_elem(char *buffer);
void	map_road(char *str);
char	*map_check(int fd);
int		lon_cont(char *str);
int		len_cont(char *str);
void	base(void *mlx_ptr, void *window, void *map, char *str);
void	base2(t_img *ima);


#endif