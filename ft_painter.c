/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_painter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:02:44 by rfabre            #+#    #+#             */
/*   Updated: 2017/10/31 10:07:54 by tchapka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

static void			set_pixel(t_mlx *info, int x, int y, int color)
{
	int	i;

	if (x >= IMAGEX || x < 0 || y >= IMAGEY || y < 0)
		return ;
	i = info->sl * y + x * 4;
	info->data[i] = color & 0xff;
	info->data[++i] = color >> 8 & 0xff;
	info->data[++i] = color >> 16;
}

static void			init_bre(t_bresenham *brhm, t_xy a, t_xy b)
{
	brhm->dx = abs(b.x - a.x);
	brhm->sx = a.x < b.x ? 1 : -1;
	brhm->dy = abs(b.y - a.y);
	brhm->sy = a.y < b.y ? 1 : -1;
	brhm->err = (brhm->dx > brhm->dy ? brhm->dx : -brhm->dy) / 2;
	brhm->e2 = brhm->err;
}

void				draw_line(t_mlx *info, t_xy a, t_xy b, int color)
{
	t_bresenham		brhm;

	init_bre(&brhm, a, b);
	if (color == -1)
		a.color = 0;
	// if (color == -3)
	// 	a.color = ft_randcol(a);
	while (1)
	{
		set_pixel(info, a.x, a.y, a.color);
		if (a.x == b.x && a.y == b.y)
			break ;
		brhm.e2 = brhm.err;
		if (brhm.e2 > -brhm.dx)
		{
			brhm.err -= brhm.dy;
			a.x += brhm.sx;
		}
		if (brhm.e2 < brhm.dy)
		{
			brhm.err += brhm.dx;
			a.y += brhm.sy;
		}
	}
}
