/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:31:00 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/30 14:37:43 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n, int sign)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	len = len + (sign ? 1 : 0);
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0 ? 1 : 0);
	n = (sign ? -n : n);
	len = ft_numlen(n, sign);
	if (!(str = ft_strnew(len)))
		return (0);
	while (len)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
