/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:14:12 by mstefano          #+#    #+#             */
/*   Updated: 2024/01/30 15:19:42 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*after_newline(char *buffer)
{
	char	*line;
	size_t	linesize;
	int		i;
	int		j;

	linesize = ft_strlen(buffer);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL);
	line = ft_calloc((linesize - i + 1), sizeof(char));
	if (!line)
		return (0);
	i = i + 1;
	while (buffer[i])
		line[j++] = buffer[i++];
	free (buffer);
	return (line);
}

char	*found_newline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	return (line);
}

char	*read_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	bytesread;

	if (!line)
		line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0 && (ft_strchr(buffer, '\n')) == NULL)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(buffer), free(line), buffer = NULL);
		buffer[bytesread] = '\0';
		if (line && buffer)
			line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash[fd] = read_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = found_newline(stash[fd]);
	stash[fd] = after_newline(stash[fd]);
	return (line);
}
