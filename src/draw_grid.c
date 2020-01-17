/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:27:52 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/18 21:51:32 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

static void	ft_line_start(int row, int col, t_fdf *fdf, t_line *line)
{
	line->x0 = (int)(fdf->grid.point[row][col].proj_x + WIN_WIDTH / 2.0);
	line->y0 = (int)(fdf->grid.point[row][col].proj_y + WIN_HEIGHT / 2.0);
	line->z0 = (int)(fdf->grid.point[row][col].proj_z + WIN_HEIGHT / 2.0);
	line->c0 = (int)(fdf->grid.point[row][col].color);
}

static void	ft_line_end_and_draw(int row, int col, t_fdf *fdf, t_line *line)
{
	line->x1 = (int)(fdf->grid.point[row][col].proj_x + WIN_WIDTH / 2.0);
	line->y1 = (int)(fdf->grid.point[row][col].proj_y + WIN_HEIGHT / 2.0);
	line->z1 = (int)(fdf->grid.point[row][col].proj_z + WIN_HEIGHT / 2.0);
	line->c1 = (int)(fdf->grid.point[row][col].color);
	ft_plot_line(fdf, line);
}

void		ft_draw_grid(t_fdf *fdf, t_line *line)
{
	int row;
	int col;

	row = -1;
	while (++row <= (fdf->grid.height - 1))
	{
		col = -1;
		while (++col <= (fdf->grid.width - 1))
		{
			ft_line_start(row, col, fdf, line);
			if (col == fdf->grid.width - 1 && row == fdf->grid.height - 1)
				break ;
			else if (row == (fdf->grid.height - 1))
				ft_line_end_and_draw(row, col + 1, fdf, line);
			else if (col == (fdf->grid.width - 1))
				ft_line_end_and_draw(row + 1, col, fdf, line);
			else
			{
				ft_line_end_and_draw(row, col + 1, fdf, line);
				ft_line_start(row, col, fdf, line);
				ft_line_end_and_draw(row + 1, col, fdf, line);
			}
		}
	}
}
