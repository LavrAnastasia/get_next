/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavrukh <alavrukh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:22 by alavrukh          #+#    #+#             */
/*   Updated: 2025/05/31 18:46:36 by alavrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_line (int fd, char *reminder, char *reading)
{
	ssize_t read_bytes;
	char temp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, reading, BUFFER_SIZE);
		if (read_bytes <=0)
			break;
		reading[read_bytes] = '\0';
		if(!reminder)
			reminder = ft_strdup("");
		temp = reminder;
		

	}
}

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
		free(reminder); 
		return NULL;
	reminder = ft_line (fd, reading, reminder);
		free (reading);
		reading = NULL;
	if (!reminder)
	return NULL;
	result = reminder;
	reminder = ft_save(result);
	return (result);
}