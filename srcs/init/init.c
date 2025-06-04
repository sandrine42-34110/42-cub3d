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

t_text	*init_text(void)
{
	t_text *text;

	text = malloc(sizeof(t_text));
	if (!text)
		return (NULL);
	text->no = NULL;
	text->so = NULL;
	text->we = NULL;
	text->ea = NULL;
	text->floor_r = 0;
	text->floor_g = 0;
	text->floor_b = 0;
	text->ceiling_r = 0;
	text->ceiling_g = 0;
	text->ceiling_b = 0;
	text->floor = 0;
	text->ceiling = 0;
	return (text);
}

t_all	*init_all(int argc, char **argv)
{
	t_all	*all;

	if (argc != 2)
	{
		ft_putstr_fd("Error : Usage : ./philo [map_name].cub\n", 2);
		return (NULL);
	}
	if(!check_map_name(argv[1]))
		return (NULL);
	all = malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->text = init_text();
	all->map = init_map();
	if (!all->text)
	{
		free(all);
		return (NULL);
	}
	all->height_file = 0;
	all->pos_line_read_file = 0;
	return (all);
}

t_map	*init_map(void)
{
	t_map	*map;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->line = NULL;
	map->h_map = 0;
	map->w_map = 0;
	map->or_p = 0;
	return (map);
}
