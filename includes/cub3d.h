#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <unistd.h>
# include <math.h>
# include <stdio.h>
/* 
# define KEY_W_UP			119
# define KEY_S_DOWN			115
# define KEY_A_LEFT			97
# define KEY_D_RIGHT		100
# define KEY_ESCAPE			65307
# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_RIGHT	65363
 */

#ifdef __APPLE__
# define KEY_W_UP			13
# define KEY_S_DOWN			1
# define KEY_A_LEFT			0
# define KEY_D_RIGHT		2
# define KEY_ARROW_UP		126
# define KEY_ARROW_DOWN		125
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124
# define KEY_ESCAPE			53
#else
# define KEY_W_UP 119
# define KEY_S_DOWN 115
# define KEY_A_LEFT 97
# define KEY_D_RIGHT 100
# define KEY_ESCAPE			65307
# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_RIGHT	65363
#endif

# define W_WIN				1500
# define H_WIN				900

# define MOVE_SPEED			0.125f
# define ANGLE_ROT			0.1f
# define COLL_PAD			0.1f

# define FOV_RAD (90.0 * M_PI / 180.0)

# define TITLE "cub3d"

# define RGB(R, G, B) ((R << 16) | (G << 8) | (B)) // Encode RGB to 0xRRGGBB
# define FCMM RGB(200, 200, 200)  // Floor Color MiniMap
# define WCMM RGB(128, 0, 128)     // Wall Color MiniMap

typedef struct s_text		t_text;
typedef struct s_map		t_map;
typedef struct s_mlx		t_mlx;
typedef struct s_minimap	t_minimap;
typedef struct s_player		t_player;
typedef struct s_raycast	t_raycast;
typedef struct s_img		t_img;


typedef struct s_all
{
	int			height_file;
	int			pos_line_read_file;
	t_map		*map;
	t_text		*text;
	t_mlx		*mlx;
	t_minimap	*minimap;
	t_player	*player;
	t_raycast	*raycast;
	t_img		*screen;
}				t_all;

typedef struct s_map
{
	char	**line;
	int		h_map;
	int		w_map; // width of each line
	int		x_p;
	int		y_p;
	char	or_p;
}			t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;


typedef struct s_minimap
{
	int		offset_x;
	int		offset_y;
	int		map_width_px;
	int		map_height_px;
}			t_minimap;

typedef struct s_player
{
	double	dx;
	double	dy;
	double	d_or;
	double	x;
	double	y;
	double	or;
}			t_player;

typedef struct s_text
{
	int		i;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
}			t_text;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w_win;
	int		h_win;
	int		tile_size;
	int		player_x;
	int		player_y;
	t_img	img_w_n;
	t_img	img_w_s;
	t_img	img_w_e;
	t_img	img_w_w;
	void	*clr_f;
	void	*clr_c;
	int		x0;		//draw_line
	int		y0;
	int		x1;
	int		y1;
	int		color;

}				t_mlx;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}			t_bresenham;

typedef struct s_raycast
{
	int		pos_px_x;
	double	px;
	double	py;
	double	ray_dir_x;
	double	ray_dir_y;
	double	ray_x;
	double	ray_y;
	double	start_x;
	double	start_y;
	double	end_x;
	double	end_y;
	double	perp;
	int		wall_tex;
	int		side;
}				t_raycast;

typedef struct s_wall
{
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	t_img	*tex;
	double	wall_x;
	int		color;
}			t_wall;

typedef enum e_texture
{
	TEX_NO,
	TEX_SO,
	TEX_WE,
	TEX_EA
}	t_tex_dir;

/* ====	check_text_and_map.c	==============================================*/

void	check_text_and_map(t_all *all);

/* ====	floodfill.c	==========================================================*/

void	check_close_map(t_all *all);

/* ====	utils_display.c	======================================================*/

void	put_pixel(t_img *img, int x, int y, int color);
void	draw_square(t_all *all, int x, int y, int size, int color);
void	draw_circle(t_all *all, int cx, int cy, int radius, int color);

/* ====	dda.c	=====================================================*/

void		dda_init(t_all *all, int *mx, int *my, double d[8]);
void		dda_loop(t_all *all, int mx, int my, double d[8]);
void		attribute_texture(t_all *all, double d[8]);
void		dda_cast(t_all *all);

/* ====	display_3d.c	==============================================*/

void	minimap_colors(t_all *all, int x, int y, int *color);
void	draw_ceiling(t_all *all);
void	draw_floor(t_all *all);
void	draw_walls(t_all *all);

/* ====	display_map.c	==============================================*/

void	display_map(t_all *all);
void	display_player(t_all *all);
void	display_screen(t_all *all);

/* ====	draw_line.c	======================================================*/

void	init_draw_vars(t_mlx *mlx, t_bresenham *b);
void	draw_line_step(t_mlx *mlx, t_bresenham *b);
void		draw_line(t_all *all, t_mlx *mlx);

/* ====	handle_win.c	======================================================*/

int		close_window(t_all *all);
int		key_hook(int keycode, t_all *all);

/* ====	raycating.c	==========================================================*/

void	draw_vision_line(t_all *all);
void	draw_vision_cone(t_all *all);

/* ====	free.c	==============================================================*/

void	free_map(t_map *map);
void	free_mlx(t_mlx *mlx);
void	free_text_and_map(t_all *all);
void	free_display(t_all *all);
void	free_all(t_all *all);

/* ====	free1.c	==============================================================*/

void	free_text(t_text *text);
void	free_map_copy(char **map_copy, int height);

/* ====	init.c	=============================================================*/

int		check_map_name(char *str);
t_text	*init_text(void);
t_all	*init_all(int argc, char **argv);
t_map	*init_map(void);
t_mlx	*init_mlx(t_all *all);

/* ====	init_display.c	=============================================================*/

t_minimap	*init_minimap(t_all *all);
t_player	*init_player(t_all *all);
t_img		*init_screen(t_all *all);

/* ====	utils_init.c	=============================================================*/

int		check_map_name(char *str);
int		tile_size(t_all *all);
double	begin_dir_pl(char dir);
void	load_images(t_all *all);

/* ====	move.c	=============================================================*/

int		translation(int keycode, double angle, double *dx, double *dy);
void	move_player(t_all *all, int keycode);

/* ====	parsing.c	=========================================================*/

void	error_msg_and_close(char *msg, t_all *all);
void	error_and_close_all(char *msg, t_all *all);
void	parse_map(t_all *all, char *file);

/* ====	handle_map.c	=================================================*/

int		ft_isdigit_and_spaces (char *c);
void	handle_map(t_all *all, char *line, int fd);

/* ====	handle_textures.c	=================================================*/

void	ft_free_split(char **split, char *msg, t_all *all);
int		is_texture(char *line);
void	handle_textures(t_all *all, char *line, int fd);

/* ====	handle_colors.c	=====================================================*/

void	set_color(t_all *all, char type, const char *str);
int		is_color(char *line);
void	handle_colors(t_all *all, char *line, int fd);

/* ====	utils.c	=============================================================*/

void	go_to_end_fd(int fd, char *line);

#endif