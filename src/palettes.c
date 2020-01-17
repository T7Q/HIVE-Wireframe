/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:29:40 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/19 23:52:46 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

static void	ft_update_palette(t_fdf *fdf)
{
	if (fdf->color.palette == 4)
	{
		fdf->color.start = NEON_BLUE;
		fdf->color.end = PINK;
		fdf->color.palette = 1;
	}
	else if (fdf->color.palette == 1)
	{
		fdf->color.start = BLACK;
		fdf->color.end = NEON_GREEN;
		fdf->color.palette = 2;
	}
	else if (fdf->color.palette == 2)
	{
		fdf->color.start = ORANGE;
		fdf->color.end = PINK;
		fdf->color.palette = 3;
	}
	else if (fdf->color.palette == 3)
	{
		fdf->color.start = GREEN;
		fdf->color.end = WHITE;
		fdf->color.palette = 4;
	}
}

void		ft_change_palette(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	ft_update_palette(fdf);
	ft_draw(fdf);
}
