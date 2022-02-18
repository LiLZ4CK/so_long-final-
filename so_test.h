/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:06:38 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/10 20:04:13 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_TEST_H
# define SO_TEST_H

# include	"mlx.h"
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<errno.h>
# include	<string.h>
# include	"get_next_line.h"
# include	"ft_printf.h"

typedef struct t_jinx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*compos;
	void	*new_img;
	char	*p_path;
	char	*free_path;
	char	**dmap;
	int		w;
	int		h;
	int		len;

}	t_jinx;

typedef struct vi
{
	int		xx;
	int		yy;

}	t_vi;

int		map_check(int argc, char **argv);
int		ft_mouve(int keycode, t_jinx *p);
int		mouse(int keycode, t_jinx *p);
int		check_components(t_jinx *p);
void	draw_map(t_jinx *p);
int		check_components2(t_jinx *p);
int		keep_map(t_jinx *p);
int		putfloor(t_jinx *p, int x, int y);
int		wall_check(t_jinx *p, int keycode, int x, int y);
int		spawny(char *s, char c);
int		check_collec(t_jinx *p, int x, int y);
int		exit_block(t_jinx *p, int keycode, int x, int y);
int		mapchr(t_jinx *p, char c);
int		spawny(char *str, char c);
char	*player_banania(int keycode);
int		draw_map1(t_jinx *p, char *path, int x, int y);
int		collect_count(t_jinx *p, int i, int j);
int		count_x(char **argv);
int		ez_exit(int i);
char	**mapi(char **argv);
t_jinx	sub_main(t_jinx *p, int argc, char **argv);
int		sub_move_x(int keycode, int x, int y, t_jinx *p);
int		sub_move_y(int keycode, int x, int y, t_jinx *p);
int		check_close(int keycode, t_jinx *p, int x, int y);
t_vi	spawn_p(t_jinx *p, t_vi *q);
int		the_print(t_jinx *p, int i);
void	check_newlines(t_jinx *p);
void	open_door(t_jinx *p);
void	real_check(t_jinx *p);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	walls_x(t_jinx *p, int i, int j);
void	walls_y(t_jinx *p, int i, int j);

#endif