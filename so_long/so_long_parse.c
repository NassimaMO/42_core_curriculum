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

int map_verif(t_data *data)
{
    int x;
    int y;
    char d;
    int i;
    int l;

    y = 0;
    i = 0;
    while(data->map_file[y])
        y++;
    if (data->map_file[y - 1] != 'r' || data->map_file[y - 2] != 'e' || data->map_file[y - 3] != 'b')
        return (0);
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
                return (0);
            if (d == 'C')
                i++;
            x++;
            l++;
        }
        y++;
    }
    if (x == y || i == 0)
        return (0);
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