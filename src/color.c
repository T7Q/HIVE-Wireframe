/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:27:32 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 15:33:21 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

void		ft_maxmin_z(t_fdf *fdf)
{
	int col;
	int row;

	fdf->grid.z_max = fdf->grid.point[0][0].z;
	fdf->grid.z_min = fdf->grid.point[0][0].z;
	row = 0;
	while (row < fdf->grid.height)
	{
		col = 0;
		while (col < fdf->grid.width)
		{
			fdf->grid.z_min = ft_get_min((float)fdf->grid.z_min,\
				(float)fdf->grid.point[row][col].z);
			fdf->grid.z_max = ft_get_max(fdf->grid.z_max,\
				fdf->grid.point[row][col].z);
			col++;
		}
		row++;
	}
}

static void	ft_rgb_hex(int color_hex, t_rgb *color)
{
	color->red = color_hex >> 16 & 0xFF;
	color->green = color_hex >> 8 & 0xFF;
	color->blue = color_hex & 0xFF;
}

int			ft_color(int start, int end, int k)
{
	int		hex;
	t_rgb	min;
	t_rgb	max;
	t_rgb	result;

	ft_rgb_hex(start, &min);
	ft_rgb_hex(end, &max);
	result.red = k * (max.red - min.red) / 100 + min.red;
	result.green = k * (max.green - min.green) / 100 + min.green;
	result.blue = k * (max.blue - min.blue) / 100 + min.blue;
	hex = ((result.red & 0xFF) << 16) +\
					((result.green & 0xFF) << 8) + (result.blue & 0xFF);
	return (hex);
}
