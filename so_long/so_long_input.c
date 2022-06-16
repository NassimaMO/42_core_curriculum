#include "so_long.h"

int input(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        escape(data);
    else
        direct_mv(keysym, data);
    return (0);
}