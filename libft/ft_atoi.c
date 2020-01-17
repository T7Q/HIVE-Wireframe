/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:06:03 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/27 15:28:31 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' \
			|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		sign = ((*str == '-') ? -1 : 1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = 10 * n + (*str - '0');
		str++;
	}
	return ((n * sign));
}
