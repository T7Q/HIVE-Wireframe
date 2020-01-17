/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:09:46 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/28 10:16:40 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int i;

	i = 0;
	while (src[i] != '\0' && (size_t)i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while ((size_t)i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
