#include "so_long_bonus.h"

int	find_enemy(const char *s, int c)
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

static void	n_sprite_animation(t_data *data)
{
	static int	i;
	int	l;

	l = find_enemy(data->map, 'N');
	if (l < 0)
		return ;
	if (i == 0)
		user_display(&data->stct.img_enemy_left, data, \
						l % data->len_map, l / data->len_map);
	else if (i == 10000)
		user_display(&data->stct.img_enemy_middle, data, \
						l % data->len_map, l / data->len_map);
	else if (i == 20000)
	{
		user_display(&data->stct.img_enemy_right, data, l % \
						data->len_map, l / data->len_map);
		i = -1;
	}
	i++;
}