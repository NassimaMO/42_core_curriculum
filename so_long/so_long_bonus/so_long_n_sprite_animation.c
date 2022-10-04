#include "so_long_bonus.h"

static int	find_enemy(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

void	n_sprite_animation(t_data *data)
{
	static int	i;
	int			l;

	l = find_enemy(data->map, 'N');
	if (i == 0)
		display(&data->stct.img_enemy_left, data, \
						l % data->len_map, l / data->len_map);
	else if (i == 15000 || i == 45000)
		display(&data->stct.img_enemy, data, \
						l % data->len_map, l / data->len_map);
	else if (i == 30000)
		display(&data->stct.img_enemy_right, data, l % \
						data->len_map, l / data->len_map);
	else if (i == 59999)
		i = -1;
	i++;
}

void	n_sprite_animation_right(t_data *data)
{
	static int	i;
	int			l;

	l = find_enemy(data->map, 'K');
	if (i == 0)
		display(&data->stct.img_enemy_left_LR, data, \
						l % data->len_map, l / data->len_map);
	else if (i == 15000 || i == 45000)
		display(&data->stct.img_enemy_LR, data, \
						l % data->len_map, l / data->len_map);
	else if (i == 30000)
		display(&data->stct.img_enemy_right_LR, data, l % \
						data->len_map, l / data->len_map);
	else if (i == 59999)
		i = -1;
	i++;
}