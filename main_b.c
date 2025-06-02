#include "get_next_line_bonus.h"

#include <fcntl.h>  
#include <stdio.h>   

int main (void)
{
    int fd1;
    int fd2;
    fd1 = open ("readme.txt", O_RDONLY);
    fd2 = open ("bonus.txt", O_RDONLY);

    char *line1, *line2;
    line1 = get_next_line (fd1);
    line2 = get_next_line (fd2);
    while (line1 || line2)
    {
        if (line1)
        {
            printf ("File 1 content: %s\n", line1);
            free (line1);
        }
        if (line2) {
            printf ("File 2 content: %s\n", line2);
            free (line2);
        }
        line1 = get_next_line (fd1);
        line2 = get_next_line (fd2);
    }
    close(fd1);
    close(fd2);
}