/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:19:49 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/30 16:20:37 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_wordnb(const char *s, char c)
{
	size_t	i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			wordcount++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (wordcount);
}

static size_t			ft_wordlen(const char *s, char c, int start)
{
	size_t wordlen;

	wordlen = 0;
	while (s[start] != c && s[start])
	{
		wordlen++;
		start++;
	}
	return (wordlen);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**array;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	array = 0;
	if (!s)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(char *) * (ft_wordnb(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(array[j++] = ft_strsub(s, i, ft_wordlen(s, c, i))))
				return (NULL);
			while (s[i] != c && s[i])
				i++;
		}
		array[j] = 0;
	}
	return (array);
}
