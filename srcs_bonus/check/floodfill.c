#include "cub3d.h"

char	**duplicate_map(t_map *map, t_all *all)
{
	int		y;
	char	**copy;

	copy = (char **)malloc(sizeof(char *) * (map->h_map + 1));
	if (!copy)
		error_msg_and_close("Malloc failed for map_copy!", all);
	y = 0;
	while (y < map->h_map)
	{
		copy[y] = ft_strdup(map->line[y]);
		if (!copy[y])
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			error_msg_and_close("Error : Malloc failed for map_cpy line!", all);
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, t_all *all)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0')
		error_msg_and_close("Error : Map isn't valid!\n", all);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] != '0' && map[y][x] != 'N' && map[y][x] != 'S' &&
		map[y][x] != 'E' && map[y][x] != 'W')
		error_msg_and_close("Error : Map isn't valid!\n", all);
	flood_fill(map, x + 1, y, all);
	map[y][x] = 'F';
	flood_fill(map, x - 1, y, all);
	flood_fill(map, x, y + 1, all);
	flood_fill(map, x, y - 1, all);
}

int	find_start(t_map *map, int *start_x, int *start_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->h_map)
	{
		x = 0;
		while (x < map->w_map)
		{
			if (map->line[y][x] == 'N' || map->line[y][x] == 'S'
				|| map->line[y][x] == 'E' || map->line[y][x] == 'W')
			{
				map->or_p = map->line[y][x];
				*start_x = x;
				*start_y = y;
				map->x_p = x;
				map->y_p = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ctrl_only_one_player(t_map *map, int start_x, int start_y, t_all *all)
{
	int	x;
	int	y;

	y = start_y;
	x = start_x + 1;
	while (y < map->h_map)
	{
		while (x < map->w_map)
		{
			if (map->line[y][x] == 'N' || map->line[y][x] == 'S'
				|| map->line[y][x] == 'E' || map->line[y][x] == 'W')
				error_msg_and_close("Error : More than one player\n", all);
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_close_map(t_all *all)
{
	int		x;
	int		y;
	char	**map_copy;

	x = 0;
	y = 0;
	if (!find_start(all->map, &x, &y))
		error_msg_and_close("Error : No player!\n", all);
	ctrl_only_one_player(all->map, x, y, all);
	map_copy = duplicate_map(all->map, all);
	flood_fill(map_copy, x, y, all);
	free_map_copy(map_copy, all->map->h_map);
}
