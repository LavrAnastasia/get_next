/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavrukh <alavrukh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:22 by alavrukh          #+#    #+#             */
/*   Updated: 2025/06/02 12:46:31 by alavrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*remainder;
	char		*buffer;
	char		*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	result = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(remainder);
		return (NULL);
	}
	remainder = fill_line (fd, remainder, buffer);
	free (buffer);
	buffer = NULL;
	if (!remainder)
		return (NULL);
	result = remainder;
	remainder = save_line(result);
	return (result);
}
