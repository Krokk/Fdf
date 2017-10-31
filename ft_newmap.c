/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:02:52 by rfabre            #+#    #+#             */
/*   Updated: 2017/10/31 10:07:46 by tchapka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

void			get_coord_h(t_mlx *info, int i, int j, int color)
{
	t_xy	a;
	t_xy	b;

	a.x = (((info->coord[i][j].x - info->coord[i][j].y) * SCALE) + 1) + RL;
	a.y = (((info->coord[i][j].z * SZ * SCALE / 40) +
		(info->coord[i][j].x + info->coord[i][j].y) * SCALE) + 1) + UD;
	a.color = info->coord[i][j].color;
	b.x = (((info->coord[i][j + 1].x - info->coord[i][j + 1].y) * SCALE) + 1)
		+ RL;
	b.y = (((info->coord[i][j + 1].z * SZ * SCALE / 40) +
		(info->coord[i][j + 1].x + info->coord[i][j + 1].y) * SCALE) + 1) + UD;
	b.color = info->coord[i][j + 1].color;
	draw_line(info, a, b, color);
}

void			get_coord_v(t_mlx *info, int i, int j, int color)
{
	t_xy	a;
	t_xy	b;

	a.x = (((info->coord[i][j].x - info->coord[i][j].y) * SCALE) + 1) + RL;
	a.y = (((info->coord[i][j].z * SZ * SCALE / 40) +
		(info->coord[i][j].x + info->coord[i][j].y) * SCALE) + 1) + UD;
	a.color = info->coord[i][j].color;
	b.x = (((info->coord[i + 1][j].x - info->coord[i + 1][j].y) * SCALE) + 1)
		+ RL;
	b.y = (((info->coord[i + 1][j].z * SZ * SCALE / 40) +
		(info->coord[i + 1][j].x + info->coord[i + 1][j].y) * SCALE) + 1) + UD;
	b.color = info->coord[i + 1][j].color;
	draw_line(info, a, b, color);
}

void			ft_randmap(t_mlx *info)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	j = 0;
	color = -3;
	while (i < info->lines)
	{
		while (j < info->col)
		{
			if (j + 1 < info->col)
				get_coord_h(info, i, j, color);
			if (i + 1 < info->lines)
				get_coord_v(info, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void			clear_map(t_mlx *info)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	j = 0;
	color = -1;
	while (i < info->lines)
	{
		while (j < info->col)
		{
			if (j + 1 < info->col)
				get_coord_h(info, i, j, color);
			if (i + 1 < info->lines)
				get_coord_v(info, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void			ft_newmap(t_mlx *info)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	j = 0;
	color = -2;
	while (i < info->lines)
	{
		while (j < info->col)
		{
			if (j + 1 < info->col)
				get_coord_h(info, i, j, color);
			if (i + 1 < info->lines)
				get_coord_v(info, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}
