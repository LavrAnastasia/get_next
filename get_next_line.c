/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavrukh <alavrukh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:22 by alavrukh          #+#    #+#             */
/*   Updated: 2025/05/30 15:56:08 by alavrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* 
char *get_next_line(int fd)
{
	char *line;

	line = malloc (BUFFER_SIZE +1);
	if (!line)
		return NULL;

	ssize_t bytes_read = read (fd, line, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(line);
		return NULL;
	}
	line[bytes_read] = '\0';
	return line;
} */

char *get_next_line (int fd)
{
	static char *reminder;
	char *reading;
	char *result;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return NULL;
	reminder = NULL;
	reading = (char*)malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!reading)
		free(reminder), 
	return NULL;
}

