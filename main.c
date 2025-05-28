#include "get_next_line.h"

char *get_next_line(int fd);
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
}