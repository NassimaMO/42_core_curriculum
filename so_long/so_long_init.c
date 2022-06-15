#include "so_long.h"

void    img_init(t_data *data)
{
    data->img_wall.path = "IMAGES/tree.xpm";
    data->img_wall.len = data->img_wall.hei = 64;
    data->img_wall.addr = mlx_xpm_file_to_image(data->mlx_ptr, data->img_wall.path, &data->img_wall.len, &data->img_wall.hei);

    data->img_item.path = "IMAGES/champi.xpm";
    data->img_item.len = data->img_item.hei = 64;
    data->img_item.addr = mlx_xpm_file_to_image(data->mlx_ptr, data->img_item.path, &data->img_item.len, &data->img_item.hei);

    data->img_user.path = "IMAGES/Mario.xpm";
    data->img_user.len = data->img_user.hei = 64;
    data->img_user.addr = mlx_xpm_file_to_image(data->mlx_ptr, data->img_user.path, &data->img_user.len, &data->img_user.hei);

    data->img_background.path = "IMAGES/leaaff.xpm";
    data->img_background.len = data->img_background.hei = 64;
    data->img_background.addr = mlx_xpm_file_to_image(data->mlx_ptr, data->img_background.path, &data->img_background.len, &data->img_background.hei);
    
    data->img_exit.path = "IMAGES/nice.xpm";
    data->img_exit.len = data->img_exit.hei = 64;
    data->img_exit.addr = mlx_xpm_file_to_image(data->mlx_ptr, data->img_exit.path, &data->img_exit.len, &data->img_exit.hei);

    data->img_enemy.path = "IMAGES/enemyn1.xpm";
    data->img_enemy.len = data->img_enemy.hei = 64;
    data->img_enemy.addr = mlx_xpm_file_to_image(data->mlx_ptr, data->img_enemy.path, &data->img_enemy.len, &data->img_enemy.hei);
}

