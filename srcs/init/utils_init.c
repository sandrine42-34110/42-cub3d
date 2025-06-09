#include "cub3d.h"

int	check_map_name(char *str)
{
	int	len_name_file;

	len_name_file = ft_strlen(str);
	if (ft_strcmp(".cub",str + len_name_file - 4) == 0)
		return(1);
	ft_putstr_fd("Error : Name map isn't in .cub\n", 2);
	return (0);
}

int	tile_size(t_all *all)
{
	int	size_w;
	int	size_h;

	size_w = W_WIN / (3 * all->map->w_map);
	size_h = H_WIN / (3 * all->map->h_map);
	return (fmin(size_w, size_h));
}

double	begin_dir_pl(char dir)
{
	double	angle;

	angle = 0;
	if (dir == 'E')
		angle = 0;
	else if (dir == 'N')
		angle = M_PI / 2;
	else if (dir == 'W')
		angle = M_PI;
	else if (dir == 'S')
		angle = 3 * M_PI / 2;
	return (angle);
}