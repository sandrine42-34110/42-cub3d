#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <unistd.h>
# include <math.h>

# define KEY_W_UP		119
# define KEY_S_DOWN		115
# define KEY_A_LEFT		97
# define KEY_D_RIGHT	100
# define KEY_ESCAPE		65307

# define W_WIN 1000
# define H_WIN 600

# define TITLE "cub3d"

# define RGB(R, G, B) ((R << 16) | (G << 8) | (B)) // Encode RGB to 0xRRGGBB
# define FCMM RGB(200, 200, 200)  // Floor Color MiniMap
# define WCMM RGB(50, 50, 50)     // Wall Color MiniMap

typedef struct s_text	t_text;
typedef struct s_map	t_map;
typedef struct s_mlx	t_mlx;

typedef struct s_all
{
	int			height_file;
	int			pos_line_read_file;
	t_map		*map;
	t_text		*text;
	t_mlx		*mlx;
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

/* ====	floodfill.c	==============================================*/

void	check_close_map(t_all *all);

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

/* ====	parsing.c	=========================================================*/

void	error_msg_and_close(char *msg, t_all *all);
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