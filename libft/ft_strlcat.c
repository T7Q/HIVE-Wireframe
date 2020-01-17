/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:12:28 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/30 16:19:00 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] && size > i)
		i++;
	j = 0;
	while (src[j] && size > (j + i + 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (size > i)
		dest[j + i] = '\0';
	return (ft_strlen((char *)src) + i);
}
