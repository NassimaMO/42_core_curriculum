#ifndef FDF_H
#define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WINDOW_WIDTH 2560
# define WINDOW_HEIGHT 1440
# define SIZE_IMG 64

# define RED_PIXEL 0xFF0000
# define ORANGE_PIXEL 0xFF8C00
# define YELLOW_PIXEL 0xFFFF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000

# define MLX_ERROR 1

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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map_file;
	t_imgs	img;
}	t_data;

//fdf.win.param.c
int		escape(int keysym, t_data *data);
int		close_window(t_data *data);

//fdf.imgs.c
void	img_pix_put(t_imgs *img, int x, int y, int color);
int		render_rect(t_imgs *img, t_rect rect);
void	render_background(t_imgs *img, int color);
int		render(t_data *data);
void	free_data_imgs(void	*img);

//gnl
char	*get_next_line(int fd);

//fdf_utils.c
int	ft_strlen(const char *s);
int	ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int	ft_atoi(const char *nptr);

//fdf_parse.c
int height_size_map();
int width_size_map();
int value();

#endif