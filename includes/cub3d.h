#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

#include <unistd.h>

typedef struct s_text	t_text;

typedef struct s_all
{
	int			height_file;
//	t_map		*map;
	t_text		*text;
}			t_all;


/* typedef struct s_map
{
	int		i; //bidon juste pour creer la structure
}			t_map; */

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

/* ====	init.c	=============================================================*/

int		check_map_name(char *str);
t_all	*init_all(int argc, char **argv);

/* ====	parsing.c	=========================================================*/

void	error_msg_and_close(char *msg);
void	parse_map(t_all *all, char *file);

/* ====	handle_textures.c	=================================================*/

void	ft_free_split(char **split, char *msg);
int		is_texture(t_all *all, char *line);
void	handle_textures(t_all *all, char *line);

/* ====	handle_colors.c	=====================================================*/

void	set_color(t_all *all, char type, const char *str);
int		is_color(char *line);
void	handle_colors(t_all *all, char *line);

#endif