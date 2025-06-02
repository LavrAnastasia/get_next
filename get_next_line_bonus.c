/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavrukh <alavrukh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:39:59 by alavrukh          #+#    #+#             */
/*   Updated: 2025/06/02 12:50:33 by alavrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_line(int fd, char *remainder, char *buffer)
{
	ssize_t	read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = remainder;
		remainder = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_bytes < 0)
	{
		free(remainder);
		return (NULL);
	}
	return (remainder);
}

char	*save_line(char *entire_line)
{
	char	*newline;
	char	*after_newline;

	newline = ft_strchr(entire_line, '\n');
	if (newline)
	{
		after_newline = ft_strdup(newline + 1);
		if (!after_newline || *after_newline == '\0')
		{
			free(after_newline);
			after_newline = NULL;
			return (NULL);
		}
		*(newline + 1) = '\0';
		return (after_newline);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];
	char		*buffer;
	char		*result;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= MAX_FD)
		return (NULL);
	result = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(remainder[fd]);
		return (NULL);
	}
	remainder[fd] = fill_line (fd, remainder[fd], buffer);
	free (buffer);
	buffer = NULL;
	if (!remainder[fd])
		return (NULL);
	result = remainder[fd];
	remainder[fd] = save_line(result);
	return (result);
}
