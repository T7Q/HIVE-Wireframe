/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:17:09 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/19 14:56:17 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_read_input(const int fd, char **str)
{
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			bytes_read;

	bytes_read = 0;
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (bytes_read);
}

static int		ft_trim_input(char **str, char **line, const int fd)
{
	char	*temp;
	int		len_tail;
	int		len_line;

	temp = str[fd];
	len_tail = 0;
	if (ft_strchr(temp, '\n'))
		len_tail = ft_strlen(ft_strchr(temp, '\n'));
	len_line = ft_strlen(temp) - len_tail;
	*line = ft_strsub(temp, 0, len_line);
	str[fd] = ft_strsub(temp, (len_line + 1), len_tail);
	free(temp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[4000];
	int			bytes_read;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL || fd > 4000)
		return (-1);
	bytes_read = ft_read_input(fd, str);
	if (bytes_read < 0)
		return (-1);
	else if (bytes_read == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
	{
		return (0);
	}
	else
		return (ft_trim_input(str, line, fd));
}
