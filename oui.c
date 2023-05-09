
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	touch(int key_touch, void *param)
{
	void	*mlx_ptr;
	t_test	oui;
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

int	len_cont(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	lon_cont(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int main(int argc, char **argv)
{
	t_test	oui;
	int		img_lo;
	int		img_la;
	int		len;
	int		lon;
	int		i;
	int		j;
	int		fd;
	char	*map;
	char	**smap;
	int		x;
	int		y;
	int		a;
	int		b;
	int		f;
	int		g;
	int		o;
	int		p;
	int		w;
	int		z;
	int		u;

	map = NULL;
	fd = -1;
	if (argc == 2)
	{
		if (ft_strstr(argv[1], ".ber"))
			fd = open(argv[1], O_RDONLY);
		else
			ft_exit(9);
		map = map_check(fd);
	}
	else
		ft_exit(8);
	len = len_cont(map);
	lon = lon_cont(map);
	smap = ft_split(map, '\n');
	oui.mlx_ptr = mlx_init();
	oui.window = mlx_new_window(oui.mlx_ptr, len * 50, lon * 50, "oui");
	oui.map = mlx_xpm_file_to_image(oui.mlx_ptr, "map.xpm", &img_lo, &img_la);
	oui.wall = mlx_xpm_file_to_image(oui.mlx_ptr, "wall.xpm", &f, &g);
	oui.perso = mlx_xpm_file_to_image(oui.mlx_ptr, "perso.xpm", &x, &y);
	oui.colec = mlx_xpm_file_to_image(oui.mlx_ptr, "colec.xpm", &i, &j);
	oui.exit = mlx_xpm_file_to_image(oui.mlx_ptr, "exit.xpm", &a, &b);
	z = 0;
	w = 0;
	u = len;
	while (lon > 0)
	{
		len = u;
		w = 0;
		while (len > 0)
		{
			mlx_put_image_to_window(oui.mlx_ptr, oui.window, oui.map, w, z);
			w += 50;
			len--;
		}
		lon--;
		z += 50;
	}
	z = 0;
	o = 0;
	while (smap[o])
	{
		p = 0;
		w = 0;
		while (smap[o][p])
		{
			if (smap[o][p] == '1')
				mlx_put_image_to_window(oui.mlx_ptr, oui.window, oui.wall, w, z);
			if (smap[o][p] == 'C')
				mlx_put_image_to_window(oui.mlx_ptr, oui.window, oui.colec, w, z);
			if (smap[o][p] == 'E')
				mlx_put_image_to_window(oui.mlx_ptr, oui.window, oui.exit, w, z);
			if (smap[o][p] == 'P')
				mlx_put_image_to_window(oui.mlx_ptr, oui.window, oui.perso, w, z);
			w +=50;
			p++;
		}
		z += 50;
		o++;
	}
	mlx_loop(oui.mlx_ptr);
 }
