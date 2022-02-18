/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:45:52 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/10 02:15:44 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_test.h"

char	*player_banania(int keycode)
{
	char	*up;
	char	*down;
	char	*left;
	char	*right;

	up = "./img/banania_up.xpm";
	down = "./img/banania_down.xpm";
	left = "./img/banania_left.xpm";
	right = "./img/banania_right.xpm";
	if (keycode == 13 || keycode == 126)
		return (up);
	if (keycode == 1 || keycode == 125)
		return (down);
	if (keycode == 0 || keycode == 123)
		return (left);
	if (keycode == 2 || keycode == 124)
		return (right);
	return (down);
}

int	spawny(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

t_vi	spawn_p(t_jinx *p, t_vi *q)
{
	q->xx = 0;
	q->yy = 0;
	while (q->xx == 0)
	{
		q->xx = spawny(p->dmap[q->yy], 'P');
		q->yy++;
	}
	q->yy--;
	q->xx *= 80;
	q->yy *= 80;
	return (*q);
}

int	check_close(int keycode, t_jinx *p, int x, int y)
{
	if (mapchr(p, 'C') == 0)
		open_door(p);
	if ((mapchr(p, 'C') <= 0 && exit_block(p, keycode, x, y))
		|| keycode == 12 || keycode == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(1);
		return (0);
	}
	return (0);
}

void	open_door(t_jinx *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->dmap[i])
	{
		j = 0;
		while (p->dmap[i][j])
		{
			if (p->dmap[i][j] == 'E')
			{
				draw_map1(p, "./img/open_door.xpm", j * 80, i * 80);
				j++;
			}
			j++;
		}
		i++;
	}
}
