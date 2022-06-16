#include "so_long.h"

void direct_mv(int keysym, t_data *data)
{
    if (keysym == XK_W || keysym == XK_w)
        mv_up(data);
    else if (keysym == XK_A || keysym == XK_a)
        mv_left(data);
    else if (keysym == XK_S || keysym == XK_s)
        mv_down(data);
    else if (keysym == XK_D || keysym == XK_d)
        mv_right(data);
}

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
        if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C'))
        {
            data->map[l] = 'P';
            data->map[tmp] = '0';
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
        if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C'))
        {
            data->map[l] = 'P';
            data->map[tmp] = '0';
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
        if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C'))
        {
            data->map[l] = 'P';
            data->map[tmp] = '0';
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
        if (data->map[l] && (data->map[l] == '0' || data->map[l] == 'C'))
        {
            data->map[l] = 'P';
            data->map[tmp] = '0';
            (data->nbr_step)++;
        }
        if (data->map[l] && data->map[l] == 'E' && !strchr(data->map, 'C'))
            close_window(data);
    }
}