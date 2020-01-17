/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:00:21 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/30 11:54:26 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *src)
{
	char	*duplicate;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (duplicate == 0)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		duplicate[len] = src[len];
		len++;
	}
	duplicate[len] = '\0';
	return (duplicate);
}
