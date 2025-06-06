#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <unistd.h>
# include <math.h>

# define KEY_W_UP			119
# define KEY_S_DOWN			115
# define KEY_A_LEFT			97
# define KEY_D_RIGHT		100
# define KEY_ESCAPE			65307
# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_RIGHT	65363

# define W_WIN				1000
# define H_WIN				600

# define MOVE_SPEED			0.125
# define ANGLE_ROT			0.1

# define TITLE "cub3d"

# define RGB(R, G, B) ((R << 16) | (G << 8) | (B)) // Encode RGB to 0xRRGGBB
# define FCMM RGB(200, 200, 200)  // Floor Color MiniMap
# define WCMM RGB(50, 50, 50)     // Wall Color MiniMap

typedef struct s_text		t_text;
typedef struct s_map		t_map;
typedef struct s_mlx		t_mlx;
typedef struct s_minimap	t_minimap;
typedef struct s_player		t_player;

typedef struct s_all
{
	int			height_file;
	int			pos_line_read_file;
	t_map		*map;
	t_text		*text;
	t_mlx		*mlx;
	t_minimap	*minimap;
	t_player	*player;
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
	int		x;
	int		y;
	int		or;
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
	void	*img_w_n;
	void	*img_w_s;
	void	*img_w_e;
	void	*img_w_w;
	void	*clr_f;
	void	*clr_c;
}				t_mlx;

/* ====	check_text_and_map.c	==============================================*/

void	check_text_and_map(t_all *all);

/* ====	floodfill.c	==========================================================*/

void	check_close_map(t_all *all);

/* ====	handle_win.c	======================================================*/

int		close_window(t_all *all);
int		key_hook(int keycode, t_all *all);

/* ====	utils_display.c	======================================================*/

void	draw_square(t_all *all, int x, int y, int size, int color);
void	draw_circle(t_mlx *mlx, int cx, int cy, int radius, int color);

/* ====	free.c	==============================================================*/

void	free_text_and_map(t_all *all);
void	free_all(t_all *all);

/* ====	display_map.c	==============================================*/

void	display_minimap(t_all *all);

/* ====	init.c	=============================================================*/

int		check_map_name(char *str);
t_text	*init_text(void);
t_all	*init_all(int argc, char **argv);
t_map	*init_map(void);
t_mlx	*init_mlx(t_all *all);

/* ====	init_display.c	=============================================================*/

t_minimap	*init_minimap(t_all *all);
t_player	*init_player(t_all *all);

/* ====	utils_init.c	=============================================================*/

int	check_map_name(char *str);
int	tile_size(t_all *all);
int	begin_dir_pl(char dir);

/* ====	move.c	=============================================================*/

int		translation(int keycode, double *dx, double *dy);
void	move_player(t_all *all, int keycode);

/* ====	parsing.c	=========================================================*/

void	error_msg_and_close(char *msg, t_all *all);
void	error_and_close_all(char *msg, t_all *all);
void	parse_map(t_all *all, char *file);

/* ====	handle_map.c	=================================================*/

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