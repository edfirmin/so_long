/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:04:10 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/16 16:02:12 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_mouv(t_img *param, int y, int n)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_up(param);
	mlx_string_put(param->mlx_ptr, param->window, 0, 0, 0xFFFFFF, ft_itoa(n));
	y -= 1;
	return (y);
}

int	down_mouv(t_img *param, int y, int n)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_down(param);
	mlx_string_put(param->mlx_ptr, param->window, 0, 0, 0xFFFFFF, ft_itoa(n));
	y += 1;
	return (y);
}

int	left_mouv(t_img *param, int x, int n)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_left(param);
	mlx_string_put(param->mlx_ptr, param->window, 0, 0, 0xFFFFFF, ft_itoa(n));
	x -= 1;
	return (x);
}

int	right_mouv(t_img *param, int x, int n)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_right(param);
	mlx_string_put(param->mlx_ptr, param->window, 0, 0, 0xFFFFFF, ft_itoa(n));
	x += 1;
	return (x);
}

void	end_mouv(t_img *param)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_end(param);
	mlx_string_put(param->mlx_ptr, param->window, 0, 0, 0xFFFFFF, ft_itoa(param->m));
	exit (0);
}
