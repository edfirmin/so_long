
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

t_img	init(t_img	ima, char *map);

int	touch(int key_touch, t_img	*param)
{
	static int	x;
	static int	y;	

	if (!x && !y)
	{
		y = 0;
		while (param->smap[y])
		{
			x = 0;
			while (param->smap[y][x])
			{
				if (param->smap[y][x] == 'P')
					break ;
				x++;
			}
			if (param->smap[y][x] == 'P')
				break ;
			y++;
		}
	}
	if (key_touch == 13)
	{
		ft_printf("haut ");
		mlx_put_image_to_window(param->mlx_ptr, param->window, param->perso, x*50, y*50 - 50);
		y -= 1;
	}
	if (key_touch == 1)
	{
		ft_printf("bas ");
		mlx_put_image_to_window(param->mlx_ptr, param->window, param->perso, x*50, y*50 +50);
		y +=1;
	}
	if (key_touch == 0)
	{
		ft_printf("gauche ");
		mlx_put_image_to_window(param->mlx_ptr, param->window, param->perso, x*50 - 50, y*50);
		x -=1;
	}
	if (key_touch == 2)
	{
		ft_printf("droite ");
		mlx_put_image_to_window(param->mlx_ptr, param->window, param->perso, x*50 + 50, y*50);
		x +=1;
	}
	if (key_touch == 53)
		exit(0);
	return (0);
}

t_img	init(t_img	ima, char *map)
{
	t_int	val;

	ima.smap = ft_split(map, '\n');
	ima.mlx_ptr = mlx_init();
	ima.window = mlx_new_window(ima.mlx_ptr, len_cont(map) * 50,
			lon_cont(map) * 50, "oui");
	ima.map = mlx_xpm_file_to_image(ima.mlx_ptr, "map.xpm",
			&val.img_lo, &val.img_la);
	ima.wall = mlx_xpm_file_to_image(ima.mlx_ptr, "wall.xpm", &val.f, &val.g);
	ima.perso = mlx_xpm_file_to_image(ima.mlx_ptr, "perso.xpm", &val.x, &val.y);
	ima.colec = mlx_xpm_file_to_image(ima.mlx_ptr, "colec.xpm", &val.i, &val.j);
	ima.exit = mlx_xpm_file_to_image(ima.mlx_ptr, "exit.xpm", &val.a, &val.b);
	return (ima);
}

int main(int argc, char **argv)
{
	t_img	ima;
	t_int	val;

	val.fd = -1;
	ima.map = NULL;
	if (argc == 2)
	{
		if (ft_strstr(argv[1], ".ber"))
			val.fd = open(argv[1], O_RDONLY);
		else
			ft_exit(9);
		ima.mapp = map_check(val.fd);
	}
	else
		ft_exit(8);
	ima = init(ima, ima.mapp);
	val.n_colec = nb_colec(ima.smap);
	base(ima.mlx_ptr, ima.window, ima.map, ima.mapp);
	base2(ima);
	base3(ima);
	mlx_hook(ima.window, 2, 0, touch, &ima);
	mlx_loop(ima.mlx_ptr);
}
