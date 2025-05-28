/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get _next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavrukh <alavrukh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:22 by alavrukh          #+#    #+#             */
/*   Updated: 2025/05/28 13:52:57 by alavrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int  start = 0;
    static int  end = 0;
    int i = 0;
    char *line = malloc(BUFFER_SIZE + 1);

    if (!line)
        return NULL;

    while (1)
    {
        if (start >= end) 
        {
            end = read(fd, buffer, BUFFER_SIZE);
            start = 0;
            if (end <= 0)  
            {
                free(line);
                return NULL;
            }
        }

        line[i] = buffer[start];
        start++;
        i++;

        if (line[i - 1] == '\n')
            break;

        if (i >= BUFFER_SIZE)
            break;
    }

    line[i] = '\0';

    return line;
}