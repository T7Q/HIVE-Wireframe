/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_buff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:44:35 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 15:38:58 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

void		ft_clean_zbuff(t_fdf *fdf)
{
	int row;
	int col;

	row = 0;
	while (row < WIN_HEIGHT)
	{
		col = 0;
		while (col < WIN_WIDTH)
		{
			fdf->zbuff.pixel[row][col].z = -1000;
			col++;
		}
		row++;
	}
}

void		ft_init_buff(t_fdf *fdf)
{
	int	row;
	int	col;

	if (!(fdf->zbuff.pixel = (t_coord **)malloc(sizeof(t_coord **) *\
															WIN_HEIGHT)))
		ft_puterror("Error: memory allocation\n", 4);
	row = 0;
	while (row < WIN_HEIGHT)
	{
		if (!(fdf->zbuff.pixel[row] = (t_coord *)malloc(sizeof(t_coord) *\
															WIN_WIDTH)))
			ft_puterror("Error: memory allocation\n", 4);
		col = 0;
		while (col < WIN_WIDTH)
		{
			fdf->zbuff.pixel[row][col].y = row;
			fdf->zbuff.pixel[row][col].x = col;
			fdf->zbuff.pixel[row][col].z = 1000;
			col++;
		}
		row++;
	}
}

static void	ft_pixel_color(t_line_param *param, t_line *line, int i)
{
	float m;

	if (i == 1)
		m = ft_percent((param->y - line->y0), (line->y1 - line->y0));
	if (i == 2)
		m = ft_percent((param->x - line->x0), (line->x1 - line->x0));
	line->color = ft_color(line->c0, line->c1, m);
}

int			pixel_is_visible(t_fdf *fdf, t_line_param *param,\
												t_line *line, int i)
{
	float	k;
	float	z;

	if (i == 1)
		k = ft_percent((param->y - line->y0), (line->z1 - line->z0));
	if (i == 2)
		k = ft_percent((param->x - line->x0), (line->z1 - line->z0));
	z = k * (line->z1 - line->z0) / 100 + line->z0;
	if ((param->y < WIN_HEIGHT && param->y >= 0 &&\
										param->x < WIN_WIDTH && param->x >= 0))
	{
		if (z > fdf->zbuff.pixel[param->y][param->x].z)
		{
			fdf->zbuff.pixel[param->y][param->x].z = z;
			{
				ft_pixel_color(param, line, i);
				return (1);
			}
		}
	}
	return (0);
}
