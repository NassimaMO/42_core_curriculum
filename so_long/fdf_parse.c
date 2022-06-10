#include "fdf.h"

int width_size_map()
{
    int fd;
    char *line;
    int x;
    int i;

    fd = open("elem.fdf", O_RDONLY);
    line = get_next_line(fd);
    x = 0;
    i = 0;
    while(line[i])
    {
        if (ft_isdigit(line[i]))
            x++;
        i++;
    }
    x--;
    close(fd);
    free(line);
    return (x);
}

int height_size_map()
{
    int fd;
    char *line;
    int y;

    y = 0;
    fd = open("elem.fdf", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        line = get_next_line(fd);
        y++;
    }
    close(fd);
    free(line);
    return (y);
}

int value()
{
    static int d = 0;
    static int l = 0;
    int fd;
    char *line;
    int i;

    fd = open("elem.fdf", O_RDONLY);
    i = 0;
    line = get_next_line(fd);
    while (line && i < l)
    {
        line = get_next_line(fd);
        i++;
    }
    if (line && !line[d + 1])
    {
        d = 0;
        line = get_next_line(fd);
        l++;
    }
    if (!line)
    {
        d = 0;
        l = 0;
        close(fd);
        fd = open("elem.fdf", O_RDONLY);
        line = get_next_line(fd);

    }
    while (line && line[d])
    {
        if (ft_isdigit(line[d]))
        {
            i = ft_atoi(line + d);
            if (i > 9)
                d += 2;
            else
                d++;
            break ;
        }
        d++;
    }
    close(fd);
    free(line);
    return (i);
}