/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:28:00 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 16:24:07 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

static void	ft_scale_grid(t_fdf *fdf)
{
	int		row;
	int		col;
	float	k;

	k = fdf->grid.zoom * ft_get_min((WIN_WIDTH / fdf->grid.width),\
				(WIN_HEIGHT / fdf->grid.height)) / 4;
	row = 0;
	while (row < fdf->grid.height)
	{
		col = 0;
		while (col < fdf->grid.width)
		{
			fdf->grid.point[row][col].scale_x = (int)(k * \
					((float)fdf->grid.point[row][col].x -\
					(float)fdf->grid.width * 0.5));
			fdf->grid.point[row][col].scale_y = (int)(k *\
					((float)fdf->grid.point[row][col].y - \
					(float)fdf->grid.height * 0.5));
			fdf->grid.point[row][col].scale_z = (int)(k *\
					((float)fdf->grid.point[row][col].z));
			col++;
		}
		row++;
	}
}

static void	ft_camera_angle(float *alpha, float *beta, float *theta, t_fdf *fdf)
{
	*alpha = 2.00 * 3.14 * (fdf->angle.alpha / 360.00);
	*beta = 2.00 * 3.14 * (fdf->angle.beta / 360.00);
	*theta = 2.00 * 3.14 * (fdf->angle.theta / 360.00);
}

static void	ft_calc_coord(t_fdf *fdf, t_camera *angle, int row, int col)
{
	fdf->grid.point[row][col].proj_x = cos(angle->beta) * cos(angle->theta) *\
		(float)fdf->grid.point[row][col].scale_x + cos(angle->beta) *\
		sin(angle->theta) * (float)fdf->grid.point[row][col].scale_y -\
		sin(angle->beta) * (float)fdf->grid.point[row][col].scale_z;
	fdf->grid.point[row][col].proj_y = (sin(angle->alpha) * sin(angle->beta) *\
		cos(angle->theta) - cos(angle->alpha) * sin(angle->theta)) *\
		(float)fdf->grid.point[row][col].scale_x + (sin(angle->alpha) *\
		sin(angle->beta) * sin(angle->theta) + cos(angle->alpha) *\
		cos(angle->theta)) * (float)fdf->grid.point[row][col].scale_y +\
		sin(angle->alpha) * cos(angle->beta) *\
			(float)fdf->grid.point[row][col].scale_z;
	fdf->grid.point[row][col].proj_z = (cos(angle->alpha) * sin(angle->beta) *\
		cos(angle->theta) + sin(angle->alpha) * sin(angle->theta)) *\
		(float)fdf->grid.point[row][col].scale_x + (cos(angle->alpha) *\
		sin(angle->beta) * sin(angle->theta) - sin(angle->alpha) *\
		cos(angle->theta)) * (float)fdf->grid.point[row][col].scale_y +\
		cos(angle->alpha) * cos(angle->beta) *\
		(float)fdf->grid.point[row][col].scale_z;
}

static void	ft_iso_projection(t_fdf *fdf)
{
	t_camera	angle;
	int			row;
	int			col;
	int			k;

	ft_camera_angle(&angle.alpha, &angle.beta, &angle.theta, fdf);
	row = -1;
	while (++row < fdf->grid.height)
	{
		col = -1;
		while (++col < fdf->grid.width)
		{
			ft_calc_coord(fdf, &angle, row, col);
			k = ft_percent(fdf->grid.point[row][col].z, fdf->grid.z_max);
			fdf->grid.point[row][col].color = ft_color(fdf->color.start,\
													fdf->color.end, k);
		}
	}
}

void		ft_draw(t_fdf *fdf)
{
	t_line	line;

	ft_maxmin_z(fdf);
	ft_scale_grid(fdf);
	ft_iso_projection(fdf);
	ft_clean_zbuff(fdf);
	ft_draw_grid(fdf, &line);
	ft_instructions(fdf);
	mlx_key_hook(fdf->mlx.win_ptr, deal_key, (void*)fdf);
	mlx_loop(fdf->mlx.mlx_ptr);
}
