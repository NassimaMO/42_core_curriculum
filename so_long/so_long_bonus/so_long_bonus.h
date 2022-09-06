/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:43:26 by nmouslim          #+#    #+#             */
/*   Updated: 2022/06/18 13:43:29 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define SIZE_IMG 64

# define RED_PIXEL 0xFF0000
# define ORANGE_PIXEL 0xFF8C00
# define YELLOW_PIXEL 0xFFFF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define BROWN_PIXEL 0xA0522D
# define BROWNER_PIXEL 0x5C3333

# define MLX_ERROR 1
# define MAP_ERROR 2
# define MALLOC_ERROR 42
# define FILE_ERROR 3

typedef struct s_imgs
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imgs;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_lil_imgs
{
	void	*mlx_lil_img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	char	*path;
	int		len;
	int		hei;

}	t_lil_imgs;

typedef struct s_stct_lil_imgs
{
	t_lil_imgs	img_wall;
	t_lil_imgs	img_wall2;
	t_lil_imgs	img_item;
	t_lil_imgs	img_user;
	t_lil_imgs	img_user_mouth_half_open;
	t_lil_imgs	img_user_mouth_closed;
	t_lil_imgs	img_user_up;
	t_lil_imgs	img_user_up_mouth_half_open;
	t_lil_imgs	img_user_up_mouth_closed;
	t_lil_imgs	img_user_down;
	t_lil_imgs	img_user_down_mouth_half_open;
	t_lil_imgs	img_user_down_mouth_closed;
	t_lil_imgs	img_user_left;
	t_lil_imgs	img_user_left_mouth_half_open;
	t_lil_imgs	img_user_left_mouth_closed;
	t_lil_imgs	img_background;
	t_lil_imgs	img_background_after;
	t_lil_imgs	img_exit;
	t_lil_imgs	img_enemy;
	t_lil_imgs	img_0;
	t_lil_imgs	img_1;
	t_lil_imgs	img_2;
	t_lil_imgs	img_3;
	t_lil_imgs	img_4;
	t_lil_imgs	img_5;
	t_lil_imgs	img_6;
	t_lil_imgs	img_7;
	t_lil_imgs	img_8;
	t_lil_imgs	img_9;
}	t_stct_lil_imgs;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*map_file;
	int				hei_map;
	int				len_map;
	int				nbr_step;
	char			user;
	char			*map;
	t_imgs			img;
	t_stct_lil_imgs	stct;
}	t_data;

//so_long_init_and_free.c
void		init_map(t_data *win_param, int argc, char **argv);
void		free_all(t_data *win_param);

//so_long_init.c
void		init_call(t_data *data);

//so_long_end.c
void		escape(t_data *data);
int			close_window(t_data *data);
void		free_data_imgs(void *img);
void		free_lil_imgs(t_stct_lil_imgs *imgs);

//so_long_img/so_long_imgs.c
void		render_steps(t_data *data);
int			render(t_data *data);
int			moved(t_data *data, int img_x, int img_y, int x);

//so_long_img/so_long_imgs_print.c
void		background_reset(t_data *data, int img_x, int img_y);
void		render_background(t_data *data, int color);
void		print_img(t_lil_imgs *img, t_data *data, int x, int y);

//so_long_img/so_long_imgs_utils.c
void		img_pix_put(t_imgs *img, int x, int y, int color);
t_lil_imgs	*get_img_ntr(char c, t_data *data);
t_lil_imgs	*return_ntr(t_stct_lil_imgs *img, int n);
t_lil_imgs	*get_img_num_ntr(t_stct_lil_imgs *img, int steps, int l, int x);

//so_long_img/so_long_sprite_anim_imgs.c
void		sprite_animations(t_data *data, int l, int img_x, int img_y);

//so_long_enemy/so_long_place_enemy.c
void		put_enemy_in_map(t_data *data);

//so_long_enemy/so_long_enemy_imgs.c
void		enemy_mvments(t_data *data);
int			n_mv_up(t_data *data);
int			n_mv_left(t_data *data);
int			n_mv_down(t_data *data);
int			n_mv_right(t_data *data);

//so_long_utils.c
int			ft_strlen(const char *s);
int			nbr_case(int n);

//so_long_parse.c
int			width_size_map(char *file);
int			height_size_map(char *file);
char		*put_map_in_tab(t_data *data);

//so_long_move.c
void		mv_up(t_data *data);
void		mv_left(t_data *data);
void		mv_down(t_data *data);
void		mv_right(t_data *data);

//so_long_input.c
int			input(int keysym, t_data *data);

//so_long_verif.c
int			file_verif(char *file);
int			map_verif(t_data *data);
void		map_path(t_data *data);

//gnl
char		*get_next_line(int fd);

//ft_printf
int			ft_printf(const char *str, ...);

#endif
