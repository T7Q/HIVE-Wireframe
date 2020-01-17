/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:50:14 by tkuumola          #+#    #+#             */
/*   Updated: 2019/10/23 14:50:26 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	if (!(mem = (char	*)malloc(sizeof(char) * size + 1)))
		return (0);
	ft_bzero(mem, size + 1);
	return (mem);
}
