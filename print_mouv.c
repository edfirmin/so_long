/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:04:10 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/22 15:32:31 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_mouv(t_img *param, int y, int n)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_up(param);
	ft_printf("%d\n", n);
	y -= 1;
	return (y);
}

int	down_mouv(t_img *param, int y, int n)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_down(param);
	ft_printf("%d\n", n);
	y += 1;
	return (y);
}

int	left_mouv(t_img *param, int x, int n)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_left(param);
	ft_printf("%d\n", n);
	x -= 1;
	return (x);
}

int	right_mouv(t_img *param, int x, int n)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_right(param);
	ft_printf("%d\n", n);
	x += 1;
	return (x);
}

void	end_mouv(t_img *param)
{
	mlx_clear_window(param->mlx_ptr, param->window);
	base(param->mlx_ptr, param->window, param->map, param->mapp);
	base2(param);
	base_end(param);
	ft_printf("%d\n", param->m);
	ft_free(NULL, param->mapp);
	exit (0);
}
