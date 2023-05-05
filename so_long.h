/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:16:44 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/05 07:56:40 by edfirmin         ###   ########.fr       */
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

typedef struct s_test
{
	void	*mlx_ptr;
	void	*window;
	void	*map;
	void	*perso;
	void	*rondin;
}				t_test;

void	ft_bzero(void *s, size_t n);
void	*ft_free(char *str1, char *str2);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	ft_exit(void);



#endif