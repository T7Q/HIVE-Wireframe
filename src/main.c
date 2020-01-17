/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:01:02 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/19 22:14:24 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

void	ft_puterror(char *message, int ret)
{
	ft_putendl(message);
	exit(ret);
}

int		main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		if (ft_read(argv, &fdf) == 1)
		{
			ft_init_fdf(&fdf);
			ft_draw(&fdf);
		}
	}
	else
		write(1, "usage: ./fillit input_file\n", 28);
	return (0);
}
