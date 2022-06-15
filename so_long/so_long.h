#ifndef FDF_H
#define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
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
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_lil_imgs
{
	char	*path;
	void	*addr;
	int		len;
	int		hei;
}	t_lil_imgs;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map_file;
	int		hei_map;
	int		len_map;
	char	*map;
	t_imgs	img;
	t_lil_imgs	img_wall;
	t_lil_imgs	img_item;
	t_lil_imgs	img_user;
	t_lil_imgs	img_background;
	t_lil_imgs	img_exit;
	t_lil_imgs	img_enemy;
}	t_data;

//so_long_init.c
void    img_init(t_data *data);


//so_long_win_param.c
int		escape(int keysym, t_data *data);
int		close_window(t_data *data);

//so_long_imgs.c
void	img_pix_put(t_imgs *img, int x, int y, int color);
int		render_rect(t_imgs *img, t_rect rect);
void	render_background(t_data *data, int color);
int		render(t_data *data);
void	free_data_imgs(void	*img);

//gnl
char	*get_next_line(int fd);

//so_long_utils.c
int	ft_strlen(const char *s);
int	ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int	ft_atoi(const char *nptr);

//so_long_parse.c
int map_verif(t_data *data);
char    *put_map_in_tab(t_data *data);
int height_size_map(char *file);
int width_size_map(char *file);
char value(char *file);

#endif