/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:16:44 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/16 17:43:42 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "lib/libft.h"
#include "mlx.h"
#include "ft_printf/ft_printf.h"

typedef struct s_img
{
	void *mlx_ptr;
	char **smap;
	void *window;
	void *map;
	void *up;
	void *down;
	void *left;
	void *right;
	void *wall;
	void *colec;
	void *exit;
	char *mapp;
	int m;
} t_img;

typedef struct s_int
{
	int x;
	int y;
	int fd;
	int n_colec;
} t_int;

void *ft_free(char *str1, char *str2);
void ft_exit(int i);
void map_close(char *str);
void map_rect(char *str);
void map_elem(char *str);
void map_no_elem(char *buffer);
void map_road(char *str);
char *map_check(int fd);
int lon_cont(char *str);
int len_cont(char *str);
int nb_colec(char **str);
void base(void *mlx_ptr, void *window, void *map, char *str);
int event_check(int x, int y, int n, t_img *param);
void base2(t_img *ima);
void base3(t_img *ima);
void base_up(t_img *ima);
void base_down(t_img *ima);
void base_left(t_img *ima);
void base_right(t_img *ima);
void base_end(t_img *ima);
int up_mouv(t_img *param, int y, int n);
int down_mouv(t_img *param, int y, int n);
int right_mouv(t_img *param, int x, int n);
int left_mouv(t_img *param, int x, int n);
void end_mouv(t_img *param);
int event_check(int x, int y, int n, t_img *param);
int init_val(char **smap, int x, int y);
int init_val2(char **smap, int x, int y);

#endif