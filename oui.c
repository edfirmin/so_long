
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	touch(int key_touch, void *param)
{
	void	*mlx_ptr;
	t_img	oui;
	int		la;
	int		lo;
	int		img_la;
	int		img_lo;
	static int		x;
	static int		y;
	static int		c;

	if (!x || !y || !c)
	{
		c = 0;
		printf ("%s\n", ft_itoa(c));
		x = 440;
		y = 200;
	}
	mlx_ptr = mlx_init();
	oui.perso = mlx_xpm_file_to_image(mlx_ptr, "perso.xpm", &lo, &la);
	oui.map = mlx_xpm_file_to_image(oui.mlx_ptr, "map.xpm", &img_lo, &img_la);
	if (key_touch == 53)
		exit(0);
	if (key_touch == 0 || key_touch == 123)
	{
		if (x - 30 >= 0)
		{
			c++;
			printf("%s\n", ft_itoa(c));
			x -= 30;
		}
		mlx_clear_window(mlx_ptr, param);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.map, 0, 0);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.perso, x, y);
		mlx_string_put(mlx_ptr, param, 910, 20, 0xFFFFFF, ft_strjoin("Score: ", ft_itoa(c)));
		//ft_putstr("Gauche ");
	}
	if (key_touch == 13 || key_touch == 126)
	{
		if (y - 30 >= 0)
		{
			c++;
			printf("%s\n", ft_itoa(c));
			y -= 30;
		}
		mlx_clear_window(mlx_ptr, param);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.map, 0, 0);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.perso, x, y);
		mlx_string_put(mlx_ptr, param, 910, 20, 0xFFFFFF, ft_strjoin("Score: ", ft_itoa(c)));
		//ft_putstr("Haut ");
	}
	if (key_touch == 2 || key_touch == 124)
	{
		if (x + 30 <= 994)
		{
			c++;
			printf("%s\n", ft_itoa(c));
			x += 30;
		}
		mlx_clear_window(mlx_ptr, param);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.map, 0, 0);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.perso, x, y);
		mlx_string_put(mlx_ptr, param, 910, 20, 0xFFFFFF, ft_strjoin("Score: ", ft_itoa(c)));
		//ft_putstr("Droite ");
	}
	if (key_touch == 1 || key_touch == 125)
	{
		if (y + 30 <= 738)
		{
			c++;
			printf("%s\n", ft_itoa(c));
			y += 30;
		}
		mlx_clear_window(mlx_ptr, param);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.map, 0, 0);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.perso, x, y);
		mlx_string_put(mlx_ptr, param, 910, 20, 0xFFFFFF, ft_strjoin("Score: ", ft_itoa(c)));
		//ft_putstr("Bas ");
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_img	ima;
	t_int	val;
	char	*map;

	map = NULL;
	val.fd = -1;
	if (argc == 2)
	{
		if (ft_strstr(argv[1], ".ber"))
			val.fd = open(argv[1], O_RDONLY);
		else
			ft_exit(9);
		map = map_check(val.fd);
	}
	else
		ft_exit(8);
	ima.smap = ft_split(map, '\n');
	ima.mlx_ptr = mlx_init();
	ima.window = mlx_new_window(ima.mlx_ptr, len_cont(map) * 50, lon_cont(map) * 50, "oui");
	ima.map = mlx_xpm_file_to_image(ima.mlx_ptr, "map.xpm", &val.img_lo, &val.img_la);
	ima.wall = mlx_xpm_file_to_image(ima.mlx_ptr, "wall.xpm", &val.f, &val.g);
	ima.perso = mlx_xpm_file_to_image(ima.mlx_ptr, "perso.xpm", &val.x, &val.y);
	ima.colec = mlx_xpm_file_to_image(ima.mlx_ptr, "colec.xpm", &val.i, &val.j);
	ima.exit = mlx_xpm_file_to_image(ima.mlx_ptr, "exit.xpm", &val.a, &val.b);
	base(ima.mlx_ptr, ima.window, ima.map, map);
	base2(&ima);
	mlx_loop(ima.mlx_ptr);
 }
