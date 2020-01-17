/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:30:36 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/27 15:05:45 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*fresh;
	int		len;
	int		start;

	start = 0;
	if (!s)
		return (0);
	len = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (s[start] == '\0')
		return (ft_strnew(0));
	fresh = ft_strsub(s, start, len - start + 1);
	return (fresh);
}
