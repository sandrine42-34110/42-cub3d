#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

#include <unistd.h>

typedef struct s_all
{
	int			height_file;
	t_map		*map;
	t_text		*text;
}			t_all;


/* typedef struct s_map
{
	int		i; //bidon juste pour creer la structure
}			t_map; */

/* typedef struct s_text
{
	int		i; //bidon juste pour creer la structure
}			t_text; */

/* ====	init.c	=============================================================*/

int		check_map_name(char *str);
t_all	*init_all(int argc, char **argv);

/* ====	parsing.c	=========================================================*/

int	parse_map(all, argv[1]);

/* ====	nom fichier	=========================================================*/



#endif