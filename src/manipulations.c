/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:29:29 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 15:24:52 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

int		ft_close(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	exit(0);
}

void	ft_zoom(t_fdf *fdf, int i)
{
	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	if (i == 1 && fdf->grid.zoom < 20)
		fdf->grid.zoom = fdf->grid.zoom * 1.05;
	if (i == 2 && fdf->grid.zoom > 0.1)
		fdf->grid.zoom = fdf->grid.zoom * 0.95;
	ft_draw(fdf);
}

void	ft_change_projection(t_fdf *fdf, int i)
{
	int a;
	int b;
	int t;

	a = (i == 1 ? -1 : 0);
	b = (i == 2 ? -1 : 0);
	t = (i == 3 ? -1 : 0);
	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	fdf->angle.alpha = fdf->angle.alpha + a;
	fdf->angle.beta = fdf->angle.beta + b;
	fdf->angle.theta = fdf->angle.theta + t;
	ft_draw(fdf);
}

void	ft_change_projection2(t_fdf *fdf, int i)
{
	int a;
	int b;
	int t;

	a = (i == 1 ? +1 : 0);
	b = (i == 2 ? +1 : 0);
	t = (i == 3 ? +1 : 0);
	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	fdf->angle.alpha = fdf->angle.alpha + a;
	fdf->angle.beta = fdf->angle.beta + b;
	fdf->angle.theta = fdf->angle.theta + t;
	ft_draw(fdf);
}
