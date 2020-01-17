/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:26:55 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 15:36:33 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

static int		is_valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || ft_isdigit(line[i]) ||\
							(line[i] = '-' && ft_isdigit(line[(i + 1)])))
			return (1);
		i++;
	}
	return (0);
}

static int		is_valid_input(t_fdf *fdf, char **argv)
{
	int		fd;
	char	*line;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_puterror("Error: opening file", 1);
	fdf->grid.height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (fdf->grid.height == 0)
			fdf->grid.width = ft_wordnb(line);
		if ((int)ft_wordnb(line) == fdf->grid.width)
		{
			if (is_valid_char(line) == 0)
				return (0);
			fdf->grid.height++;
		}
		else
			ft_puterror("Error: invalid input", 1);
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("Error: closing file", 1);
	return (1);
}

static int		ft_allocate_grid_memory(t_fdf *fdf)
{
	int i;

	if (!(fdf->grid.point = (t_point **)malloc(sizeof(t_point **) * \
												fdf->grid.height)))
		ft_puterror("Error: memory allocation\n", 1);
	i = 0;
	while (i < fdf->grid.height)
	{
		if (!(fdf->grid.point[i] = (t_point *)malloc(sizeof(t_point) * \
										fdf->grid.width)))
			ft_puterror("Error: memory allocation\n", 1);
		i++;
	}
	return (1);
}

static void		ft_update_grid(t_fdf *fdf, char *line, int row)
{
	char	**split;
	int		col;
	int		i;

	i = 0;
	col = 0;
	if ((split = ft_strsplit(line, ' ')))
	{
		while (col < fdf->grid.width)
		{
			fdf->grid.point[row][col].x = col;
			fdf->grid.point[row][col].y = row;
			fdf->grid.point[row][col].z = ft_atoi(split[col]);
			ft_init_to_zero(fdf, row, col);
			col++;
		}
		while (i < fdf->grid.width)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

int				ft_read(char **argv, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		row;

	row = 0;
	if (is_valid_input(fdf, argv))
	{
		if (!(ft_allocate_grid_memory(fdf)))
			return (0);
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_puterror("Error: opening file", 1);
		while (get_next_line(fd, &line) > 0)
		{
			ft_update_grid(fdf, line, row);
			free(line);
			row++;
		}
		if (close(fd) < 0)
			ft_puterror("Error: closing file", 1);
	}
	else
		ft_puterror("Error: invalid input", 1);
	return (1);
}
