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
    {
        c = line[d];
        d++;
    }
   // printf("%d\n", d);
    close(fd);
    free(line);
    return (c);
}

int file_verif(char *file)
{
    int y;
    int fd;

    y = 0;
    while(file[y])
        y++;
    if (file[y - 1] != 'r' || file[y - 2] != 'e' || file[y - 3] != 'b')
        return (ft_printf("Error\nWrong file extension.\n"), 0);
    fd = open(file, O_RDONLY);
    if (read(fd, "", 0) == -1)
        return (ft_printf("Error\nFile not found or not valid.\n"), 0);
    return (1);
}

int map_verif(t_data *data)
{
    int x;
    int y;
    char d;
    int l;

    y = 0;
    l = 0;
    while (y != data->hei_map)
    {
        x = 0;
        while (x < data->len_map)
        {
            d = data->map[l];
            if ((y == 0 && d != '1')\
                || (x == data->len_map && d != '1')\
                || (x == 0 && d != '1')\
                || (y == data->hei_map && d != '1')\
                || (d != '0' && d != '1' && d != 'C' && d != 'E' && d != 'P'))
                return (ft_printf("Error\nMap not respecting the rules.\n"), 0);
            x++;
            l++;
        }
        y++;
    }
    if (x == y || !strchr(data->map, 'E') || !strchr(data->map, 'C') || !strchr(data->map, 'P'))
        return (ft_printf("Error\nMap might not be a rectangle or is missing a character.\n"), 0);
    return (1);
}

char    *put_map_in_tab(t_data *data)
{
    char    *tab;
    int     i;
    char    d;

    tab = malloc(sizeof(int) * (data->len_map * data->hei_map) + 1);
    if (!tab)
        return (NULL);
    i = 0;
    while (i != data->len_map * data->hei_map)
    {
        d = value(data->map_file);
        tab[i] = d;
        i++;
    }
    tab[i] = '\0';
    return (tab);
}