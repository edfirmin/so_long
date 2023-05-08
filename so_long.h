/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:16:44 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/08 17:45:19 by edfirmin         ###   ########.fr       */
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

typedef struct s_test
{
	void	*mlx_ptr;
	void	*window;
	void	*map;
	void	*perso;
	void	*rondin;
}				t_test;

void	*ft_free(char *str1, char *str2);
void	ft_exit(void);
void	map_close(char *str);
void	map_rect(char *str);
void	map_elem(char *str);
void	map_no_elem(char *buffer);
void	map_road(char *str);

#endif