/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eventmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:03:06 by rfabre            #+#    #+#             */
/*   Updated: 2017/10/31 10:07:43 by tchapka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

static void		ft_freetab(t_mlx *info)
{
	int		i;

	i = 0;
	while (i < info->lines)
	{
		free(info->coord[i]);
		i++;
	}
	free(info->coord);
}

int				ft_event(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_image(((t_mlx*)param)->mlx, ((t_mlx*)param)->img);
		mlx_destroy_window(((t_mlx*)param)->mlx, ((t_mlx*)param)->win);
		ft_freetab(param);
		exit(EXIT_SUCCESS);
	}
	clear_map(param);
	((t_mlx*)param)->sz += (keycode == 13) ? 1 : 0;
	((t_mlx*)param)->sz -= (keycode == 1) ? 1 : 0;
	((t_mlx*)param)->ud -= (keycode == 125) ? 3 : 0;
	((t_mlx*)param)->ud += (keycode == 126) ? 3 : 0;
	((t_mlx*)param)->rl += (keycode == 123) ? 3 : 0;
	((t_mlx*)param)->rl -= (keycode == 124) ? 3 : 0;
	if (keycode == 11)
		init(param);
	ft_newmap(param);
	if (keycode == 49)
		ft_randmap(param);
	return (0);
}

int				ft_mouse_event(int button, int x, int y, void *param)
{
	int		i;
	int		j;

	i = x;
	j = y;
	clear_map(param);
	if (button == 4)
		((t_mlx*)param)->scale += 1;
	if (button == 5)
		((t_mlx*)param)->scale -= 1;
	ft_newmap(param);
	return (0);
}
