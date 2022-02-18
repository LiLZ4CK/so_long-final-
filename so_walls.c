/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:06:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/10 01:23:14 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_test.h"

void	check_newlines(t_jinx *p)
{
	int	i;

	i = 0;
	while (p->dmap[i])
	{
		if (p->dmap[i][0] == '\n')
		{
			ez_exit(i);
		}
		i++;
	}
}

void	walls_x(t_jinx *p, int i, int j)
{
	int	k;

	k = 0;
	i -= 1;
	while (k < j)
	{
		if (p->dmap[0][k] != '1')
		{
			ez_exit(i);
		}
		if (p->dmap[i][k] != '1')
		{
			ez_exit(i);
		}
		k++;
	}
}

void	walls_y(t_jinx *p, int i, int j)
{
	int	k;

	k = 0;
	i -= 1;
	j -= 1;
	while (k < i)
	{
		if (p->dmap[k][0] != '1')
		{
			ez_exit(i);
		}
		if (p->dmap[k][j] != '1')
		{
			ez_exit(i);
		}
		k++;
	}
}

int	wall_check(t_jinx *p, int keycode, int x, int y)
{
	static int	i;
	static int	j;

	i = y / 80;
	j = x / 80;
	if (keycode == 13 || keycode == 126)
		if (p->dmap[i - 1][j] == '1')
			return (0);
	if (keycode == 1 || keycode == 125)
		if (p->dmap[i + 1][j] == '1')
			return (0);
	if (keycode == 0 || keycode == 123)
		if (p->dmap[i][j - 1] == '1')
			return (0);
	if (keycode == 2 || keycode == 124)
		if (p->dmap[i][j + 1] == '1')
			return (0);
	return (1);
}

t_jinx	sub_main(t_jinx *p, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	map_check(argc, argv);
	p->dmap = mapi(argv);
	real_check(p);
	check_newlines(p);
	check_components2(p);
	check_components(p);
	while (p->dmap[i])
	{
		j = 0;
		while (p->dmap[i][j])
			j++;
		i++;
	}
	j = ft_strlen(p->dmap[0]) - 1;
	walls_x(p, i, j);
	walls_y(p, i, j);
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, j * 80, i * 80, "so_long");
	return (*p);
}
