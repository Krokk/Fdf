/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 09:01:11 by rfabre            #+#    #+#             */
/*   Updated: 2017/10/31 10:08:07 by tchapka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init(t_mlx *info)
{
	info->scale = SIZESCALE;
	info->sz = SIZESZ;
	info->ud = 0;
	info->rl = 500;
}

void		fdf(char *str)
{
	t_mlx		info;
	ft_bzero(&info, sizeof(t_mlx));
	info.coord = ft_parsing(str, &info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WINX, WINY, "FDF !");
	info.img = mlx_new_image(info.mlx, IMAGEX, IMAGEY);
	info.data = mlx_get_data_addr(info.img, &info.bpp, &info.sl, &info.endian);
	init(&info);
	ft_newmap(&info);
	mlx_hook(info.win, 2, 3, ft_event, &info);
	mlx_mouse_hook(info.win, ft_mouse_event, &info);
	mlx_loop(info.mlx);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*tab;

	if (ac < 2)
		ft_error(-1);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error(-1);
	tab = ft_strnew(0);
	while ((get_next_line(fd, &line)) > 0)
	{
		tab = ft_freejoinstr(tab, line);
		tab = ft_freejoinstr(tab, "\n");
	}
	if (*tab == '\0' || *tab == '\n')
		ft_error(-1);
	fdf(tab);
	return (0);
}
