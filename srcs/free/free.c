#include "cub3d.h"

void	free_text(t_text *text)
{
	if (!text)
		return ;
	if (text->no)
		free(text->no);
	if (text->so)
		free(text->so);
	if (text->we)
		free(text->we);
	if (text->ea)
		free(text->ea);
	free(text);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->line)
	{
		i = 0;
		while (map->line[i])
		{
			free(map->line[i]);
			i++;
		}
		free(map->line);
	}
	free(map);
}

void	free_all(t_all *all)
{
	if (all)
	{
		free_text(all->text);
		free_map(all->map);
		free(all);
	}
}
