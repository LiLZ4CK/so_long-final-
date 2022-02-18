/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:37:42 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/10 17:18:08 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_test.h"

int	ft_move_y(int keycode, t_jinx *p, int x, int y)
{
	if (keycode == 125 || keycode == 1)
	{
		p->p_path = player_banania(keycode);
		putfloor(p, x, y);
		y += 80;
		p->player = mlx_xpm_file_to_image(p->mlx_ptr, p->p_path, &p->w, &p->h);
		putfloor(p, x, y);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	if (keycode == 126 || keycode == 13)
	{
		p->p_path = player_banania(keycode);
		putfloor(p, x, y);
		y -= 80;
		p->player = mlx_xpm_file_to_image(p->mlx_ptr, p->p_path, &p->w, &p->h);
		putfloor(p, x, y);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	return (y);
}

int	ft_move_x(int keycode, t_jinx *p, int x, int y)
{
	if (keycode == 124 || keycode == 2)
	{
		p->p_path = player_banania(keycode);
		putfloor(p, x, y);
		x += 80;
		p->player = mlx_xpm_file_to_image(p->mlx_ptr, p->p_path, &p->w, &p->h);
		putfloor(p, x, y);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	if (keycode == 123 || keycode == 0)
	{
		p->p_path = player_banania(keycode);
		putfloor(p, x, y);
		x -= 80;
		p->player = mlx_xpm_file_to_image(p->mlx_ptr, p->p_path, &p->w, &p->h);
		putfloor(p, x, y);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	return (x);
}

int	ft_mouve(int keycode, t_jinx *p)
{
	static int	x;
	static int	y;
	static int	i;
	t_vi		q;

	if (i == 0)
	{
		q = spawn_p(p, &q);
		x = q.xx;
		y = q.yy;
		i++;
	}
	check_collec(p, x, y);
	if (!(wall_check(p, keycode, x, y))
		|| (mapchr(p, 'C') > 0 && exit_block(p, keycode, x, y)))
		return (0);
	check_close(keycode, p, x, y);
	if (keycode == 124 || keycode == 2 || keycode == 123 || keycode == 0)
		x = sub_move_x(keycode, x, y, p);
	if (keycode == 125 || keycode == 1 || keycode == 126 || keycode == 13)
		y = sub_move_y(keycode, x, y, p);
	if (keycode == 124 || keycode == 2 || keycode == 123 || keycode == 0
		|| keycode == 125 || keycode == 1 || keycode == 126 || keycode == 13)
		ft_printf("your move is : %d\n", i++);
	return (0);
}

int	sub_move_x(int keycode, int x, int y, t_jinx *p)
{
	if (wall_check(p, keycode, x, y))
	{
		if (keycode == 124 || keycode == 2 || keycode == 123 || keycode == 0)
		{
			x = ft_move_x(keycode, p, x, y);
		}
	}
	return (x);
}

int	sub_move_y(int keycode, int x, int y, t_jinx *p)
{
	if (wall_check(p, keycode, x, y))
	{
		if (keycode == 125 || keycode == 1 || keycode == 126 || keycode == 13)
		{
			y = ft_move_y(keycode, p, x, y);
		}
	}
	return (y);
}
