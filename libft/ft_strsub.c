/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:32:00 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/24 11:44:10 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (!s)
		return (0);
	if (!(fresh = ft_strnew(len)))
		return (0);
	i = 0;
	while (i < len)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	return (fresh);
}
