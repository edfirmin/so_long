
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (str)
	{
		while (s1[++j])
			str[i++] = s1[j];
		j = -1;
		while (s2[++j])
			str[i++] = s2[j];
	}
	str[i] = '\0';
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

static int	size_str(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				i;
	char			*str;

	i = size_str(n);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	str = malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (0);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

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
		mlx_destroy_window(mlx_ptr, param);
	if (key_touch == 0 || key_touch == 123)
	{
		if (x - 30 >= 0)
		{
			c++;
			x -= 30;
		}
		mlx_clear_window(mlx_ptr, param);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.map, 0, 0);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.perso, x, y);
		mlx_string_put(mlx_ptr, param, 925, 20, 0xFFFFFF, ft_strjoin("Score: ", ft_itoa(c)));
		printf("%s\n", ft_itoa(c));
		//ft_putstr("Gauche ");
	}
	if (key_touch == 13 || key_touch == 126)
	{
		if (y - 30 >= 0)
		{
			c++;
			y -= 30;
		}
		mlx_clear_window(mlx_ptr, param);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.map, 0, 0);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.perso, x, y);
		mlx_string_put(mlx_ptr, param, 925, 20, 0xFFFFFF, ft_strjoin("Score: ", ft_itoa(c)));
		printf("%s\n", ft_itoa(c));
		//ft_putstr("Haut ");
	}
	if (key_touch == 2 || key_touch == 124)
	{
		if (x + 30 <= 994)
		{
			c++;
			x += 30;
		}
		mlx_clear_window(mlx_ptr, param);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.map, 0, 0);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.perso, x, y);
		mlx_string_put(mlx_ptr, param, 925, 20, 0xFFFFFF, ft_strjoin("Score: ", ft_itoa(c)));
		printf("%s\n", ft_itoa(c));
		//ft_putstr("Droite ");
	}
	if (key_touch == 1 || key_touch == 125)
	{
		if (y + 30 <= 738)
		{
			c++;
			y += 30;
		}
		mlx_clear_window(mlx_ptr, param);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.map, 0, 0);
		mlx_put_image_to_window(oui.mlx_ptr, param, oui.perso, x, y);
		mlx_string_put(mlx_ptr, param, 925, 20, 0xFFFFFF, ft_strjoin("Score: ", ft_itoa(c)));
		printf("%s\n", ft_itoa(c));
		//ft_putstr("Bas ");
	}
	return (1);
}

int main(void)
{
	t_test	oui;
	int		img_lo;
	int		img_la;
	int		lo;
	int		la;
	int		i;

	i = 0;
	oui.mlx_ptr = mlx_init();
	oui.window = mlx_new_window(oui.mlx_ptr, 1024, 768, "oui");
	oui.map = mlx_xpm_file_to_image(oui.mlx_ptr, "map.xpm", &img_lo, &img_la);
	mlx_put_image_to_window(oui.mlx_ptr, oui.window, oui.map, 0, 0);
	mlx_string_put(oui.mlx_ptr, oui.window, 925, 20, 0xFFFFFF, "Score:");
	oui.perso = mlx_xpm_file_to_image(oui.mlx_ptr, "perso.xpm", &lo, &la);
	mlx_put_image_to_window(oui.mlx_ptr, oui.window, oui.perso, 440, 200);
	if (i == 1)
		mlx_clear_window(oui.mlx_ptr, oui.window);
	mlx_hook(oui.window, 2, 0, touch, oui.window);
	mlx_loop(oui.mlx_ptr);
}
