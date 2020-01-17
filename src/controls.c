/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:28:25 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 16:42:11 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

void	ft_projection_iso(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	fdf->angle.alpha = -45.00;
	fdf->angle.beta = 0.00;
	fdf->angle.theta = -35.00;
	ft_draw(fdf);
}

void	ft_projection_parallel(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	fdf->angle.alpha = 00.00;
	fdf->angle.beta = 00.00;
	fdf->angle.theta = 00.00;
	ft_draw(fdf);
}

void	ft_instructions(t_fdf *fdf)
{
	int i;

	i = 50;
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 40, i += 15,\
										NEON_BLUE, "How to Use");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 40, i += 15,\
										TEXT_COLOR, "Zoom: +/- ");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 40, i += 15,\
										TEXT_COLOR, "Exit: Esc");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 40, i += 15,\
						TEXT_COLOR, "Rotate: 1 - 4, 2 - 5, 3 -6");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 40, i += 15,\
						TEXT_COLOR, "Change color: Space");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 40, i += 15,\
										TEXT_COLOR, "ISO: I Key");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 40, i += 15,\
										TEXT_COLOR, "Parallel: P Key");
}

int		deal_key(int key, t_fdf *fdf)
{
	if (key == 53)
		ft_close(fdf);
	if (key == 49)
		ft_change_palette(fdf);
	if (key == 35)
		ft_projection_parallel(fdf);
	if (key == 34)
		ft_projection_iso(fdf);
	if (key == 69)
		ft_zoom(fdf, 1);
	if (key == 78)
		ft_zoom(fdf, 2);
	if (key == 83)
		ft_change_projection(fdf, 1);
	if (key == 86)
		ft_change_projection2(fdf, 1);
	if (key == 87)
		ft_change_projection(fdf, 2);
	if (key == 84)
		ft_change_projection2(fdf, 2);
	if (key == 85)
		ft_change_projection(fdf, 3);
	if (key == 88)
		ft_change_projection2(fdf, 3);
	return (0);
}
