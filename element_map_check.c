/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:08:45 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/04 14:08:59 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count == 0 || size == 0)
	{
		mem = malloc(0);
		return (mem);
	}
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
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
	ft_free(s1, NULL);
	str[i] = '\0';
	return (str);
}

int	valide(char *src, char c)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		if (src[i] == c)
			j++;
		i++;
	}
	return (j);
}

void	valide2(char *str)
{
	if (valide (str, 'P') != 1)
		printf("%s\n", "Error");
	else if (valide (str, 'E') != 1)
		printf("%s\n", "Error");
	else if (valide (str, 'C') == 0)
		printf("%s\n", "Error");
	else
		printf("%s\n", "Tout les element sont la.");
	free(str); //a enlever plus tard
}

void	line(char *buffer, int fd)
{
	char	*str;
	int		i;

	str = ft_calloc(2, sizeof(char));
	buffer = ft_calloc(sizeof(char), 1);
	if (!str || !buffer)
	{
		ft_free(buffer, str);
		return ;
	}
	i = 1;
	while (i == 1)
	{
		ft_bzero(str, 1);
		i = read(fd, str, 1);
		if (i == 0)
			break ;
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	valide2(buffer);
}

void main_fonc(int fd)
{
	char		*buffer;

	if (fd == -1)
		return ;
	line(buffer, fd);
}

int main(void)
{
	int	fd;

	fd = open("yep.ber", O_RDONLY);
	main_fonc(fd);
	system("leaks a.out");
}