/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:09:17 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/28 10:13:41 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	if (n <= 0)
		return (0);
	i = 1;
	while ((*s1 == *s2) && (i <= n))
	{
		if ((*s1 == '\0' && *s2 == '\0') || (i == n))
			return (0);
		s1++;
		s2++;
		i++;
	}
	return (((unsigned char)*s1) - ((unsigned char)*s2));
}
