/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mouv_utile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:12:02 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/22 14:57:04 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	base_up(t_img *ima)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	j = 0;
	while (ima->smap[j])
	{
		i = 0;
		x = 0;
		while (ima->smap[j][i])
		{
			if (ima->smap[j][i] == 'E')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->exit, x, y);
			if (ima->smap[j][i] == 'P')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->up, x, y);
			x += 50;
			i++;
		}
		y += 50;
		j++;
	}
}

void	base_down(t_img *ima)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	j = 0;
	while (ima->smap[j])
	{
		i = 0;
		x = 0;
		while (ima->smap[j][i])
		{
			if (ima->smap[j][i] == 'E')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->exit, x, y);
			if (ima->smap[j][i] == 'P')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->down, x, y);
			x += 50;
			i++;
		}
		y += 50;
		j++;
	}
}

void	base_left(t_img *ima)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	j = 0;
	while (ima->smap[j])
	{
		i = 0;
		x = 0;
		while (ima->smap[j][i])
		{
			if (ima->smap[j][i] == 'E')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->exit, x, y);
			if (ima->smap[j][i] == 'P')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->left, x, y);
			x += 50;
			i++;
		}
		y += 50;
		j++;
	}
}

void	base_right(t_img *ima)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	j = 0;
	while (ima->smap[j])
	{
		i = 0;
		x = 0;
		while (ima->smap[j][i])
		{
			if (ima->smap[j][i] == 'E')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->exit, x, y);
			if (ima->smap[j][i] == 'P')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->right, x, y);
			x += 50;
			i++;
		}
		y += 50;
		j++;
	}
}

void	base_end(t_img *ima)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	j = 0;
	while (ima->smap[j])
	{
		i = 0;
		x = 0;
		while (ima->smap[j][i])
		{
			if (ima->smap[j][i] == 'E')
				mlx_put_image_to_window(ima->mlx_ptr, ima->window,
					ima->exit, x, y);
			x += 50;
			i++;
		}
		y += 50;
		j++;
	}
	tab_free(ima->smap);
}
