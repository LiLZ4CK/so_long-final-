/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mapa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:28:07 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/10 01:22:32 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_test.h"

int	check_components(t_jinx *p)
{
	if (mapchr(p, 'C') < 1)
	{
		ft_printf("need at least one collectible");
		exit(EXIT_FAILURE);
	}
	if (mapchr(p, 'E') < 1)
	{
		ft_printf("need at least one exit");
		exit(EXIT_FAILURE);
	}
	if (mapchr(p, '0') < 1)
	{
		ft_printf("need at least one free space");
		exit(EXIT_FAILURE);
	}
	if (mapchr(p, 'P') != 1)
	{
		ft_printf("need one player");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	check_components2(t_jinx *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->dmap[i])
	{
		j = 0;
		while (p->dmap[i][j])
		{
			if (p->dmap[i][j] != '0' && p->dmap[i][j]
			!= 'E' && p->dmap[i][j] != '1'
			&& p->dmap[i][j] != 'P' && p->dmap[i][j]
			!= 'C' && p->dmap[i][j] != '\n'
			&& p->dmap[i][j] != '\0')
			{
				ez_exit(i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	putfloor(t_jinx *p, int x, int y)
{
	char	*path;

	path = "./img/free.xpm";
	p->free_path = mlx_xpm_file_to_image(p->mlx_ptr, path, &p->w, &p->h);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->free_path, x, y);
	return (0);
}

int	exit_block(t_jinx *p, int keycode, int x, int y)
{
	static int	i;
	static int	j;

	i = y / 80;
	j = x / 80;
	if (keycode == 13 || keycode == 126)
		if (p->dmap[i - 1][j] == 'E')
			return (1);
	if (keycode == 1 || keycode == 125)
		if (p->dmap[i + 1][j] == 'E')
			return (1);
	if (keycode == 0 || keycode == 123)
		if (p->dmap[i][j - 1] == 'E')
			return (1);
	if (keycode == 2 || keycode == 124)
		if (p->dmap[i][j + 1] == 'E')
			return (1);
	return (0);
}

int	check_collec(t_jinx *p, int x, int y)
{
	int	c;

	c = 0;
	x /= 80;
	y /= 80;
	if (p->dmap[y][x] == 'C')
	{
		p->dmap[y][x] = '0';
		c++;
	}
	return (c);
}
