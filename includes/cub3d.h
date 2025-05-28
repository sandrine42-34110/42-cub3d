#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

#include <unistd.h>

typedef struct s_all
{
	int	i;
	//t_map	map;
}			t_all;


/* typedef struct s_map
{
	int		i; //bidon juste pour creer la structure
}			t_map; */

/* ====	init.c	=============================================================*/

int		check_map_name(char *str);
t_all	*init_all(int argc, char **argv);

/* ====	nom fichier	=========================================================*/



#endif