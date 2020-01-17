/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:51:22 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 14:04:33 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fdf.h"

int		ft_get_max(int num1, int num2)
{
	return (num1 > num2 ? num1 : num2);
}

int		ft_percent(int value, int total)
{
	float result;

	if (total == 0)
		return (0);
	result = ((float)value / (float)total) * 100;
	return ((int)result);
}

float	ft_get_min(float num1, float num2)
{
	return (num1 > num2 ? num2 : num1);
}

void	ft_free_memory(t_fdf *fdf)
{
	int row;

	row = 0;
	while (row < fdf->grid.height)
	{
		free(&(fdf->grid.point[row]));
		row++;
	}
}

size_t	ft_wordnb(const char *s)
{
	size_t	i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != ' ')
		{
			wordcount++;
			while (s[i] != ' ' && s[i])
				i++;
		}
		while (s[i] == ' ')
			i++;
	}
	return (wordcount);
}
