/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:12:13 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/10 01:21:47 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_test.h"

int	mapchr(t_jinx *p, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (p->dmap[i])
	{
		j = 0;
		while (p->dmap[i][j])
		{
			if (p->dmap[i][j] == c)
			{
				n++;
			}
			j++;
		}
		i++;
	}
	return (n);
}

void	draw_map(t_jinx *p)
{
	int	x;
	int	y;

	y = 0;
	while (p->dmap[y / 80])
	{
		x = 0;
		while (p->dmap[y / 80][x / 80])
		{
			if (p->dmap[y / 80][x / 80] == '1')
				x = draw_map1(p, "./img/wall.xpm", x, y);
			if (p->dmap[y / 80][x / 80] == '0')
				x = draw_map1(p, "./img/free.xpm", x, y);
			if (p->dmap[y / 80][x / 80] == 'C')
				x = draw_map1(p, "./img/collect.xpm", x, y);
			if (p->dmap[y / 80][x / 80] == 'E')
				x = draw_map1(p, "./img/hodor.xpm", x, y);
			if (p->dmap[y / 80][x / 80] == 'P')
				x = draw_map1(p, "./img/start_banania.xpm", x, y);
			if (p->dmap[y / 80][x / 80] == '\n')
				x += 80;
		}
		y += 80;
	}
}

int	draw_map1(t_jinx *p, char *path, int x, int y)
{
	p->compos = mlx_xpm_file_to_image(p->mlx_ptr, path, &p->w, &p->h);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->compos, x, y);
	x += 80;
	return (x);
}

int	map_check(int argc, char **argv)
{
	int		i;
	int		len;
	char	*ber;

	i = 0;
	ber = ".ber";
	len = ft_strlen(argv[1]) - 4;
	if (argc == 2)
	{
		while (argv[1][len] == ber[i])
		{
			len++;
			i++;
			if (!argv[1][len] && !ber[i])
				return (1);
			if (argv[1][len] != ber[i])
			{
				ez_exit(i);
			}
		}
	}
	ez_exit(i);
	return (0);
}

int	ez_exit(int i)
{
	i = 1;
	ft_printf("error : invalid map !\n");
	exit (EXIT_FAILURE);
	return (0);
}
