/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:17:00 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/23 16:53:24 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	while (big[i] != '\0' && (size_t)i < n)
	{
		while (big[i + j] == little[j])
		{
			if ((j == len - 1) && ((size_t)(i + j) < n))
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
