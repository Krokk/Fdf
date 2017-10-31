/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchapka <tchapka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:04:44 by tchapka           #+#    #+#             */
/*   Updated: 2017/10/31 10:06:10 by tchapka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WINX 500
# define WINY 500
# define IMAGEX 1000
# define IMAGEY 1000

typedef	struct		s_data
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_data;

typedef struct		s_mlx
{
	t_data			**coord;
	int				lines;
	int				col;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				sl;
	int				bpp;
	int				endian;
	int				scale;
	int				sz;
	int				ud;
	int				rl;
}					t_mlx;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bresenham;

typedef struct		s_xy
{
	int				x;
	int				y;
	int				color;
}					t_xy;

# define SCALE info->scale
# define SZ info->sz
# define UD info->ud
# define RL info->rl
# define SIZESCALE 5
# define SIZESZ 1

void				check_map(char *str, int *nl, int *nc);
t_data				**ft_parsing(char *str, t_mlx *info);
void				ft_error(int i);
int					ft_event(int keycode, void *param);
int					ft_mouse_event(int button, int x, int y, void *param);
void				draw_line(t_mlx *info, t_xy a, t_xy b, int color);
int					ft_put_color(t_xy a, t_xy b);
void				get_coord_h(t_mlx *info, int i, int j, int color);
void				get_coord_v(t_mlx *info, int i, int j, int color);
void				init(t_mlx *info);
void				ft_menu(t_mlx *info);
void				clear_map(t_mlx *info);
void				ft_newmap(t_mlx *info);
void				ft_randmap(t_mlx *info);

#endif
