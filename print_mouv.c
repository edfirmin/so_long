/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:04:10 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/16 13:05:48 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_mouv(t_img *param, int y, int n)
{
	ft_printf("%d\n", n);
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_up(param);
	y -= 1;
	return (y);
}

int	down_mouv(t_img *param, int y, int n)
{
	ft_printf("%d\n", n);
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_down(param);
	y += 1;
	return (y);
}

int	left_mouv(t_img *param, int x, int n)
{
	ft_printf("%d\n", n);
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_left(param);
	x -= 1;
	return (x);
}

int	right_mouv(t_img *param, int x, int n)
{
	ft_printf("%d\n", n);
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_right(param);
	x += 1;
	return (x);
}
