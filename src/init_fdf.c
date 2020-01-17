/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:28:42 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 16:42:21 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

void	ft_init_to_zero(t_fdf *fdf, int row, int col)
{
	fdf->grid.point[row][col].proj_x = 0;
	fdf->grid.point[row][col].proj_y = 0;
	fdf->grid.point[row][col].proj_z = 0;
	fdf->grid.point[row][col].scale_x = 0;
	fdf->grid.point[row][col].scale_y = 0;
	fdf->grid.point[row][col].scale_z = 0;
	fdf->grid.point[row][col].color = 0;
}

void	ft_init_fdf(t_fdf *fdf)
{
	fdf->mlx.mlx_ptr = mlx_init();
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, WIN_WIDTH,\
										WIN_HEIGHT, "wireframe");
	fdf->grid.z_max = 0;
	fdf->grid.z_min = 0;
	fdf->grid.zoom = 1;
	fdf->angle.alpha = 0.00;
	fdf->angle.beta = 0.00;
	fdf->angle.theta = 0.00;
	fdf->color.start = NEON_BLUE;
	fdf->color.end = PINK;
	fdf->color.palette = 1;
	ft_init_buff(fdf);
}
