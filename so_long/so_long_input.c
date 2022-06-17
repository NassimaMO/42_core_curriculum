#include "so_long.h"

int input(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        escape(data);
    else
        direct_mv(keysym, data);
    return (0);
}

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
