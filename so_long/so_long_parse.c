#include "so_long.h"

int width_size_map(char *file)
{
    int fd;
    char *line;
    int x;
    int i;

    fd = open(file, O_RDONLY);
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

int height_size_map(char *file)
{
    int fd;
    char *line;
    int y;

    y = 0;
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        y++;
    }
    close(fd);
    free(line);
    return (y);
}

char value(char *file)
{
    static int d = 0;
    static int l = 0;
    int fd;
    char *line;
    int i;
    char    c;

    fd = open(file, O_RDONLY);
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
        fd = open(file, O_RDONLY);
        line = get_next_line(fd);

    }
    if (line && line[d])
        d++;
    c = line[d];
    close(fd);
    free(line);
    return (c);
}

int map_verif(char *file)
{
    int x;
    int y;
    char d;

    y = 0;
    while (y != height_size_map(file))
    {
        x = 0;
        while (x <= width_size_map(file))
        {
            d = value(file);
            if ((y == 0 && d != '1')\
                || (x == width_size_map(file) && d != '1')\
                || (x == 0 && d != '1')\
                || (y == height_size_map(file) && d != '1')\
                || (d != '0' && d != '1' && d != 'C' && d != 'E' && d != 'P'))
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

char    *put_map_in_tab(char *file)
{
    char    *tab;
    int     i;

    tab = malloc(sizeof(int) * (height_size_map(file) * width_size_map(file)) + 1);
    if (!tab)
        return (NULL);
    i = 0;
    while (i != height_size_map(file) * width_size_map(file))
    {
        tab[i] = value(file);
        i++;
    }
    tab[i] = '\0';
    return (tab);
}