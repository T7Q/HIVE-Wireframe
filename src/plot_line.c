/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:27:42 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 15:46:51 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

static void		ft_plot_line_low(t_line *line, t_fdf *fdf)
{
	t_line_param	param;

	param.delta_x = line->x1 - line->x0;
	param.delta_y = line->y1 - line->y0;
	param.yi = 1;
	if (param.delta_y < 0)
	{
		param.yi = -1;
		param.delta_y = -param.delta_y;
	}
	param.d = 2 * param.delta_y - param.delta_x;
	param.y = line->y0;
	param.x = line->x0 - 1;
	while (++param.x < line->x1)
	{
		if (pixel_is_visible(fdf, &param, line, 2) == 1)
			mlx_pixel_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, param.x, param.y,\
				line->color);
		if (param.d > 0)
		{
			param.y = param.y + param.yi;
			param.d = param.d - 2 * param.delta_x;
		}
		param.d = param.d + 2 * param.delta_y;
	}
}

static void		ft_plot_line_high(t_line *line, t_fdf *fdf)
{
	t_line_param	param;

	param.delta_x = line->x1 - line->x0;
	param.delta_y = line->y1 - line->y0;
	param.xi = 1;
	if (param.delta_x < 0)
	{
		param.xi = -1;
		param.delta_x = -param.delta_x;
	}
	param.d = 2 * param.delta_x - param.delta_y;
	param.x = line->x0;
	param.y = line->y0 - 1;
	while (++param.y < line->y1)
	{
		if (pixel_is_visible(fdf, &param, line, 1) == 1)
			mlx_pixel_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, param.x, param.y,\
						line->color);
		if (param.d > 0)
		{
			param.x = param.x + param.xi;
			param.d = param.d - 2 * param.delta_y;
		}
		param.d = param.d + 2 * param.delta_x;
	}
}

static void		ft_coord_swap(t_line *line)
{
	int	temp_x;
	int	temp_y;
	int	temp_z;
	int temp_c;

	temp_x = line->x0;
	line->x0 = line->x1;
	line->x1 = temp_x;
	temp_y = line->y0;
	line->y0 = line->y1;
	line->y1 = temp_y;
	temp_c = line->c0;
	line->c0 = line->c1;
	line->c1 = temp_c;
	temp_z = line->z0;
	line->z0 = line->z1;
	line->z1 = temp_z;
}

void			ft_plot_line(t_fdf *fdf, t_line *line)
{
	if (abs(line->y1 - line->y0) < abs(line->x1 - line->x0))
	{
		if (line->x0 > line->x1)
		{
			ft_coord_swap(line);
			ft_plot_line_low(line, fdf);
		}
		else
			ft_plot_line_low(line, fdf);
	}
	else
	{
		if (line->y0 > line->y1)
		{
			ft_coord_swap(line);
			ft_plot_line_high(line, fdf);
		}
		else
			ft_plot_line_high(line, fdf);
	}
}
