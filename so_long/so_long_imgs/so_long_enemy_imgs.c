#include "../so_long.h"

void enemy_mvments(t_data *data)
{
    static int i = 0;
    static int mvUp = 0;
    static int mvDown = 0;
    static int mvLeft = 0;
    static int mvRight = 0;

    if (i == 100)
    {
        i = 0;
        if (n_mv_up(data) && (!mvUp || (mvDown && mvLeft && mvRight)))
        {
            mvUp++;
            mvDown = mvLeft = mvRight = 0;
            return ;
        }
        if (n_mv_down(data) && !mvDown)
            return ;
        if (n_mv_left(data) && !mvLeft)
            return ;
        if (n_mv_right(data) && !mvRight)
            return ;
    }
    i++;
}

int    n_mv_up(t_data *data)
{
    int l;
    int tmp;

    l = 0;
    while (data->map[l] && data->map[l] != 'N')
        l++;
    if (data->map[l] == 'N')
    {
        tmp = l;
        l = strlen((const char *)data->map) / data->hei_map;
        l = tmp - l;
        if (data->map[l] && data->map[l] == '0')
        {
            data->map[l] = 'N';
            data->map[tmp] = '0';
            return (1);
        }
    }
    return (0);
}

int    n_mv_left(t_data *data)
{
    int l;
    int tmp;

    l = 0;
    while (data->map[l] && data->map[l] != 'N')
        l++;
    if (data->map[l] == 'N')
    {
        tmp = l;
        l--;
        if (data->map[l] && data->map[l] == '0')
        {
            data->map[l] = 'N';
            data->map[tmp] = '0';
            return (1);
        }
    }
    return (0);
}

int    n_mv_down(t_data *data)
{
    int l;
    int tmp;

    l = 0;
    while (data->map[l] && data->map[l] != 'N')
        l++;
    if (data->map[l] == 'N')
    {
        tmp = l;
        l = strlen((const char *)data->map) / data->hei_map;
        l = tmp + l;
        if (data->map[l] && data->map[l] == '0')
        {
            data->map[l] = 'N';
            data->map[tmp] = '0';
            return (1);
        }
    }
    return (0);
}

int    n_mv_right(t_data *data)
{
    int l;
    int tmp;

    l = 0;
    while (data->map[l] && data->map[l] != 'N')
        l++;
    if (data->map[l] == 'N')
    {
        tmp = l;
        l++;
        if (data->map[l] && data->map[l] == '0')
        {
            data->map[l] = 'N';
            data->map[tmp] = '0';
            return (1);
        }
    }
    return (0);
}