/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavrukh <alavrukh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:39:32 by alavrukh          #+#    #+#             */
/*   Updated: 2025/06/02 11:39:33 by alavrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>  
#include <stdio.h>   

static char *remainder;

int main (void)
{
    int fd = open ("readme.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line (fd)) != NULL)
    {
        printf ("%s", line);
        free (line);
    }
    close(fd);
	free (remainder);
}