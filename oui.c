
#include "mlx.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int	touch(int key_touch, void *param)
{
	param = NULL;
	if (key_touch == 0)
		ft_putstr("Gauche ");
	if (key_touch == 13)
		ft_putstr("Haut ");
	if (key_touch == 2)
		ft_putstr("Droite ");
	if (key_touch == 1)
		ft_putstr("Bas ");
	return (key_touch);
}

int main(void)
{
	void	*mlx_ptr;
	void	*window; // pour recup. l'ID de la fenetre pour dessiner dedans plus tard
	int		i;
	int		j;

	j = 0;
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 900, 500, "oui");
	while (j <= 500)
	{
		i = 0;
		while (j <= 250 && i <= 900)
		{
			mlx_pixel_put(mlx_ptr, window, i, j, 0x004AFF);
			i++;
		}
		while (j <= 290 && i <= 900)
		{
			mlx_pixel_put(mlx_ptr, window, i, j, 0xFFFFFF);
			i++;
		}
		while (j <= 330 && i <= 900)
		{
			mlx_pixel_put(mlx_ptr, window, i, j, 0xFF0000);
			i++;
		}
		while (j <= 370 && i <= 900)
		{
			mlx_pixel_put(mlx_ptr, window, i, j, 0xFFFFFF);
			i++;
		}
		while (j <= 500 && i <= 900)
		{
			mlx_pixel_put(mlx_ptr, window, i, j, 0x004AFF);
			i++;
		}
		j++;
	}
	mlx_string_put(mlx_ptr, window, 450, 250, 0x004AFF, "667");
	mlx_key_hook(window, touch, NULL);
	mlx_loop(mlx_ptr);
}
