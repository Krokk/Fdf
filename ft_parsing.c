/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:02:31 by rfabre            #+#    #+#             */
/*   Updated: 2017/10/31 10:07:59 by tchapka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

static void		ft_color(t_data **pos, char **str, int *i, int *j)
{
	if (**str == '0' && *(*str + 1) == 'x')
		*str += 2;
	pos[*i][*j].color = ft_atoi_base(*str, 16);
	*str += 6;
}

static void		ft_col(t_data **pos, char **str, int *i, int *j)
{
	while (**str == ' ' || **str == '\t' || **str == '\n')
		(*str)++;
	if (ft_isdigit(**str) || **str == '-')
		pos[*i][*j].z = ft_atoi(*str);
	if (pos[*i][*j].z > 50000)
		pos[*i][*j].z = 50000;
	if (pos[*i][*j].z < -50000)
		pos[*i][*j].z = -50000;
	pos[*i][*j].x = *j;
	pos[*i][*j].y = *i;
	while (ft_isdigit(**str) || **str == '-')
		(*str)++;
	if (**str == ',')
	{
		(*str)++;
		ft_color(pos, str, i, j);
	}
	else
		pos[*i][*j].color = 0xffffff;
	(*j)++;
}

t_data			**ft_parsing(char *str, t_mlx *info)
{
	t_data		**pos;
	int			i;
	int			j;

	i = 0;
	j = 0;
	pos = NULL;
	check_map(str, &info->col, &info->lines);
	if (!(pos = (t_data**)malloc(sizeof(t_data*) * (info->lines + 1))))
		ft_error(-42);
	while (i < info->lines)
	{
		if (!(pos[i] = (t_data*)malloc(sizeof(t_data) * (info->col + 1))))
			ft_error(-42);
		while (j < info->col)
			ft_col(pos, &str, &i, &j);
		j = 0;
		i++;
	}
	return (pos);
}
