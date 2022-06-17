#include "so_long.h"

void    mv_up(t_data *data)
{
    int l;
    int tmp;

    l = 0;
    while (data->map[l] && data->map[l] != 'P')
        l++;
    if (data->map[l] == 'P')
    {
        tmp = l;
        l = strlen((const char *)data->map) / data->hei_map;
        l = tmp - l;
        if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C' || data->map[l] == '2'))
        {
            data->map[l] = 'P';
            data->map[tmp] = '2';
            (data->nbr_step)++;
        }
        if (data->map[l] && data->map[l] == 'E' && !strchr(data->map, 'C'))
            close_window(data);
    }
}

void    mv_left(t_data *data)
{
    int l;
    int tmp;

    l = 0;
    while (data->map[l] && data->map[l] != 'P')
        l++;
    if (data->map[l] == 'P')
    {
        tmp = l;
        l--;
        if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C' || data->map[l] == '2'))
        {
            data->map[l] = 'P';
            data->map[tmp] = '2';
            (data->nbr_step)++;
        }
        if (data->map[l] && data->map[l] == 'E' && !strchr(data->map, 'C'))
            close_window(data);
    }
}

void    mv_down(t_data *data)
{
    int l;
    int tmp;

    l = 0;
    while (data->map[l] && data->map[l] != 'P')
        l++;
    if (data->map[l] == 'P')
    {
        tmp = l;
        l = strlen((const char *)data->map) / data->hei_map;
        l = tmp + l;
        if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C' || data->map[l] == '2'))
        {
            data->map[l] = 'P';
            data->map[tmp] = '2';
            (data->nbr_step)++;
        }
        if (data->map[l] && data->map[l] == 'E' && !strchr(data->map, 'C'))
            close_window(data);
    }
}

void    mv_right(t_data *data)
{
    int l;
    int tmp;

    l = 0;
    while (data->map[l] && data->map[l] != 'P')
        l++;
    if (data->map[l] == 'P')
    {
        tmp = l;
        l++;
        if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C' || data->map[l] == '2'))
        {
            data->map[l] = 'P';
            data->map[tmp] = '2';
            (data->nbr_step)++;
        }
        if (data->map[l] && data->map[l] == 'E' && !strchr(data->map, 'C'))
            close_window(data);
    }
}