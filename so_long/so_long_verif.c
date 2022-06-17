#include "so_long.h"

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
