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

int	begin_dir_pl(char dir)
{
	int	angle;

	if (dir == 'E')
		angle = 0;
	else if (dir == 'N')
		angle = pi() / 2;
	else if (dir == 'W')
		angle = pi();
	else if (dir == 'S')
		angle = 3 * pi() / 2;
	return (angle);
}