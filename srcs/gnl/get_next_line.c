/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:32:47 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/08 19:32:03 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static char	*get_extra(int fd, char *extra)
{
	int		bytes;
	char	*buff;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && !extra))
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = 0;
		tmp = ft_strjoin(extra, buff);
		free(extra);
		extra = tmp;
	}
	free(buff);
	return (extra);
}

static char	*get_line(char	*extra)
{
	int		i;
	char	*line;

	i = 0;
	while (extra[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (extra[i])
	{
		line[i] = extra[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	extra = get_extra(fd, extra);
	if (!extra)
		return (NULL);
	line = get_line(extra);
	return (line);
}
